#pragma once
#include <string>
#include <list>
#include <memory>
#include "Film.h"


class User
{
public:
	using IMoviePtr = std::shared_ptr<std::vector<Film>>;

public:
	User() = default;
	User(int id, std::string name, std::string username, std::string dateOfBirth, std::string email, std::string password, std::string country);

	unsigned int GetID() const;
	std::string GetName() const;
	std::string GetUsername() const;
	std::string GetDateOfBirth() const;
	std::string GetEmail() const;
	std::string GetPassword() const;
	std::string GetCountry() const;

	void SetID(const unsigned int& id);
	void SetName(const std::string& name);
	void SetUsername(const std::string& username);
	void SetDateOfBirth(const std::string& dateOfBirth);
	void SetEmail(const std::string& email);
	void SetPassword(const std::string& password);
	void SetCountry(const std::string& country);

	//void leaveReview(Film& film, const int& grade);

	void AddMovieToWatched(IMoviePtr movie);
	void AddMovieToFavourites(IMoviePtr movie);

private:
	unsigned int m_id;
	std::string m_name;
	std::string m_username;
	std::string m_dateOfBirth;
	std::string m_email;
	std::string m_password;
	std::string m_country;
	std::vector<IMoviePtr> m_watchedMovies;
	std::vector<IMoviePtr> m_favouriteMovies;
};

