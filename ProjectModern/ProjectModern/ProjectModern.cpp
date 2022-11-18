#include <iostream>
#include "User.h"
#include "Register.h"
#include "IRegister.h"

int main()
{
    std::cout << "Hello World!\n";

    std::string email = "denisachete1223yahoo.com";
    Register r(1, "Denisa Chete", "denic30", "12-12-2022", email, "parola", "Romania");


    if (r.EmailValidation(email))
    {
        std::cout << "Email valid";
    }
    else
    {
        std::cout << "Email invalid";
    }
}
