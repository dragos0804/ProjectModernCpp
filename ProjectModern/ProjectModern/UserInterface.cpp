#include "UserInterface.h"

void UserInterface::StartUpMenu()
{
    option = 1;
    PrintMenu();

    option = _getch();

    switch (option) {
    // 1 == 49 in ASCII table
    case 49:
        RegisterMenu();
        break;
    case 50:
        LoginMenu();
        break;
    // ESC KEY
    case 27:
        exit(0);
    // any other key will not change anything
    default:
        StartUpMenu();
        break;
    }
}

void UserInterface::RegisterMenu()
{
    PrintMenu();

    std::cout << "\t\tRegister a new account" << std::endl;
    std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

    option = _getch();

    switch (option) {
    case 8:
        StartUpMenu();
        break;
    // 1 == 49 in ASCII table
    case 49:
        RegisterMenu();
        break;
    case 50:
        LoginMenu();
        break;
    // ESC KEY
    case 27:
        exit(0);
    // any other key will not change anything
    default:
        Register r;
        r.CreateUser(storage);
        LoginMenu();
        break;
    }
}

void UserInterface::LoginMenu()
{
    PrintMenu();

    std::cout << "\t\tLog into your account" << std::endl;
    std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

    option = _getch();

    switch (option) {
    case 8:
        StartUpMenu();
        break;
        // 1 == 49 in ASCII table
    case 49:
        RegisterMenu();
        break;
    case 50:
        LoginMenu();
        break;
        // ESC KEY
    case 27:
        exit(0);
        // any other key will not change anything
    default:
        std::string username = "";
        std::string password = "";

        std::cout << "\t\tUsername: ";
        std::getline(std::cin, username);
        std::cout << "\t\tPassword: ";
        std::getline(std::cin, password);

        Login l(username, password);
        bool verifiedLoginStatus = l.VerifyMatchUserToPassword(storage, username, password, user);

        if (verifiedLoginStatus) {
            LoggedInMenu();
        }
        else {
            Sleep(4000);
            LoginMenu();
        }
        break;
    }
}

void UserInterface::LoggedInMenu()
{
    option = 2;
    PrintMenu();

    option = _getch();

    switch (option) {
    case 8:
        StartUpMenu();
        break;
    case 49:
        SettingsMenu();
        break;
    case 50:
        // TODO: SwitchAccount();
        break;
    case 51:
        SearchForAFilm();
        break;
    case 27:
        exit(0);
    default:
        LoggedInMenu();
        break;
    }
}

void UserInterface::SettingsMenu()
{
    option = 3;
    PrintMenu();

    std::cout << "\t\tPress BACKSPACE to go back or choose an option" << std::endl;

    option = _getch();

    switch (option) {
    case 8:
        StartUpMenu();
        break;
    case 49:
        ChangeUsername();
        break;
    case 50:
        ChangePassword();
        break;
    case 27:
        exit(0);
    // any other key will not change anything
    default:
        SettingsMenu();
        break;
    }
}

void UserInterface::SearchForAFilm()
{
    std::string title;
    std::cout << "\t\tSearch: ";
    std::getline(std::cin, title);
    std::cout << std::endl;
    storage.SearchFilmByTitle(title);
}

void UserInterface::ChangePassword()
{
    std::string password = "";

    std::cout << "\t\tNew Password: ";
    std::getline(std::cin, password);

    user.SetPassword(password);

    Register r;
    if (r.PasswordValidation(password)) {
        storage.m_db.update(user);
        std::cout << "\t\tPassword Changed Succesfully!";
        Sleep(2500);
    }
    else       
        Sleep(4000);

    LoggedInMenu();
}

void UserInterface::ChangeUsername()
{
    std::string username = "";

    std::cout << "\t\tNew Username: ";
    std::getline(std::cin, username);

    user.SetUsername(username);

    Register r;
    if (r.UsernameValidation(username, storage)) {
        std::cout << "\t\tUsername Changed Succesfully!";
        storage.m_db.update(user);
        Sleep(2500);
    }
    else {
        std::cout << "\t\tUsername Already Taken / Username Invalid. Try again.";
        Sleep(2500);
    }
    
    LoggedInMenu();
}

void UserInterface::PrintMenu()
{
    system("CLS");
    std::cout << "\t\t*******************************************************\n";
    std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
    std::cout << "\t\t*******************************************************\n\n";

    switch (option)
    {
    case 1:
        std::cout << "\t\t+----------------------------------------------------+\n";
        std::cout << "\t\t|                       MENU                         |\n";
        std::cout << "\t\t+----------------------------------------------------+\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t|                    1. Register                     |\n";
        std::cout << "\t\t|                    2. Login                        |\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t+----------------------------------------------------+\n\n";
        break;
    case 2:
        std::cout << "\t\t+----------------------------------------------------+\n";
        std::cout << "\t\t|                       WELCOME!                     |\n";
        std::cout << "\t\t+----------------------------------------------------+\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t|                You are now logged in!              |\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t|                  1. Settings                       |\n";
        std::cout << "\t\t|                  2. Switch Account                 |\n";
        std::cout << "\t\t|                  3. Search for a film              |\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t+----------------------------------------------------+\n\n";
        break;
    case 3:
        std::cout << "\t\t+----------------------------------------------------+\n";
        std::cout << "\t\t|                      SETTINGS                      |\n";
        std::cout << "\t\t+----------------------------------------------------+\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t|                 1. Change Username                 |\n";
        std::cout << "\t\t|                 2. Change Password                 |\n";
        std::cout << "\t\t|                                                    |\n";
        std::cout << "\t\t+----------------------------------------------------+\n\n";
        break;
    default:
        break;
    }
}
