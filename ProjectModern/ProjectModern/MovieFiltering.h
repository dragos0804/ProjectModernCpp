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
	bool ComparatorLengthName(const Film& film1, const Film& film2);
	bool ComparatorDuration(const Film& film1, const Film& film2);
	bool ComparatorRating(const Film& film1, const Film& film2);
	bool ComparatorReleaseDate(const Film& film1, const Film& film2);
};

