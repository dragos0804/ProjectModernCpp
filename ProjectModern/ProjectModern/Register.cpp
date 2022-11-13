#include "Register.h"
#include "User.h"

Register::Register(int id, std::string name, std::string username, std::string dateOfBirth, std::string password, std::string country)
	: m_id(id)
	, m_name(name)
	, m_username(username)
	, m_dateOfBirth(dateOfBirth)
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
	User(m_id, m_name, m_username, m_dateOfBirth, m_password, m_country);
	//TODO: Add in database
}
