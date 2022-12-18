#include "User.h"

User::User(int id, std::string name, std::string username, std::string dateOfBirth, std::string email, std::string password, std::string country)
	: m_id(id)
	, m_name(name)
	, m_username(username)
	, m_dateOfBirth(dateOfBirth)
	, m_email(email)
	, m_password(password)
	, m_country(country)
{
	m_favouriteMovies = {};
	m_watchedMovies = {};
}

unsigned int User::GetID() const
{
	return m_id;
}

std::string User::GetName() const
{
	return m_name;
}

std::string User::GetUsername() const
{
	return m_username;
}

std::string User::GetDateOfBirth() const
{
	return m_dateOfBirth;
}

std::string User::GetEmail() const
{
	return m_email;
}

std::string User::GetPassword() const
{
	return m_password;
}

std::string User::GetCountry() const
{
	return m_country;
}

void User::SetID(const unsigned int& id)
{
	m_id = id;
}

void User::SetName(const std::string& name)
{
	m_name = name;
}

void User::SetUsername(const std::string& username)
{
	m_username = username;
}

void User::SetDateOfBirth(const std::string& dateOfBirth)
{
	m_dateOfBirth = dateOfBirth;
}

void User::SetEmail(const std::string& email)
{
	m_email = email;
}

void User::SetPassword(const std::string& password)
{
	m_password = password;
}

void User::SetCountry(const std::string& country)
{
	m_country = country;
}

//void User::leaveReview(Film& film, const int& grade)
//{
//	double sumOfGrades=0.0;
//	sumOfGrades += grade;
//	double averageRating = sumOfGrades / film.GetNumberOfReviews();
//	film.SetNumberOfReviews(film.GetNumberOfReviews() + 1);
//	film.SetRating(averageRating);
//}

void User::AddMovieToWatched(IMoviePtr movie)
{
	//m_watchedMovies.emplace_back(movie);
}

void User::AddMovieToFavourites(IMoviePtr movie)
{
	//m_favouriteMovies.emplace_back(movie);
}
