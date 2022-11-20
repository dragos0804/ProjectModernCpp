#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "Film.h"

class MovieFiltering
{
public:
	void SortBy(const uint8_t & option);
private:
	std::vector<std::shared_ptr<Film>> m_listOfAllMovies;
	bool ComparatorLengthName( Film& film1,  Film& film2);
	bool ComparatorDuration( Film& film1,  Film& film2);
	bool ComparatorRating( Film& film1,  Film& film2);
	bool ComparatorReleaseDate( Film& film1,  Film& film2);
};

