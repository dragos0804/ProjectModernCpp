#pragma once
#include <string>
#include "User.h"
class Login
{
private:
	std::string m_usernameInput;
	std::string m_passwordInput;
public:
	bool VerifyMatchUserToPassword(const User& user);
};

