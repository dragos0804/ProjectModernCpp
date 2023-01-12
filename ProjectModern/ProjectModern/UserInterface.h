#pragma once
#include "KMeans.h"
#include "Register.h"
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

    void AddToWatched(const Film& film);

    //void AddToFavourites(const Film& film);

private:
    User user;
    Film film;
    AppStorage storage;
    int option = -1;
};

