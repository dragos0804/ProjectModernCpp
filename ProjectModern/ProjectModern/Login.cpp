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

bool Login::VerifyMatchUserToPassword(AppStorage& appStorage, const std::string& usernameInput, const std::string& passwordInput)
{
	auto selectUsers = appStorage.m_db.get_all<User>(where(c(&User::GetUsername) == usernameInput));
	if (selectUsers.size() == 0)
	{
		std::cout << "\t\tThere is no user with the username " << "\"" << usernameInput << "\"! Please, try again.\n";
		return false;
	}
	else
	{
		for (const auto& user : selectUsers)
			if (user.GetPassword() != passwordInput)
			{
				std::cout << "\t\tMissmatched password! Please, try again.\n";
				return false;
			}
	}
	system("CLS");
	std::cout << "\t\t*******************************************************\n";
	std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
	std::cout << "\t\t*******************************************************\n\n";

	std::cout << "\t\t+----------------------------------------------------+\n";
	std::cout << "\t\t|                       WELCOME!                     |\n";
	std::cout << "\t\t+----------------------------------------------------+\n";
	std::cout << "\t\t|                                                    |\n";
	std::cout << "\t\t|                  You are now loged in!             |\n";
	std::cout << "\t\t|                  Check out what's new!             |\n";
	std::cout << "\t\t|                                                    |\n";
	std::cout << "\t\t+----------------------------------------------------+\n\n";
	std::cout << "\t\tPress ENTER to continue...\n";

	return true;
}
