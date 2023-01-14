#pragma once
#include "KMeans.h"
#include "Register.h"
#include "Login.h"

#define PRESS_BACKSPACE 8
#define PRESS_ESC 27
#define PRESS_1 49
#define PRESS_2 50
#define PRESS_3 51
#define PRESS_4 52

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

    void PrintFilmPage();

    void PrintUserProfile();

    void RateThisFilm();

    void AddToWatched(const Film& film);

    void AddToFavourites(const Film& film);

    std::vector<Film> ManageLoopSimilarity(const std::vector<Film>& properVectorOfFilms);

private:
    User m_user;
    Film m_film;
    AppStorage m_storage;
    int m_option = -1;
};

