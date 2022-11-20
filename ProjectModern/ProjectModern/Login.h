#pragma once

#include <string>
#include "ILogin.h"
#include "User.h"

class Login : public ILogin
{
public:
	Login(std::string usernameInput, std::string passwordInput);

	std::string GetUsernameInput() const override;
	std::string GetPasswordInput() const override;

	bool VerifyMatchUserToPassword(const User& user) override;

private:
	std::string m_usernameInput;
	std::string m_passwordInput;
};

