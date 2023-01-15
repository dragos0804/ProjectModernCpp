#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>
#include <conio.h>
#include <Windows.h>
#include "User.h"
#include "Film.h"

using namespace sqlite_orm;

const std::string dbFile = "MovieApp_db.sqlite";


inline auto createStorage(const std::string& filename)
{
	return make_storage(
		filename,
		make_table(
			"Users",
			make_column("id", &User::SetID, &User::GetID, autoincrement(), primary_key()),
			make_column("name", &User::SetName, &User::GetName),
			make_column("username", &User::SetUsername, &User::GetUsername),
			make_column("dateOfBirth", &User::SetDateOfBirth, &User::GetDateOfBirth),
			make_column("email", &User::SetEmail, &User::GetEmail),
			make_column("password", &User::SetPassword, &User::GetPassword),
			make_column("country", &User::SetCountry, &User::GetCountry),
			make_column("watched", &User::SetWatched, &User::GetWatchedMovies),
			make_column("favourites", &User::SetFavourites, &User::GetFavouriteMovies)
		),
		make_table(
			"Films",
			make_column("id", &Film::SetId, &Film::GetId, autoincrement(), primary_key()), 
			make_column("type", &Film::SetType, &Film::GetType), 
			make_column("title", &Film::SetTitle, &Film::GetTitle), 
			make_column("director", &Film::SetDirector, &Film::GetDirector), 
			make_column("cast", &Film::SetCast, &Film::GetCast),
			make_column("country", &Film::SetCountry, &Film::GetCountry),
			make_column("release_year", &Film::SetReleaseYear, &Film::GetReleaseYear), 
			make_column("age_range", &Film::SetAgeRange, &Film::GetAgeRange),
			make_column("duration", &Film::SetDuration, &Film::GetDuration),
			make_column("genre", &Film::SetGenres, &Film::GetGenres),
			make_column("description", &Film::SetDescription, &Film::GetDescription),
			make_column("rating", &Film::SetRating, &Film::GetRating),
			make_column("number_of_reviews", &Film::SetNumberOfReviews, &Film::GetNumberOfReviews),
			make_column("sum_of_grades", &Film::SetSumOfGrades, &Film::GetSumOfGrades)
		)
	);
}

using Storage = decltype(createStorage(""));

class AppStorage
{
public:
	void AddUser(User& user);
	void AddFilm(Film& film);
	std::vector<Film> SearchFilmByTitle(const std::string& title);
	Film SelectFilmFromCurrentList(const std::vector<Film>& listOfFilms, int& currentNumber);
	std::vector<Film> GetFilmsByCategoryAndAgeRange(const std::vector<std::string>& categories, const std::string& ageRange);
	std::vector<Film> GetFilmsByCategoryAndAgeRangeOrderedByRating(const std::vector<std::string>& categories, const std::string& ageRange);
	std::vector<Film> GetFilmsByCategoryAndAgeRangeAndYear(const std::vector<std::string>& categories, const std::string& ageRange, const int& releaseYear);
	
	static std::vector<std::string> split(const std::string& str, const std::string& delim);

public:
	Storage m_db = createStorage(dbFile);
};
