#include "UserInterface.h"
#include "../Validation/Validate.h"

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

		while (Validate::IsBlankField(username) || Validate::ContainsOnlyWhiteSpaces(username))
		{
			std::cout << "\t\tUsername: ";
			std::getline(std::cin, username);
		}

		std::cout << "\t\tPassword: ";
		std::getline(std::cin, password);

		while (Validate::IsBlankField(password) || Validate::ContainsOnlyWhiteSpaces(password))
		{
			std::cout << "\t\tPassword: ";
			std::getline(std::cin, password);
		}

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
	case 49:
		SettingsMenu();
		break;
	case 50:
		//switch user
		LoginMenu();
		break;
	case 51:
		SearchForAFilm();
		break;
	case 52:
		PrintUserProfile();
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
		LoggedInMenu();
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
	int movieNumber;
	std::cout << "\t\tSearch: \n";

	while (title.empty())
	{
		std::cout << "\t\t";
		std::getline(std::cin, title);
	}

	std::cout << std::endl;
	if (storage.SearchFilmByTitle(title))
	{
		std::cout << std::endl;
		std::cout << "\t\tSelect a movie: ";
		std::cin >> movieNumber;


		option = -1;

		film = storage.SelectFilmFromCurrentList(title, movieNumber);

		std::cout << "\t\t------------------------------------------------------\n";
		std::cout << "\t\tSimilar movies, based on genres:\n";


		std::vector<std::string> vectorOfCategoriesForFilm = AppStorage::split(film.GetGenres(), ", ");
		std::vector<Film> films = storage.GetFilmsByCategory(vectorOfCategoriesForFilm);

		KMeans kmeans(vectorOfCategoriesForFilm.size());
		kmeans.Run(films);

		std::vector<Film> similarFilms = kmeans.GetSimilarFilms(film);
		int countMax10FilmsPerRecommendation = 1;
		for (const auto& simFilm : similarFilms)
		{
			if (countMax10FilmsPerRecommendation == 11)
				break;
			std::cout << "\t\t\t" << countMax10FilmsPerRecommendation << ". " << simFilm.GetTitle() << " - " << simFilm.GetGenres() << std::endl;
			countMax10FilmsPerRecommendation++;
		}

		std::cout << "\t\t1. Leave review." << std::endl;
		std::cout << "\t\t2. Add to watched." << std::endl;
		std::cout << "\t\t3. Add to favourites." << std::endl;
		std::cout << std::endl;
	}
	std::cout << "\t\tPress BACKSPACE to go back" << std::endl;

	option = _getch();

	switch (option) {
	case 8:
		LoggedInMenu();
		break;
	case 49:
	{
		int grade;
		std::cout << "\t\tLeave a grade between 1 and 10 for this film: ";
		std::cin >> grade;
		user.leaveReview(film, grade);
		std::cout << "\t\tThank you! Rating after your review: " << film.GetRating() << std::endl;
		storage.m_db.update(film);
		std::cout << "\t\tPress BACKSPACE to go back" << std::endl;

		option = _getch();

		switch (option) {
		case 8:
			LoggedInMenu();
			break;
		case 27:
			exit(0);
		default:
			LoggedInMenu();
			break;
		}
		break;
	}
	case 50:
		AddToWatched(film);
		break;
	case 51:
		//AddToFavourites(film);
		break;
	case 27:
		exit(0);
		// any other key will not change anything
	default:
		LoggedInMenu();
		break;
	}

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


void UserInterface::PrintUserProfile()
{
	PrintMenu();
	std::cout << "\t\t" << "Name: " << user.GetName() << std::endl;
	std::cout << "\t\t" << "Username: " << user.GetUsername() << std::endl;
	std::cout << "\t\t" << "Date of birth: " << user.GetDateOfBirth() << std::endl;
	std::cout << "\t\t" << "Country: " << user.GetCountry() << std::endl;
	std::cout << "\t\t" << "Email: " << user.GetEmail() << std::endl;
	std::cout << "\t\t" << "Watched movies: " << user.GetWatchedMovies() << std::endl;
	std::cout << "\t\t" << "Favourite movies: " << user.GetFavouriteMovies() << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "\t\tPress BACKSPACE to go back" << std::endl;

	option = _getch();

	switch (option) {
	case 8:
		LoggedInMenu();
		break;
	case 27:
		exit(0);
	default:
		LoggedInMenu();
		break;
	}
}

void UserInterface::AddToWatched(const Film& film)
{
	//set the string that is actually stored in the database with the id of the current film 
	user.SetWatched(user.GetWatchedMovies() + " " + std::to_string(film.GetId()));
	storage.m_db.update(user);
	//also, modify in the vector of shared pointers that this film is part of the user's watched movies
	const Film* filmPointer = &film;
	std::shared_ptr<const Film> filmPtr(filmPointer);
	user.AddToWatchedVector(filmPtr);
}

//void UserInterface::AddToFavourites(const Film& film)
//{
//    user.SetFavourites(user.GetFavouriteMovies() + " " + std::to_string(film.GetId()));
//    storage.m_db.update(user);
//    user.AddToFavouritesVector(film);
//}

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
		std::cout << "\t\t|                  4. Your profile                   |\n";
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
