#pragma once
#include <string>
#include "User.h"
#include "Storage.h"
#include <vector>

class IRegister
{
public:

	virtual ~IRegister() = default;

	virtual void CreateUser(AppStorage& appStorage) = 0;

	virtual bool EmailValidation(const std::string& email, AppStorage& appStorage) = 0;

	virtual bool CheckUniqueEmail(const std::string& email, AppStorage& appStorage) = 0;

	virtual bool UsernameValidation(const std::string& username, AppStorage& appStorage) = 0;
	
	virtual bool CheckUniqueUsername(const std::string& username, AppStorage& appStorage) = 0;

	virtual bool PasswordValidation(const std::string& password) = 0;

	virtual std::string PasswordSecurityLevel(const int length, const uint8_t capital_letters, const uint8_t digits, bool special_characters) = 0;

	virtual bool AgeValidation(const std::string& dateOfBirth) = 0;
};

