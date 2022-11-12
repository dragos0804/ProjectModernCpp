#include "MovieFiltering.h"

void MovieFiltering::SortBy(const unsigned int& option)
{
	switch(option)
	{
		case 0:
			std::sort(m_listOfAllMovies.begin(), m_listOfAllMovies.end(), ComparatorLengthName); //furure iterations will make query select for these operations; for now, this is a dummy implementation to test the requirements
		case 1:
			std::sort(m_listOfAllMovies.begin(), m_listOfAllMovies.end(), ComparatorDuration);
	}
}

bool MovieFiltering::ComparatorLengthName(const Film& film1, const Film& film2)
{
	return film1.GetName() < film2.GetName();
}

bool MovieFiltering::ComparatorDuration(const Film& film1, const Film& film2)
{
	return film1.GetDuration() < film2.GetDuration();
}