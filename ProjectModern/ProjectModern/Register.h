#pragma once
#include "User.h"
#include "Storage.h"
#include <regex>
#include <ctime>

class Register
{
public:
	Register() = default;

	void CreateUser(AppStorage& appStorage);

	bool EmailValidation(const std::string& email, AppStorage& appStorage);

	bool CheckUniqueEmail(const std::string& email, AppStorage& appStorage);
	
	bool UsernameValidation(const std::string& username, AppStorage& appStorage);

	bool CheckUniqueUsername(const std::string& username, AppStorage& appStorage);

	bool PasswordValidation(const std::string& password);

	std::string PasswordSecurityLevel(const int length, const uint8_t capital_letters, const uint8_t digits, bool special_characters);

	bool AgeValidation(const std::string& dateOfBirth);

};

