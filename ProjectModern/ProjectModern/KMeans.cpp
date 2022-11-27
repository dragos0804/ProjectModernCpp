#include "KMeans.h"

std::vector<Film> KMeans::GetSimilarFilms(const Film& film)
{
	uint8_t closetClusterIndex = ComputeClosetClusterIndex(film);
	return m_clusteredFilms[closetClusterIndex];
}
