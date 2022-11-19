#include <iostream>
#include "User.h"
#include "Register.h"
#include "IRegister.h"

int main()
{
    std::cout << "Hello World!\n";

    std::string email = "denisachete1223yahoo.com";
    std::string username = "_denisa30";
    Register r(1, "Denisa Chete", username, "12-12-2022", email, "parola", "Romania");


    if (r.EmailValidation(email))
    {
        std::cout << "Email valid" << std::endl;
    }
    else
    {
        std::cout << "Email invalid" << std::endl;
    }

    if (r.UsernameValidation(username))
    {
        std::cout << "Username valid" << std::endl;
    }
    else
    {
        std::cout << "Username invalid" << std::endl;
    }
}
