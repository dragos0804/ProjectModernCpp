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
	return m_password;
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


bool Register::UsernameValidation(const std::string& username, std::vector<User>& users)
{
	//small letters, digits and underscore only, minimum/maximum length is 4/15
	const std::regex usernamePattern("^[a-z0-9_]{4,15}$");
	if (std::regex_match(username, usernamePattern) && CheckUniqueUsername(users) == true)
		return true;
	return false;
}

bool Register::CheckUniqueUsername(std::vector<User>& users)
{
	for (auto& user : users)
		if (user.GetName() == m_username)
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

