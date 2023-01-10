#include <iostream>
#include "UserInterface.h"
#include "Parser.h"

int main()
{

   // ParseMethod();

    
   /*AppStorage storage;

    auto allFilms = storage.m_db.get_all<Film>();

    for (auto& film : allFilms) {
        film.SetSumOfGrades(0);
            storage.m_db.update(film);
    }*/
    

    UserInterface UI;
    UI.StartUpMenu();

    return 0;
}
