#include "Film.h"
#include <algorithm>



Film::Film(unsigned int id, 
	unsigned int numberOfReviews, 
	std::string duration, 
	float rating, 
	std::string type, 
	std::string title, 
	std::string ageRange, 
	std::string description, 
	uint16_t releaseYear, 
	std::string genres, 
	std::string cast, 
	std::string director, 
	std::string country)
	: m_id(id)
	, m_numberOfReviews(numberOfReviews)
	, m_duration(duration)
	, m_rating(rating)
	, m_type(type)
	, m_title(title)
	, m_ageRange(ageRange)
	, m_description(description)
	, m_releaseYear(releaseYear)
	, m_genres(genres)
	, m_cast(cast)
	, m_director(director)
	, m_country(country)
{
}


// ---- GETTERS ----
unsigned int Film::GetId() const
{
	return m_id;
}

std::string Film::GetType() const
{
	return m_type;
}

std::string Film::GetDuration() const
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

std::string Film::GetTitle() const
{
	return m_title;
}

uint16_t Film::GetReleaseYear() const
{
	return m_releaseYear;
}

std::string Film::GetGenres() const
{
	return m_genres;
}

std::string Film::GetCast() const
{
	return m_cast;
}

std::string Film::GetDirector() const
{
	return m_director;
}

std::string Film::GetDescription() const
{
	return m_description;
}

std::string Film::GetCountry() const
{
	return m_country;
}

std::string Film::GetAgeRange() const
{
	return m_ageRange;
}

void Film::SetId(const unsigned int& id)
{
	m_id = id;
}

void Film::SetType(const std::string& type)
{
	m_type = type;
}

void Film::SetDuration(const std::string& duration)
{
	m_duration = duration;
}

void Film::SetNumberOfReviews(const unsigned int& numberOfReviews)
{
	m_numberOfReviews = numberOfReviews;
}

void Film::SetRating(const float& rating)
{
	m_rating = rating;
}

void Film::SetTitle(const std::string& title)
{
	m_title = title;
}

void Film::SetReleaseYear(const uint16_t& releaseYear)
{
	m_releaseYear = releaseYear;
}

void Film::SetGenres(const std::string& genres)
{
	m_genres = genres;
}

void Film::SetCast(const std::string& cast)
{
	m_cast = cast;
}

void Film::SetDirector(const std::string& director)
{
	m_director = director;
}

void Film::SetDescription(const std::string& description)
{
	m_description = description;
}

void Film::SetCountry(const std::string& country)
{
	m_country = country;
}

void Film::SetAgeRange(const std::string& ageRange)
{
	m_ageRange = ageRange;
}
