#include <iostream>
//#include "User.h"
//#include "Register.h"
//#include "IRegister.h"
//#include "ILogin.h"
//#include "Login.h"
//#include "MovieFiltering.h"
#include "Parser.h"

int main()
{
  //  std::cout << "Hello World!\n";

  //  std::string email = "denisachete1223yahoo.com";
  //  std::string username = "_denisa30";
  //  Register r(1, "Denisa Chete", username, "12-12-2022", email, "parola", "Romania");

  //  std::vector<User> users;
  //  
  //  if (r.CheckUniqueUsername(users))
  //      std::cout << "registered" << std::endl;
  //  User user1(1, "Denisa Chete", username, "12-12-2022", email, "parola", "Romania");
  //  users.push_back(user1);
  //  if (r.CheckUniqueUsername(users))
  //      std::cout << "registration failed" << std::endl;

  //  if (r.EmailValidation(email))
  //  {
  //      std::cout << "Email valid" << std::endl;
  //  }
  //  else
  //  {
  //      std::cout << "Email invalid" << std::endl;
  //  }

  //  if (r.UsernameValidation(username, users))
  //  {
  //      std::cout << "Username valid" << std::endl;
  //  }
  //  else
  //  {
  //      std::cout << "Username invalid" << std::endl;
  //  }

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

  ///*  MovieFiltering mv;
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

    ParseMethod();

    return 0;
}
