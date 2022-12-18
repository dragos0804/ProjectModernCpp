#include "UserInterface.h"

void UserInterface::StartUpMenu()
{
    option = -1;

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
        RegisterMenu();
    }
    // 2 == 50 in ASCII table
    else if (option == 50) {
        LoginMenu();
    }
    // ESC KEY
    else if (option == 27)
        exit(0);
    // any other key will not change anything
    else {
        system("CLS");
        StartUpMenu();
    }
}

void UserInterface::RegisterMenu()
{
    option = -1;

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
        StartUpMenu();
    }

    // ESC key -> 27 in ASCII Table
    else if (option == 27) {
        exit(0);
    }

    Register r;
    r.CreateUser(storage);

    LoginMenu();
}

void UserInterface::LoginMenu()
{
    option = -1;

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
        StartUpMenu();
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
        LoggedInMenu();
    }
    else {
        Sleep(4000);
        LoginMenu();
    }
}

void UserInterface::LoggedInMenu()
{
    option = -1;

    system("CLS");
    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
    std::cout << "\t\t*******************************************************\n\n";

    std::cout << "\t\t+----------------------------------------------------+\n";
    std::cout << "\t\t|                       WELCOME!                     |\n";
    std::cout << "\t\t+----------------------------------------------------+\n";
    std::cout << "\t\t|                                                    |\n";
    std::cout << "\t\t|                You are now logged in!              |\n";
    std::cout << "\t\t|                                                    |\n";
    std::cout << "\t\t|                  1. Settings                       |\n";
    std::cout << "\t\t|                  2. Switch Account                 |\n";
    std::cout << "\t\t|                                                    |\n";
    std::cout << "\t\t+----------------------------------------------------+\n\n";


    option = _getch();

    if (option == 49)
        SettingsMenu();

    //else if (option == 50)
       // TODO: SwitchAccount();

    // BACKSPACE key -> 8 in ASCII Table
    else if (option == 8) {
        system("CLS");
        StartUpMenu();
    }

    // ESC key -> 27 in ASCII Table
    else if (option == 27) {
        exit(0);
    }
    else {
        LoggedInMenu();
    }
}

void UserInterface::SettingsMenu()
{
    system("CLS");
    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
    std::cout << "\t\t*******************************************************\n\n";

    std::cout << "\t\tSettings" << std::endl;
    std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

    std::cout << "\t\t1. Change Username" << std::endl;
    std::cout << "\t\t2. Change Password" << std::endl;

    option = _getch();

    //if (option == 49)
        // TODO: ChangePassword();

    //else if (option == 50)
       // TODO: ChangeUsername();

    // BACKSPACE key -> 8 in ASCII Table
    if (option == 8) {
        system("CLS");
        LoggedInMenu();
    }

    // ESC key -> 27 in ASCII Table
    else if (option == 27) {
        exit(0);
    }
    else {
        SettingsMenu();
    }

}
