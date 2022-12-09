#include "KMeans.h"
#define power2(a) ((a) * (a))

std::vector<Film> KMeans::GetSimilarFilms(const Film& film)
{
	uint8_t closetClusterIndex = ComputeClosetClusterIndex(film);
	return m_clusteredFilms[closetClusterIndex];
}

float KMeans::ComputeEuclidianDistance(Position firstPoint, Position secondPoint)
{
	float total = 0;
	uint8_t numberOfCoordinates = std::tuple_size<decltype(firstPoint)>::value;
	
	total += (float)(std::get<0>(secondPoint) - std::get<0>(firstPoint));
	total += (float)(std::get<1>(secondPoint) - std::get<1>(firstPoint));
	total += (float)(std::get<2>(secondPoint) - std::get<2>(firstPoint));
	total += (float)(std::get<3>(secondPoint) - std::get<3>(firstPoint));
	total += (float)(std::get<4>(secondPoint) - std::get<4>(firstPoint));

	return sqrt(total);

}

Position KMeans::GetNormFilm(const Film& film)
{
	return Position();
}

uint8_t KMeans::ComputeClosetClusterIndex(const Film& film)
{
	return 0;
}
