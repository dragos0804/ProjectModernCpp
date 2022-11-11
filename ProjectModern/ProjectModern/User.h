#pragma once
#include <string>
#include <list>
#include "Film.h"

class User
{
public:
	User();
	User(int m_id, std::string name, std::string username, std::string dateOfBirth, std::string password, std::string country);

	std::string GetName() const;
	std::string GetUsername() const;
	std::string GetDateOfBirth() const;
	std::string GetPassword() const;
	std::string GetCountry() const;

	void SetName(std::string name);
	void SetUsername(std::string username);
	void SetDateOfBirth(std::string dateOfBirth);
	void SetPassword(std::string password);
	void SetCountry(std::string country);

private:
	int m_id;
	std::string m_name;
	std::string m_username;
	std::string m_dateOfBirth;
	std::string m_password;
	std::string m_country;
	
};

