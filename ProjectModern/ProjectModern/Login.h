#pragma once
#include <string>
#include "User.h"
class Login
{
public:
	Login(std::string usernameInput, std::string passwordInput);

	std::string GetUsernameInput() const;
	std::string GetPasswordInput() const;
	void SetUsernameInput(const std::string& username);
	void SetPasswordInput(const std::string& password);

	bool VerifyMatchUserToPassword(const User& user);
private:
	std::string m_usernameInput;
	std::string m_passwordInput;
};

