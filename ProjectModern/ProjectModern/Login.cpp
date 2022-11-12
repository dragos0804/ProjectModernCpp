#include "Login.h"

bool Login::VerifyMatchUserToPassword(const User& user)
{
	return user.GetUsername() == m_usernameInput && user.GetPassword() == m_passwordInput;
}
