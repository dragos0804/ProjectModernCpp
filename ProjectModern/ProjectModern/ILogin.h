#pragma once
#include <string>
#include "User.h"
#include "Storage.h"

class ILogin
{
public:
	virtual ~ILogin() = default;

	virtual std::string GetUsernameInput() const = 0;

	virtual std::string GetPasswordInput() const = 0;

	virtual bool VerifyMatchUserToPassword(AppStorage& appStorage, const std::string& usernameInput, const std::string& passwordInput, User& savedUser) = 0;
};

