#pragma once
#include <string>
#include<sqlite_orm/sqlite_orm.h>
#include "User.h"
#include "Film.h"

using namespace sqlite_orm;

const std::string dbFile = "App_db.sqlite";


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
			make_column("country", &User::SetCountry, &User::GetCountry)
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
			make_column("description", &Film::SetDescription, &Film::GetDescription)
			make_column("rating", &Film::SetRating, &Film::GetRating),
			make_column("number_of_reviews", &Film::SetNumberOfReviews, &Film::GetNumberOfReviews)
		)
	);
}

using Storage = decltype(createStorage(""));

class AppStorage
{
public:
	//bool Initialize(const std::string& csvDataFilePath);
	void AddUser(User& user);
	void AddFilm(Film& film);
	void SearchFilmByTitle(std::string title);
	static std::vector<std::string> split(const std::string& str, const std::string& delim);

private:
	//void PopulateStorage(const std::string& dataFilePath);

public:
	Storage m_db = createStorage(dbFile);
};
