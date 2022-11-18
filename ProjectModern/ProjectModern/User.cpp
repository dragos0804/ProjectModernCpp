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

void User::SetName(std::string name)
{
	m_name = name;
}

void User::SetUsername(std::string username)
{
	m_username = username;
}

void User::SetDateOfBirth(std::string dateOfBirth)
{
	m_dateOfBirth = dateOfBirth;
}

void User::SetEmail(std::string email)
{
	m_email = email;
}

void User::SetPassword(std::string password)
{
	m_password = password;
}

void User::SetCountry(std::string country)
{
	m_country = country;
}

void User::leaveReview(Film& film, const int& grade)
{
	double sumOfGrades=0.0;
	sumOfGrades += grade;
	double averageRating = sumOfGrades / film.GetNumberOfReviews();
	film.SetNumberOfReviews(film.GetNumberOfReviews() + 1);
	film.SetRating(averageRating);
}
