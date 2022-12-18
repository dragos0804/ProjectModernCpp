#include "UserInterface.h"

void UserInterface::StartUpMenu(Register r, AppStorage storage)
{
    int option = 1;

    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
    std::cout << "\t\t*******************************************************\n\n";

    std::cout << "\t\t+----------------------------------------------------+\n";
    std::cout << "\t\t|                       MENU                         |\n";
    std::cout << "\t\t+----------------------------------------------------+\n";
    std::cout << "\t\t|                                                    |\n";
    std::cout << "\t\t|                    1. Register                     |\n";
    std::cout << "\t\t|                    2. Login                        |\n";
    std::cout << "\t\t|                                                    |\n";
    std::cout << "\t\t+----------------------------------------------------+\n\n";

    option = _getch();

    // 1 == 49 in ASCII table
    if (option == 49) {
        RegisterMenu(r, storage);
    }
    // 2 == 50 in ASCII table
    else if (option == 50) {
        LoginMenu(r, storage);
    }
    // ESC KEY
    else if (option == 27)
        exit(0);
    // any other key will not change anything
    else {
        system("CLS");
        StartUpMenu(r, storage);
    }
}

void UserInterface::RegisterMenu(Register r, AppStorage storage)
{
    int option = -1;

    system("CLS");
    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
    std::cout << "\t\t*******************************************************\n\n";

    std::cout << "\t\tRegister a new account" << std::endl;
    std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

    option = _getch();
    // BACKSPACE key -> 8 in ASCII Table
    if (option == 8) {
        system("CLS");
        StartUpMenu(r, storage);
    }

    // ESC key -> 27 in ASCII Table
    else if (option == 27) {
        exit(0);
    }

    r.CreateUser(storage);

    LoginMenu(r, storage);
}

void UserInterface::LoginMenu(Register r, AppStorage storage)
{
    int option = -1;

    std::string username = "";
    std::string password = "";
    system("CLS");
    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
    std::cout << "\t\t*******************************************************\n\n";

    std::cout << "\t\tLog into your account" << std::endl;
    std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

    option = _getch();
    // BACKSPACE key -> 8 in ASCII Table
    if (option == 8) {
        system("CLS");
        StartUpMenu(r, storage);
    }

    // ESC key -> 27 in ASCII Table
    else if (option == 27) {
        exit(0);
    }

    std::cout << "\t\tUsername: ";
    std::getline(std::cin, username);
    std::cout << "\t\tPassword: ";
    std::getline(std::cin, password);

    Login l(username, password);
    bool verifiedLoginStatus = l.VerifyMatchUserToPassword(storage, username, password);

    if (verifiedLoginStatus) {
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
    }
    else {
        Sleep(4000);
        LoginMenu(r, storage);
    }
}
