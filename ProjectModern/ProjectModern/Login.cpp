#include "Login.h"

Login::Login(std::string usernameInput, std::string passwordInput)
	: m_usernameInput(usernameInput)
	, m_passwordInput(passwordInput)
{

}

std::string Login::GetUsernameInput() const
{
	return m_usernameInput;
}

std::string Login::GetPasswordInput() const
{
	return m_passwordInput;
}

bool Login::VerifyMatchUserToPassword(const User& user)
{
	return user.GetUsername() == m_usernameInput && user.GetPassword() == m_passwordInput;
}
