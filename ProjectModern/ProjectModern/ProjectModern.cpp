#include <iostream>
#include "User.h"
#include "Register.h"
#include "IRegister.h"
#include "ILogin.h"
#include "Login.h"
#include "MovieFiltering.h"
#include "Parser.h"
#include "Storage.h"
#include <conio.h>
#include <Windows.h>

int main()
{
    std::string email = "denisachete1223yahoo.com";
    std::string username = "_denisa30";
    std::string dateOfBirth = "2002-01-30";

    /* std::vector<User> users;

     if (r.CheckUniqueUsername(users))
         std::cout << "registered" << std::endl;
     User user1(1, "Denisa Chete", username, "12-12-2022", email, "parola", "Romania");
     users.push_back(user1);
     if (r.CheckUniqueUsername(users))
         std::cout << "registration failed" << std::endl;

     if (r.EmailValidation(email))
     {
         std::cout << "Email valid" << std::endl;
     }
     else
     {
         std::cout << "Email invalid" << std::endl;
     }

     if (r.UsernameValidation(username, users))
     {
         std::cout << "Username valid" << std::endl;
     }
     else
     {
         std::cout << "Username invalid" << std::endl;
     }*/

     /*if (r.AgeValidation(dateOfBirth))
     {
         std::cout << "Valid age";
     }
     else
     {
         std::cout << "Invalid age";
     }*/

     //  User u;
     //  u.SetUsername(username);
     //  u.SetPassword("parola");

     //  Login l(username, "parola");
     //  if (l.VerifyMatchUserToPassword(u) == true)
     //      std::cout << "Login successful" << std::endl;

     //  Login l1(username, "parolaP");
     //  if (l1.VerifyMatchUserToPassword(u) == false)
     //      std::cout << "Login failed" << std::endl;

     //  Film f1(0, 7, 200, 5, "film1", "20-12-2020", { Film::Genre::action, Film::Genre::adventure }, { Film::Actor::A1 }, { Film::Producer::P1 });
     //  Film f2(1, 3, 100, 4, "film2", "21-12-2020", { Film::Genre::action, Film::Genre::adventure }, { Film::Actor::A2 }, { Film::Producer::P2 });

     //  std::vector<Film> movies;
     //  movies.push_back(f1);
     //  movies.push_back(f2);

     //  MovieFiltering mv;
     //  mv.SortBy(0);
     //  for (auto& movie : movies)
     //      std::cout << movie.GetName() << " ";
     //  std::cout << std::endl;

     //  mv.SortBy(1);
     //  for (auto& movie : movies)
     //      std::cout << movie.GetName() << " ";
     //  std::cout << std::endl;

     //  mv.SortBy(2);
     //  for (auto& movie : movies)
     //      std::cout << movie.GetName() << " ";
     //  std::cout << std::endl;

     //  mv.SortBy(3);
     //  for (auto& movie : movies)
     //      std::cout << movie.GetName() << " ";
     //  std::cout << std::endl;*/

     //  r.SetPassword("ParolaNoua1");
     //  r.PasswordValidation(r.GetPassword());
     //  r.SetPassword("ParolaPuternica123!");
     //  r.PasswordValidation(r.GetPassword());

      //ParseMethod();

      // User user1(1, "Denisa Chete", username, "12-12-2022", email, "parola", "Romania");

      // storage.AddUser(user1);

      // Film film1(1, 5, 120, 3.5, "Film", "Dick Johnson Is Dead", "TV-MA", "After crossing paths at a party, a Cape Town teen sets out to prove whether a private-school swimming star is her sister who was abducted at birth.", 2016, "Action, Drama", "", "Kirsten Johnson", "United States, Romania");
      // storage.AddFilm(film1);


    AppStorage storage;

    Register r;
    int option = 1;
    int keyCheck = -1;

    while (1) {
        switch (option)
        {
        case 1:
        {
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
            //std::cout << "\t\tChoose yout option : ";


            //std::cin >> option;
            //std::cin.get();

            // WINDOWS Specific = reads character ( also special ones ) without echoing and returns ASCII value
            option = _getch();
            break;
        }
        case 49:
        {
            system("CLS");
            std::cout << "\t\t*******************************************************\n";
            std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
            std::cout << "\t\t*******************************************************\n\n";

            std::cout << "\t\tRegister a new account" << std::endl;
            std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

            keyCheck = _getch();
            // BACKSPACE key -> 8 in ASCII Table
            if (keyCheck == 8) {
                option = 1;
                system("CLS");
                break;
            }

            // ESC key -> 27 in ASCII Table
            else if (keyCheck == 27) {
                option = -1;
                break;
            }

            r.CreateUser(storage);
            option = 50;
            break;
        }
        case 50:
        {
            std::string username = "";
            std::string password = "";
            system("CLS");
            std::cout << "\t\t*******************************************************\n";
            std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
            std::cout << "\t\t*******************************************************\n\n";

            std::cout << "\t\tLog into your account" << std::endl;
            std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

            keyCheck = _getch();
            // BACKSPACE key -> 8 in ASCII Table
            if (keyCheck == 8) {
                option = 1;
                system("CLS");
                break;
            }

            // ESC key -> 27 in ASCII Table
            else if (keyCheck == 27) {
                option = -1;
                break;
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
                option = 50;
                Sleep(4000);
                break;
            }
        }
        default:
            return 0;
        }
    }


    return 0;
}
