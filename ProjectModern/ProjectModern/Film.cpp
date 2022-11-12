#include "Film.h"
#include <algorithm>

// ---- GETTERS ----
const unsigned int Film::getLength() const
{
	return m_duration;
}


// ---- SORT ----
bool comparatorFilm(Film film1, Film film2) {
	return film1.getLength() < film2.getLength();
}


void Film::sortBy(std::vector<Film> films)
{
	std::sort(films.begin(), films.end(), comparatorFilm);
}

// mai multe sort-uri? ( sortByLength, sortByGenre, sortByActors )
// urmat de mai multi comparatori?