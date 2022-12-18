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

private:
    AppStorage storage;
    int option = -1;
};

