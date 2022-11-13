#include "Film.h"
#include <algorithm>

Film::Film(unsigned int id, unsigned int numberOfReviews, unsigned int duration, float rating, std::string name
	, std::string releaseDate, std::list<Genre> genres, std::list<Actor> actors, std::list<Producer> producers)
	: m_id(id) 
	, m_numberOfReviews(numberOfReviews)
	, m_duration(duration)
	, m_rating(rating)
	, m_name(name)
	, m_releaseDate(releaseDate)
	, m_genres(genres)
	, m_actors(actors)
	, m_producers(producers)
{
}

// ---- GETTERS ----
unsigned int Film::GetId() const
{
	return m_id;
}

unsigned int Film::GetDuration() const
{
	return m_duration;
}

unsigned int Film::GetNumberOfReviews() const
{
	return m_numberOfReviews;
}

float Film::GetRating() const
{
	return m_rating;
}

std::string Film::GetName() const
{
	return m_name;
}

std::string Film::GetReleaseDate() const
{
	return m_releaseDate;
}

std::list<Film::Genre> Film::GetGenres() const
{
	return m_genres;
}

std::list<Film::Actor> Film::GetActors() const
{
	return m_actors;
}

std::list<Film::Producer> Film::GetProducers() const
{
	return m_producers;
}

void Film::SetNumberOfReviews(const unsigned int numberOfReviews)
{
	m_numberOfReviews = numberOfReviews;
}

void Film::SetRating(unsigned int rating)
{
	m_rating = rating;
}

void Film::SetName(const std::string name)
{
	m_name = name;
}

void Film::SetGenres(const std::list<Genre> genres)
{
	m_genres = genres;
}

void Film::SetActors(const std::list<Actor> actors)
{
	m_actors = actors;
}

void Film::SetProducers(const std::list<Producer> producers)
{
	m_producers = producers;
}
