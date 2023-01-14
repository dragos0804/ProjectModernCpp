#include "KMeans.h"

const std::unordered_map<std::string, float> AgeRangeMappingValues =
{
	{"TV-Y", 1.0f},
	{"TV-G", 2.0f},
	{"TV-Y7", 3.0f},
	{"TV-Y7-FV", 4.0f},
	{"TV-PG", 5.0f},
	{"TV-14", 7.0f},
	{"TV-MA", 9.0f},
	{"G", 2.0f},
	{"PG", 5.0f},
	{"NR", 5.0f},
	{"NC-17", 8.0f},
	{"PG-13", 6.0f},
	{"R", 9.0f},
	{"UR", 5.0f}
};

const std::unordered_map<std::string, float> CategoriesMappingValues =
{
	//---TV_SHOWS---
	{"", 0.1f},
	{"TV Shows", 0.1f},
	{"Kids' TV", 1.0f},
	{"Teen TV Shows", 2.0f},
	{"TV Sci-Fi & Fantasy", 3.0f},
	{"Classic & Cult TV", 4.0f}, //mediana
	{"Crime TV Shows", 5.0f},
	{"TV Mysteries", 6.0f},
	{"Documentaries", 6.5f},
	{"Science & Nature TV", 7.0f},
	{"TV Action & Adventure", 8.0f},
	{"TV Thrillers", 9.0f},
	{"TV Horror", 10.0f},
	{"International TV Shows", 6.3f}, //mediana
	{"British TV Shows", 6.3f}, //mediana
	{"TV Dramas", 11.0f},
	{"Reality TV", 12.0f},
	{"Spanish-Language TV Shows", 19.0f}, //mediana
	{"Korean TV Shows", 20.0f}, //mediana
	{"Romantic TV Shows", 13.0f},
	{"TV Comedies", 15.0f},
	//---MOVIES---
	{"Movies", 0.1f},
	{"Dramas", 11.0f},
	{"Sports Movies", 6.5f},
	{"Independent Movies", 4.0f}, //mediana
	{"Children & Family Movies", 14.0f},
	{"Music & Musicals", 14.0f},
	{"Sci-Fi & Fantasy", 3.0f},
	{"Stand-Up Comedy", 15.0f},
	{"Horror Movies", 10.0f},
	{"Comedies", 15.0f},
	{"Anime Series", 2.5f},
	{"Faith & Spirituality", 4.0f},
	{"Stand-Up Comedy & Talk Shows", 15.0f},
	{"International Movies", 6.3f},
	{"Anime Features", 2.5f},
	{"Romantic Movies", 13.0f},
	{"LGBTQ Movies", 6.0f},
	{"Docuseries", 6.5f},
	{"Cult Movies", 4.0f}, //mediana
	{"Classic Movies", 4.0f}, //mediana
	{"Thrillers", 9.0f},
	{"Action & Adventure", 8.0f}
};

KMeans::KMeans(uint8_t numberOfClusters)
{
	srand(std::time(0));
	m_clusters.reserve(numberOfClusters);
	for (uint8_t id = 0; id < numberOfClusters; ++id)
	{
		m_clusters.emplace_back(Cluster(id, { static_cast<float>(rand()) / RAND_MAX,
											  rand() % numberOfClusters,
											  static_cast<uint16_t>(rand()) / RAND_MAX,
											  static_cast<uint16_t>(rand()) / RAND_MAX,
											  rand() % 10}));
		m_clusteredFilms.push_back({});
	}
}

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

	float middleCategory = 0.0f;
	uint8_t numberOfCategories = 0;

	std::vector filmCategories = AppStorage::split(film.GetGenres(), ", ");
	for (const auto& filmCategory : filmCategories)
	{
		numberOfCategories++;
		middleCategory += CategoriesMappingValues.at(filmCategory);
	}

	std::string duration;
	for (uint8_t index = 0; index < film.GetDuration().size(); ++index)
		if (film.GetDuration()[index] >= '0' && film.GetDuration()[index] <= '9')
			duration += film.GetDuration()[index];
		else break;

	uint16_t durationNumeric = atoi(duration.c_str());

	return { film.GetRating(),
			middleCategory / numberOfCategories,
			film.GetReleaseYear(),
			durationNumeric,
			AgeRangeMappingValues.at(film.GetAgeRange())};
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
