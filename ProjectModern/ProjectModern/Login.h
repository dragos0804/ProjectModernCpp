#pragma once
#include <limits>
#include <string>
#include <dos.h>
#include "ILogin.h"
#include "User.h"

class Login : public ILogin
{
public:
	Login(std::string usernameInput, std::string passwordInput);

	std::string GetUsernameInput() const override;
	std::string GetPasswordInput() const override;

	bool VerifyMatchUserToPassword(AppStorage& appStorage, const std::string& usernameInput, const std::string& passwordInput) override;

private:
	std::string m_usernameInput;
	std::string m_passwordInput;
};

