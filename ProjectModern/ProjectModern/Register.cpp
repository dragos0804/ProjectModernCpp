#include "Register.h"
#include "User.h"

Register::Register(int id, std::string name, std::string username, std::string dateOfBirth, std::string email, std::string password, std::string country)
	: m_id(id)
	, m_name(name)
	, m_username(username)
	, m_dateOfBirth(dateOfBirth)
	, m_email(email)
	, m_password(password)
	, m_country (country)
{
}

void Register::SetName(const std::string& name)
{
	m_name = name;
}

void Register::SetUsername(const std::string& username)
{
	m_username = username;
}

void Register::SetEmail(const std::string& email)
{
	m_email = email;
}

void Register::SetPassword(const std::string& password)
{
	m_password = password;
}

void Register::SetDateOfBirth(const std::string& dateOfBirth)
{
	m_dateOfBirth = dateOfBirth;
}

void Register::SetCountry(const std::string& country)
{
	m_country = country;
}

std::string Register::GetName() const
{
	return m_name;
}

std::string Register::GetUsername() const
{
	return m_username;
}

std::string Register::GetEmail() const
{
	return m_email;
}

std::string Register::GetPassword() const
{
	return std::string();
}

std::string Register::GetDateOfBirth() const
{
	return m_dateOfBirth;
}

std::string Register::GetCountry() const
{
	return m_country;
}

int Register::GetId()
{
	return m_id;
	//TODO: Take id from db or autoincrement on each new user created
}

void Register::CreateUser()
{
	User(m_id, m_name, m_username, m_dateOfBirth, m_email, m_password, m_country);
	//TODO: Add in database
}

bool Register::EmailValidation(const std::string& email) 
{
	const std::regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (std::regex_match(email, emailPattern))
		return true;
	return false;
}


bool Register::UsernameValidation(const std::string& username)
{
	//small letters, digits and underscore only, minimum/maximum length is 4/15
	const std::regex usernamePattern("^[a-z0-9_]{4,15}$");
	if (std::regex_match(username, usernamePattern))
		return true;
	return false;
}

