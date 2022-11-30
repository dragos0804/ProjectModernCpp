#include "KMeans.h"

std::vector<Film> KMeans::GetSimilarFilms(const Film& film)
{
	uint8_t closetClusterIndex = ComputeClosetClusterIndex(film);
	return m_clusteredFilms[closetClusterIndex];
}

float KMeans::ComputeEuclidianDistance(Position firstPoint, Position secondPoint)
{
	return 0.0f;
}

Position KMeans::GetNormFilm(const Film& film)
{
	return Position();
}

uint8_t KMeans::ComputeClosetClusterIndex(const Film& film)
{
	return 0;
}
