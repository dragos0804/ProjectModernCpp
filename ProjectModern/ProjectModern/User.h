#pragma once
#include <string>
#include <list>
#include <memory>
#include "Film.h"

using IMoviePtr = std::shared_ptr<class IMovie>;

class User
{
public:
	User() = default;
	User(int id, std::string name, std::string username, std::string dateOfBirth, std::string email, std::string password, std::string country);

	std::string GetName() const;
	std::string GetUsername() const;
	std::string GetDateOfBirth() const;
	std::string GetEmail() const;
	std::string GetPassword() const;
	std::string GetCountry() const;

	void SetName(std::string name);
	void SetUsername(std::string username);
	void SetDateOfBirth(std::string dateOfBirth);
	void SetEmail(std::string email);
	void SetPassword(std::string password);
	void SetCountry(std::string country);

	void leaveReview(Film& film, const int& grade);

	void AddMovieToWatched(IMoviePtr movie);

private:
	int m_id;
	std::string m_name;
	std::string m_username;
	std::string m_dateOfBirth;
	std::string m_email;
	std::string m_password;
	std::string m_country;
	std::list<IMoviePtr> m_watchedMovies;
	std::list<IMoviePtr> m_favouriteMovies;
};

