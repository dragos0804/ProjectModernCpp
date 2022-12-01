#pragma once

#include "IRegister.h"
#include <regex>
#include <ctime>

class Register : public IRegister
{
public:
	Register() = default;

	void CreateUser(AppStorage& appStorage) override;

	bool EmailValidation(const std::string& email) override;

	bool UsernameValidation(const std::string& username, AppStorage& appStorage) override;

	bool CheckUniqueUsername(const std::string& username, AppStorage& appStorage) override;

	bool PasswordValidation(const std::string& password) override;

	std::string PasswordSecurityLevel(const int length, const uint8_t capital_letters, const uint8_t digits, bool special_characters) override;

	bool AgeValidation(const std::string& dateOfBirth) override;

};

