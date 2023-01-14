#include "UserInterface.h"
#include "../Validation/Validate.h"

void UserInterface::StartUpMenu()
{
	m_option = 1;
	PrintMenu();

	m_option = _getch();

	switch (m_option) {
		// 1 == 49 in ASCII table
	case PRESS_1:
		RegisterMenu();
		break;
	case PRESS_2:
		LoginMenu();
		break;
		// ESC KEY
	case PRESS_ESC:
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

	m_option = _getch();

	switch (m_option) {
	case PRESS_BACKSPACE:
		StartUpMenu();
		break;
		// 1 == 49 in ASCII table
	case PRESS_1:
		RegisterMenu();
		break;
	case PRESS_2:
		LoginMenu();
		break;
		// ESC KEY
	case PRESS_ESC:
		exit(0);
		// any other key will not change anything
	default:
		Register r;
		r.CreateUser(m_storage);
		LoginMenu();
		break;
	}
}

void UserInterface::LoginMenu()
{
	PrintMenu();

	std::cout << "\t\tLog into your account" << std::endl;
	std::cout << "\t\tPress BACKSPACE to go back or any other key to continue" << std::endl;

	m_option = _getch();

	switch (m_option) {
	case PRESS_BACKSPACE:
		StartUpMenu();
		break;
		// 1 == 49 in ASCII table
	case PRESS_1:
		RegisterMenu();
		break;
	case PRESS_2:
		LoginMenu();
		break;
		// ESC KEY
	case PRESS_ESC:
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
		bool verifiedLoginStatus = l.VerifyMatchUserToPassword(m_storage, username, password, m_user);

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
	m_option = 2;
	PrintMenu();

	m_option = _getch();

	switch (m_option) {
	case PRESS_1:
		SettingsMenu();
		break;
	case PRESS_2:
		//switch user
		LoginMenu();
		break;
	case PRESS_3:
		SearchForAFilm();
		break;
	case PRESS_4:
		PrintUserProfile();
	case PRESS_ESC:
		exit(0);
	default:
		LoggedInMenu();
		break;
	}
}

void UserInterface::SettingsMenu()
{
	m_option = 3;
	PrintMenu();

	std::cout << "\t\tPress BACKSPACE to go back or choose an option" << std::endl;

	m_option = _getch();

	switch (m_option) {
	case PRESS_BACKSPACE:
		LoggedInMenu();
		break;
	case PRESS_1:
		ChangeUsername();
		break;
	case PRESS_2:
		ChangePassword();
		break;
	case PRESS_ESC:
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

	int contor = 0;
	std::vector<Film> searchedFilms = m_storage.SearchFilmByTitle(title);
	while (searchedFilms.size() == 0)
	{
		std::cout << "\t\tSorry, the movie you're trying to reach can't be found!" << std::endl;
		std::cout << "\t\tSearch: ";
		std::getline(std::cin, title);

		while (title.empty())
		{
			std::cout << "\t\t";
			std::getline(std::cin, title);
		}
		searchedFilms = m_storage.SearchFilmByTitle(title);
	}

	for (const auto& film : searchedFilms)
	{
		contor++;
		std::cout << "\t\t" << contor << ". " << film.GetTitle() << std::endl;
	}

	std::cout << std::endl;
	
	std::cout << std::endl;
	std::vector <Film> SimilarFilms = ManageLoopSimilarity(searchedFilms);

movie_select:

	switch (m_option) {
	case PRESS_BACKSPACE:
		LoggedInMenu();
		break;
	case PRESS_1:
	{
		RateThisFilm();
		goto movie_select;
		break;
	}
	case PRESS_2:
		AddToWatched(m_film);
		goto movie_select;
		break;
	case PRESS_3:
		AddToFavourites(m_film);
		goto movie_select;
		break;
	case PRESS_4:
	{
		SimilarFilms = ManageLoopSimilarity(SimilarFilms);
		goto movie_select;
	}
	case PRESS_ESC:
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

	m_user.SetPassword(password);

	Register r;
	if (r.PasswordValidation(password)) {
		m_storage.m_db.update(m_user);
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

	m_user.SetUsername(username);

	Register r;
	if (r.UsernameValidation(username, m_storage)) {
		std::cout << "\t\tUsername Changed Succesfully!";
		m_storage.m_db.update(m_user);
		Sleep(2500);
	}
	else {
		std::cout << "\t\tUsername Already Taken / Username Invalid. Try again.";
		Sleep(2500);
	}

	LoggedInMenu();
}

void UserInterface::PrintFilmPage()
{
	system("CLS");
	std::cout << "\t\t*******************************************************\n";
	std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
	std::cout << "\t\t*******************************************************\n\n";

	std::cout << "\t\t" << m_film.GetTitle() << std::endl;
	std::cout << "\t\t+----------------------------------------------------+\n";

	std::cout << "\t\t" << "Type: " << m_film.GetType() << std::endl;
	std::cout << "\t\t" << "Duration: " << m_film.GetDuration() << std::endl;
	std::cout << "\t\t" << "Age Restriction: " << m_film.GetAgeRange() << std::endl;
	std::cout << "\t\t" << "Release Year: " << m_film.GetReleaseYear() << std::endl;
	std::cout << "\t\t" << "Cast: " << m_film.GetCast() << std::endl;
	std::cout << "\t\t" << "Genres: " << m_film.GetGenres() << std::endl;
	std::cout << "\t\t" << "Rating: " << m_film.GetRating() << " (" << m_film.GetNumberOfReviews() << " reviews) " << std::endl;
	std::cout << "\t\t" << "Description: " << m_film.GetDescription() << "\n\n";
}

void UserInterface::PrintUserProfile()
{
	PrintMenu();
	std::cout << "\t\t" << "Name: " << m_user.GetName() << std::endl;
	std::cout << "\t\t" << "Username: " << m_user.GetUsername() << std::endl;
	std::cout << "\t\t" << "Date of birth: " << m_user.GetDateOfBirth() << std::endl;
	std::cout << "\t\t" << "Country: " << m_user.GetCountry() << std::endl;
	std::cout << "\t\t" << "Email: " << m_user.GetEmail() << std::endl;
	std::cout << "\t\t" << "Watched movies: " << std::endl;
	std::vector<std::string> watchedMovies = m_storage.split(m_user.GetWatchedMovies(), " ");;
	for (int i = 1; i < watchedMovies.size(); i++)
	{
		int idWatchedFilm = std::stoi(watchedMovies[i]);
		auto film = m_storage.m_db.get<Film>(idWatchedFilm);
		std::cout << "\t\t\t" << film.GetTitle() << std::endl;
	}
	std::cout << "\t\t" << "Favourite movies: " << std::endl;
	std::vector<std::string> favouriteMovies = m_storage.split(m_user.GetFavouriteMovies(), " ");;
	for (int i = 1; i < favouriteMovies.size(); i++)
	{
		int idFavouriteFilm = std::stoi(favouriteMovies[i]);
		auto film = m_storage.m_db.get<Film>(idFavouriteFilm);
		std::cout << "\t\t\t" << film.GetTitle() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "\t\tPress BACKSPACE to go back" << std::endl;

	m_option = _getch();

	switch (m_option) {
	case PRESS_BACKSPACE:
		LoggedInMenu();
		break;
	case PRESS_ESC:
		exit(0);
	default:
		LoggedInMenu();
		break;
	}
}

void UserInterface::RateThisFilm()
{
	int grade;
	std::cout << "\t\tLeave a grade between 1 and 10 for this film: ";
	std::cin >> grade;
	while (!(grade > 0 && grade < 11))
	{
		std::cout << "\t\tInvalid range. Leave a grade between 1 and 10, please: ";
		std::cin >> grade;
	}
	m_user.leaveReview(m_film, grade);
	std::cout << "\t\tThank you! Rating after your review: " << m_film.GetRating() << std::endl;
	m_storage.m_db.update(m_film);
	std::cout << "\t\tPress BACKSPACE to go back" << std::endl;
	m_option = _getch();
}

void UserInterface::AddToWatched(const Film& film)
{
	//set the string that is actually stored in the database with the id of the current film 

	m_user.SetWatched(m_user.GetWatchedMovies() + " " + std::to_string(film.GetId()));
	m_storage.m_db.update(m_user);
	//also, modify in the vector of shared pointers that this film is part of the user's watched movies
	std::shared_ptr<const Film> filmPtr = std::make_shared<Film>(film);

	std::vector<std::string> watchedMovies = m_storage.split(m_user.GetWatchedMovies(), " ");
	if (std::find(watchedMovies.begin(), watchedMovies.end(), std::to_string(film.GetId())) == watchedMovies.end())
	{
		m_user.AddToWatchedVector(filmPtr);
		std::cout << std::endl << std::endl;
		std::cout << "\t\tSuccessfully added the movie to your watched list" << std::endl;
	}
	else
	{
		std::cout << "\t\tThis movie is already in your watched list" << std::endl;
	}

	m_option = _getch();
}

void UserInterface::AddToFavourites(const Film& film)
{
    m_user.SetFavourites(m_user.GetFavouriteMovies() + " " + std::to_string(film.GetId()));
    m_storage.m_db.update(m_user);
	std::shared_ptr<const Film> filmPtr = std::make_shared<Film>(film);

	std::vector<std::string> favouritesMovies = m_storage.split(m_user.GetFavouriteMovies(), " ");
	if (std::find(favouritesMovies.begin(), favouritesMovies.end(), std::to_string(film.GetId())) == favouritesMovies.end())
	{
		m_user.AddToFavouritesVector(filmPtr);
		std::cout << std::endl << std::endl;
		std::cout << "\t\tSuccessfully added the movie to your favourites list" << std::endl;
	}
	else
	{
		std::cout << "\t\tThis movie is already in your favourites list" << std::endl;
	}

	m_option = _getch();
}

std::vector<Film> UserInterface::ManageLoopSimilarity(const std::vector<Film>& properVectorOfFilms)
{
	int movieNumber;
	std::cout << "\t\tSelect a movie: ";
	std::cin >> movieNumber;

	while (movieNumber <= 0 || movieNumber > properVectorOfFilms.size())
	{
		std::cout << "\t\t" << movieNumber << " is an invalid input! Please select from the list of movies available!";
		std::cout << std::endl;
		std::cout << "\t\tSelect a movie: ";
		std::cin >> movieNumber;
	}

	m_film = m_storage.SelectFilmFromCurrentList(properVectorOfFilms, movieNumber);
	PrintFilmPage();

	m_option = -1;

	std::cout << "\t\t------------------------------------------------------\n";
	std::cout << "\t\tSimilar to this:\n";


	std::vector<std::string> vectorOfCategoriesForFilm = AppStorage::split(m_film.GetGenres(), ", ");

	std::vector<Film> films = m_storage.GetFilmsByCategory(vectorOfCategoriesForFilm, m_film.GetAgeRange());

	KMeans kmeans(vectorOfCategoriesForFilm.size());
	kmeans.Run(films);

	std::vector<Film> similarFilms = kmeans.GetSimilarFilms(m_film);
	int countMax10FilmsPerRecommendation = 1;
	for (const auto& simFilm : similarFilms)
	{
		if (countMax10FilmsPerRecommendation == 11)
			break;
		std::cout << "\t\t\t" << countMax10FilmsPerRecommendation << ". " << simFilm.GetTitle() << std::endl;
		std::cout << "\t\t\t\tAge range: " << simFilm.GetAgeRange() << std::endl;
		std::cout << "\t\t\t\tGenres: " << simFilm.GetGenres() << std::endl;
		countMax10FilmsPerRecommendation++;
	}

	std::cout << "\t\t------------------------------------------------------\n";

	std::cout << "\t\t1. Leave review." << std::endl;
	std::cout << "\t\t2. Add to watched." << std::endl;
	std::cout << "\t\t3. Add to favourites." << std::endl;
	std::cout << "\t\t4. Select a movie from recomanded ones." << std::endl;
	std::cout << std::endl;

	std::cout << "\t\tPress BACKSPACE to go back" << std::endl;

	m_option = _getch();

	return similarFilms;
}

void UserInterface::PrintMenu()
{
	system("CLS");
	std::cout << "\t\t*******************************************************\n";
	std::cout << "\t\t *         MOVIE RECOMMENDATION APPLICATION          * \n";
	std::cout << "\t\t*******************************************************\n\n";

	switch (m_option)
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
