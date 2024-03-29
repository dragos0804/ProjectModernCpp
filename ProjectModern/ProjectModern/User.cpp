#include "User.h"

User::User(int id, std::string name, std::string username, std::string dateOfBirth, std::string email, std::string password, std::string country, std::string idsWatched, std::string idsFavourites)
	: m_id(id)
	, m_name(name)
	, m_username(username)
	, m_dateOfBirth(dateOfBirth)
	, m_email(email)
	, m_password(password)
	, m_country(country)
	, m_idsWatched(idsWatched)
	, m_idsFavourites(idsFavourites)
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

std::string User::GetWatchedMovies() const
{
	return m_idsWatched;
}

std::string User::GetFavouriteMovies() const
{
	return m_idsFavourites;
}

std::vector<std::shared_ptr<const Film>> User::GetWatchedMoviesVect() const
{
	return m_watchedMovies;
}

std::vector<std::shared_ptr<const Film>> User::GetFavouriteMoviesVect() const
{
	return m_favouriteMovies;
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

void User::SetWatched(const std::string& watched)
{
	m_idsWatched = watched;
}

void User::SetFavourites(const std::string& favourite)
{
	m_idsFavourites = favourite;
}

void User::AddToWatchedVector(IMoviePtr& film)
{
	m_watchedMovies.push_back(film);
}

void User::AddToFavouritesVector(IMoviePtr& film)
{
	m_favouriteMovies.push_back(film);
}

void User::leaveReview(Film& film, const int& grade)
{
	int sumOfGrades = film.GetSumOfGrades();
	sumOfGrades += grade;
	film.SetSumOfGrades(sumOfGrades);
	film.SetNumberOfReviews(film.GetNumberOfReviews() + 1);
	float averageRating = film.GetSumOfGrades() / film.GetNumberOfReviews();
	film.SetRating(averageRating);
}
