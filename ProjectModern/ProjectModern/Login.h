#pragma once
#include <string>

class Login
{
private:
	std::string m_usernameInput;
	std::string m_passwordInput;
public:
	bool VerifyMatchUserTo();
};

