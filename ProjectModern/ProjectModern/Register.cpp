#include "Register.h"
#include "User.h"

void Register::CreateUser(AppStorage& appStorage)
{
	//work in progress - bug occurs when reading the first line, no issues otherwise
	User user;
	std::string str;
	std::cout << "Register a new account\n";

	std::cout << "Enter your name: \n";
	std::getline (std::cin, str);
	user.SetName(str);
	std::cout << "\n";

	std::cout << "Enter your username: \n";
	std::getline (std::cin, str);
	while (UsernameValidation(str, appStorage) == false)
	{
		std::cout << "This username is taken. Please insert another username: \n";
		std::getline (std::cin, str);
	}
	user.SetUsername(str);
	std::cout << "\n";

	std::cout << "Enter your date of birth (YYYY-MM-DD): \n";
	std::getline (std::cin, str);
	while (AgeValidation(str) == false)
	{
		std::cout << "You must be 13 or older in order to create an account. Please try again: \n";
		std::getline (std::cin, str);
	}
	user.SetDateOfBirth(str);
	std::cout << "\n";

	std::cout << "Enter your email: \n";
	std::getline (std::cin, str);
	while (EmailValidation(str) == false) // + check unique e-mail
	{
		std::cout << "Invalid e-mail! Please try again: \n";
		std::getline (std::cin, str);
	}
	user.SetEmail(str);
	std::cout << "\n";

	std::cout << "Set up a password (minimum 7 characters, one digit and one capital letter): \n";
	std::getline (std::cin, str);
	while (PasswordValidation(str) == false) // + check unique e-mail
	{
		std::getline (std::cin, str);
	}
	user.SetPassword(str);
	std::cout << "\n";

	std::cout << "Enter your country of origin: \n";
	std::getline (std::cin, str);
	user.SetCountry(str);
	std::cout << "\n";

	appStorage.AddUser(user);
}

bool Register::EmailValidation(const std::string& email) 
{
	const std::regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (std::regex_match(email, emailPattern))
		return true;
	return false;
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
	auto selectQueryUsernames =  appStorage.m_db.get_all<User>(where(c(&User::GetUsername) != username));
	for (const auto& user : selectQueryUsernames)
		if (user.GetUsername() == username)
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
		return "Strong password!";
	}
	else if (length >= 10 && capital_letters >= 2 && digits >= 2) {
		return "Medium password: for better security you must have at least 13 characters, 2 capital leters, 2 digits and one special character.";
	}
	else if (length >= 7 && capital_letters >= 1 && digits >= 1) {
		return "Weak password : for better security you must have at least 10 characters, 1 capital leters, 1 digits.";
	}
	else {
		return "Invalid password: You must have at least 7 characters, 1 capital leter, 1 digit.";
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

