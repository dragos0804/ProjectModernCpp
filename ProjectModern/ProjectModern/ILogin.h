#pragma once
#include <string>
#include "User.h"

class ILogin
{
	virtual ~ILogin() = default;

	virtual std::string GetUsernameInput() const = 0;

	virtual std::string GetPasswordInput() const = 0;

	virtual bool VerifyMatchUserToPassword(const User& user) = 0;
};

