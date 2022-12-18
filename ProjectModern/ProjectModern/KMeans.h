#pragma once
#include "Cluster.h"
#include "Film.h"
#define power2(a) ((a) * (a))

class KMeans
{
public:
	std::vector<Film> GetSimilarFilms(const Film& film);
	void Run(std::vector<Film> films);

private:
	template <size_t I = 0, typename... Ts>
	float ComputeEuclidianDistance(std::tuple<Ts...> firstPoint, std::tuple<Ts...> secondPoint)
	{
		float total = 0;
		for (; I != sizeof...(Ts); I++)
		{
			total += power2(std::get<I>(secondPoint) - std::get<I>(firstPoint));
		}
		return sqrt(total);
	}
	Position GetNormFilm(const Film& film);
	uint8_t ComputeClosetClusterIndex(const Film& film);

private:
	
	std::vector<Cluster> m_clusters;
	std::vector<std::vector<Film>> m_clusteredFilms;
};


