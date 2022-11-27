#pragma once
#include "Cluster.h"
#include "Film.h"

class KMeans
{
public:
	std::vector<Film> GetSimilarFilms(const Film& film);

private:
	float ComputeEuclidianDistance(Position firstPoint, Position secondPoint);
	Position GetNormFilm(const Film& film);
	uint8_t ComputeClosetClusterIndex(const Film& film);

private:
	
	std::vector<Cluster> m_clusters;
	std::vector<std::vector<Film>> m_clusteredFilms;
};

