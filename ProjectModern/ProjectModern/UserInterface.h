#pragma once
#include "Register.h"
#include "Storage.h"
#include <conio.h>
#include <Windows.h>
#include "Login.h"

class UserInterface
{
public:
    void StartUpMenu();

private:
    void RegisterMenu();

    void LoginMenu();

    void LoggedInMenu();

    void SettingsMenu();

    void SearchForAFilm();

    void ChangePassword();
    
    void ChangeUsername();

    void PrintMenu();

    void PrintUserProfile();

private:
    User user;
    Film film;
    AppStorage storage;
    int option = -1;
};

