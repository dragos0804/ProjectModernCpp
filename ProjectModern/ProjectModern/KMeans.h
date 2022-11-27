#pragma once
#include "Cluster.h"
#include "Film.h"

class KMeans
{

private:
	std::vector<Cluster> m_clusters;
	std::vector<std::vector<Film>> m_clusteredFilms;
};

