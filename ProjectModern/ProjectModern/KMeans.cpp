#include "KMeans.h"

std::vector<Film> KMeans::GetSimilarFilms(const Film& film)
{
	uint8_t closetClusterIndex = ComputeClosetClusterIndex(film);
	return m_clusteredFilms[closetClusterIndex];
}

void KMeans::Run(std::vector<Film> films)
{
	for (uint8_t step = 0; step <= 50; step++)
	{
		for (const auto& film : films)
		{
			uint8_t closestClusterIndex = ComputeClosetClusterIndex(film);
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
	return Position();
}

uint8_t KMeans::ComputeClosetClusterIndex(const Film& film)
{
	Position position = GetNormFilm(film);
	uint8_t closetClusterIndex = 0;
	float minDistance = std::numeric_limits<float>::max();
	for (uint8_t pos = 0; pos < m_clusters.size(); ++pos)
	{
		float distance = ComputeEuclideanDistance(m_clusters[pos].GetPosition(), position);
		if (distance < minDistance)
		{
			closetClusterIndex = pos;
			minDistance = distance;
		}
	}
	return closetClusterIndex;
}
