#pragma once
#include <limits>
#include <string>
#include <dos.h>
#include "Storage.h"
#include "User.h"

class Login 
{
public:
	Login(std::string usernameInput, std::string passwordInput);

	std::string GetUsernameInput() const;
	std::string GetPasswordInput() const;

	bool VerifyMatchUserToPassword(AppStorage& appStorage, const std::string& usernameInput, const std::string& passwordInput, User& SavedUser);

private:
	std::string m_usernameInput;
	std::string m_passwordInput;
};

