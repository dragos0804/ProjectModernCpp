#include "KMeans.h"

const std::unordered_map<std::string, float> CategoriesMappingValues =
{
	{"TV Shows", 0.0f},
	{"Teen TV Shows", 0.0f},
	{"TV Sci-Fi & Fantasy", 0.0f},
	{"Spanish-Language TV Shows", 0.0f},
	{"TV Horror", 0.0f},
	{"TV Comedies", 0.0f},
	{"Docuseries", 0.0f},
	{"TV Action & Adventure", 0.0f},
	{"Crime TV Shows", 0.0f},
	{"Dramas", 0.0f},
	{"TV Mysteries", 0.0f},
	{"Romantic TV Shows", 0.0f},
	{"Movies", 0.0f},
	{"Sports Movies", 0.0f},
	{"Independent Movies", 0.0f},
	{"Children & Family Movies", 0.0f},
	{"Korean TV Shows", 0.0f},
	{"Music & Musicals", 0.0f},
	{"Sci-Fi & Fantasy", 0.0f},
	{"British TV Shows", 0.0f},
	{"Stand-Up Comedy", 0.0f},
	{"Horror Movies", 0.0f},
	{"Science & Nature TV", 0.0f},
	{"Comedies", 0.0f},
	{"Anime Series", 0.0f},
	{"Kids' TV", 0.0f},
	{"Faith & Spirituality", 0.0f},
	{"Stand-Up Comedy & Talk Shows", 0.0f},
	{"TV Thrillers", 0.0f},
	{"International Movies", 0.0f},
	{"Reality TV", 0.0f},
	{"International TV Shows", 0.0f},
	{"Anime Features", 0.0f},
	{"Romantic Movies", 0.0f},
	{"LGBTQ Movies", 0.0f},
	{"Documentaries", 0.0f},
	{"Cult Movies", 0.0f},
	{"TV Dramas", 0.0f},
	{"Classic Movies", 0.0f},
	{"Thrillers", 0.0f},
	{"Classic & Cult TV", 0.0f},
	{"Action & Adventure", 0.0f}
};

std::vector<Film> KMeans::GetSimilarFilms(const Film& film)
{
	uint8_t closestClusterIndex = ComputeClosestClusterIndex(film);
	return m_clusteredFilms[closestClusterIndex];
}

void KMeans::Run(std::vector<Film> films)
{
	for (uint8_t step = 0; step <= 50; step++)
	{
		for (const auto& film : films)
		{
			uint8_t closestClusterIndex = ComputeClosestClusterIndex(film);
			Position position = GetNormFilm(film);
			m_clusteredFilms[closestClusterIndex].push_back(film);
		}

		for (auto& cluster : m_clusters)
		{
			cluster.UpdateClusterPosition();
			cluster.RemovePoints();
		}
	}
}

Position KMeans::GetNormFilm(const Film& film)
{
	Position position;
	/*return { film.rating,
			CategoriesMappingValues.at(film.genres),
			film.releaseYear,
			film.duration,
			film.ageRange };*/
	return position;
}

uint8_t KMeans::ComputeClosestClusterIndex(const Film& film)
{
	Position position = GetNormFilm(film);
	uint8_t closestClusterIndex = 0;
	float minDistance = std::numeric_limits<float>::max();
	for (uint8_t pos = 0; pos < m_clusters.size(); ++pos)
	{
		float distance = ComputeEuclideanDistance(m_clusters[pos].GetPosition(), position);
		if (distance < minDistance)
		{
			closestClusterIndex = pos;
			minDistance = distance;
		}
	}
	return closestClusterIndex;
}
