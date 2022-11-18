#pragma once

#include "IRegister.h"
#include <string>

class Register : public IRegister
{
public:
	Register(int id, std::string name, std::string username, std::string dateOfBirth, std::string password, std::string country);

	void SetName(const std::string& name) override;

	void SetUsername(const std::string& username) override;

	void SetPassword(const std::string& password) override;

	void SetDateOfBirth(const std::string& dateOfBirth) override;

	void SetCountry(const std::string& country) override;

	std::string GetName() const override;

	std::string GetUsername() const override;

	std::string GetPassword() const override;

	std::string GetDateOfBirth() const override;

	std::string GetCountry() const override;

	int GetId();

	void CreateUser() override;


private:
	int m_id;
	std::string m_name;
	std::string m_username;
	std::string m_dateOfBirth;
	std::string m_password;
	std::string m_country;

};
