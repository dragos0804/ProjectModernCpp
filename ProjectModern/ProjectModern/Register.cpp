#include "Register.h"
#include "User.h"
#include "../Validation/Validate.h"

void Register::CreateUser(AppStorage& appStorage)
{
	User user;
	std::string str = "";

	std::cout << "\t\tEnter your name: ";
	std::getline(std::cin, str);

	while (Validate::IsBlankField(str) || Validate::ContainsOnlyWhiteSpaces(str) || !Validate::ContainsNumbers(str))
	{
		std::cout << "\t\tEnter your name: ";
		std::getline(std::cin, str);
	}
	
	user.SetName(str);
	std::cout << std::endl;

	std::cout << "\t\tEnter your username: ";
	std::getline (std::cin, str);

	while (Validate::IsBlankField(str) || Validate::ContainsOnlyWhiteSpaces(str))
	{
		std::cout << "\t\tEnter your username: ";
		std::getline(std::cin, str);
	}

	while (UsernameValidation(str, appStorage) == false)
	{
		std::cout << "\t\tThis username is taken. Please insert another username: ";
		
		std::getline (std::cin, str);
	}
	user.SetUsername(str);
	std::cout << std::endl;

	std::cout << "\t\tSet up a password (minimum 7 characters, one digit and one capital letter): ";
	std::getline(std::cin, str);

	while (Validate::IsBlankField(str) || Validate::ContainsOnlyWhiteSpaces(str))
	{
		std::cout << "\t\tSet up a password (minimum 7 characters, one digit and one capital letter): ";
		std::getline(std::cin, str);
	}


	while (PasswordValidation(str) == false)
	{
		std::getline(std::cin, str);
	}
	user.SetPassword(str);
	std::cout << std::endl;

	std::cout << "\t\tEnter your date of birth (YYYY-MM-DD): ";
	std::getline (std::cin, str);

	while (Validate::IsBlankField(str) || Validate::ContainsOnlyWhiteSpaces(str))
	{
		std::cout << "\t\tEnter your date of birth (YYYY-MM-DD): ";
		std::getline(std::cin, str);
	}

	while (AgeValidation(str) == false)
	{
		std::cout << "\t\tYou must be 13 or older in order to create an account. Please try again: ";
		
		std::getline (std::cin, str);
	}
	user.SetDateOfBirth(str);
	std::cout << std::endl;

	std::cout << "\t\tEnter your email: ";
	std::getline (std::cin, str);

	while (Validate::IsBlankField(str) || Validate::ContainsOnlyWhiteSpaces(str))
	{
		std::cout << "\t\tEnter your email: ";
		std::getline(std::cin, str);
	}

	while (EmailValidation(str, appStorage) == false)
	{
		std::cout << "\t\tInvalid e-mail! Please try again: ";
		std::getline (std::cin, str);
	}
	user.SetEmail(str);
	std::cout << std::endl;

	std::cout << "\t\tEnter your country of origin: ";
	std::getline (std::cin, str);

	while (Validate::IsBlankField(str) || Validate::ContainsOnlyWhiteSpaces(str))
	{
		std::cout << "\t\tEnter your country of origin: ";
		std::getline(std::cin, str);
	}

	user.SetCountry(str);
	std::cout << std::endl;

	appStorage.AddUser(user);
}

bool Register::EmailValidation(const std::string& email, AppStorage& appStorage)
{
	const std::regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (std::regex_match(email, emailPattern) && CheckUniqueEmail(email, appStorage) == true)
		return true;
	return false;
}

bool Register::CheckUniqueEmail(const std::string& email, AppStorage& appStorage)
{
	auto selectQueryEmails = appStorage.m_db.select(&User::GetEmail);
	for (const auto& user : selectQueryEmails)
		if (user == email)
			return false;
	return true;
}


bool Register::UsernameValidation(const std::string& username, AppStorage& appStorage)
{
	//small letters, digits and underscore only, minimum/maximum length is 4/15
	const std::regex usernamePattern("^[a-z0-9_]{4,15}$");
	if (std::regex_match(username, usernamePattern) && CheckUniqueUsername(username, appStorage) == true)
		return true;
	return false;
}

bool Register::CheckUniqueUsername(const std::string& username, AppStorage& appStorage)
{
	auto selectQueryUsernames =  appStorage.m_db.select(&User::GetUsername);
	for (const auto& user : selectQueryUsernames)
		if (user == username)
			return false;
	return true;
}

bool Register::PasswordValidation(const std::string& password)
{
	uint8_t capital_letters = 0, digits = 0;
	bool special_characters = false;

	for (auto& current_char : password) {
		if (islower(current_char))
			continue;
		else if (isupper(current_char))
			capital_letters++;
		else if (isdigit(current_char))
			digits++;
		else
			special_characters = true;
	}

	std::cout << PasswordSecurityLevel(password.length(), capital_letters, digits, special_characters) << std::endl;

	if (password.length() >= 7 && capital_letters && digits) 
		return true;

	return false;
}

std::string Register::PasswordSecurityLevel(const int length, const uint8_t capital_letters, const uint8_t digits, bool special_characters)
{
	if (length >= 13 && special_characters && capital_letters >= 2 && digits >= 2) {
		return "\t\tStrong password!";
	}
	else if (length >= 10 && capital_letters >= 2 && digits >= 2) {
		return "\t\tMedium password: for better security you must have at least 13 characters, 2 capital leters, 2 digits and one special character.";
	}
	else if (length >= 7 && capital_letters >= 1 && digits >= 1) {
		return "\t\tWeak password : for better security you must have at least 10 characters, 1 capital leters, 1 digits.";
	}
	else {
		return "\t\tInvalid password: You must have at least 7 characters, 1 capital leter, 1 digit.";
	}
}

bool Register::AgeValidation(const std::string& dateOfBirth)
{
	//format YYYY-MM-DD
	int day, month, year;
	struct tm date = { 0 };
	date.tm_year = atoi(dateOfBirth.substr(0, 4).c_str()) - 1900;
	date.tm_mon = atoi(dateOfBirth.substr(5, 2).c_str()) - 1;
	date.tm_mday = atoi(dateOfBirth.substr(8, 2).c_str());
	time_t userDateOfBirth = mktime(&date);
	time_t current;
	time(&current);
	int age = ((difftime(current, userDateOfBirth) + 86400L / 2) / 86400L) / 365;
	if (age > 13)
		return true;
	return false;
}

