#pragma once
#include <string>
#include "User.h"
#include <vector>

class IRegister
{
public:

	virtual ~IRegister() = default;

	virtual void SetName(const std::string& name) = 0;

	virtual void SetUsername(const std::string& username) = 0;

	virtual void SetEmail(const std::string& email) = 0;

	virtual void SetPassword(const std::string& password) = 0;

	virtual void SetDateOfBirth(const std::string& dateOfBirth) = 0;

	virtual void SetCountry(const std::string& country) = 0;

	virtual std::string GetName() const = 0;

	virtual std::string GetUsername() const = 0;

	virtual std::string GetEmail() const = 0;

	virtual std::string GetPassword() const = 0;

	virtual std::string GetDateOfBirth() const = 0;

	virtual std::string GetCountry() const = 0;

	virtual void CreateUser() = 0;

	virtual bool EmailValidation(const std::string& email) = 0;

	virtual bool UsernameValidation(const std::string& username, std::vector<User>& users) = 0;
	
	virtual bool CheckUniqueUsername(std::vector<User>& users) = 0;

	virtual bool PasswordValidation(const std::string& password) = 0;

	virtual std::string PasswordSecurityLevel(const int length, const uint8_t capital_letters, const uint8_t digits, bool special_characters) = 0;

	virtual bool AgeValidation(const std::string& dateOfBirth) = 0;
};

