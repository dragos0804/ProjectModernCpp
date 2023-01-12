#include "KMeans.h"
#define NUM_OF_GENRES 42


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
	// excludem din calculul recomandarii acele categorii care sunt prea indepartate / aducem spanish/british/korean tv shows la valori medii (media dintre toate celelalte categorii) 
	{"TV Shows", 0.1f},
	{"Teen TV Shows", 1.0f},
	{"TV Sci-Fi & Fantasy", 2.0f},
	{"Spanish-Language TV Shows", 19.0f}, //mediana
	{"TV Horror", 3.0f},
	{"TV Comedies", 15.0f},
	{"Kids' TV", 0.8f},
	{"Reality TV", 11.0f},
	{"Classic & Cult TV", 7.0f}, //mediana
	{"TV Dramas", 10.0f},
	{"TV Thrillers", 4.0f},
	{"TV Action & Adventure", 4.5f},
	{"International TV Shows", 0.15f}, //mediana
	{"Crime TV Shows", 4.7f},
	{"Romantic TV Shows", 12.0f},
	{"Science & Nature TV", 7.5f},
	{"British TV Shows", 18.0f}, //mediana
	{"TV Mysteries", 5.0f},
	{"Korean TV Shows", 20.0f}, //mediana
	{"Docuseries", 6.5f},
	//---MOVIES---
	{"Movies", 0.2f},
	{"Dramas", 10.1f},
	{"Sports Movies", 4.5f},
	{"Independent Movies", 0.0f}, //mediana
	{"Children & Family Movies", 13.0f},
	{"Music & Musicals", 14.0f},
	{"Sci-Fi & Fantasy", 2.0f},
	{"Stand-Up Comedy", 15.0f},
	{"Horror Movies", 3.0f},
	{"Comedies", 15.0f},
	{"Anime Series", 0.0f},
	{"Faith & Spirituality", 0.0f},
	{"Stand-Up Comedy & Talk Shows", 15.0f},
	{"International Movies", 0.16f},
	{"Anime Features", 0.9f},
	{"Romantic Movies", 12.0f},
	{"LGBTQ Movies", 8.0f},
	{"Documentaries", 6.5f},
	{"Cult Movies", 0.0f}, //mediana
	{"Classic Movies", 0.0f}, //mediana
	{"Thrillers", 4.0f},
	{"Action & Adventure", 4.5f}
};

KMeans::KMeans(uint8_t numberOfClusters)
{
	srand(std::time(0));
	m_clusters.reserve(numberOfClusters);
	for (uint8_t id = 0; id < numberOfClusters; ++id)
	{
		m_clusters.emplace_back(Cluster(id, { static_cast<float>(rand()) / RAND_MAX,
											  rand() % NUM_OF_GENRES,
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
