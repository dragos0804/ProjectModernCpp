#pragma once

#include "Film.h"
#include "Storage.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

void ParseMethod()
{
	std::ifstream inputFile;
	inputFile.open("netflix_titles_formatted.csv");
	std::ofstream fout("filme.out");
	std::string line = "";
	AppStorage storage;

	while (std::getline(inputFile, line))
	{
		std::stringstream inputString(line);

		Film film;

		std::string ignoredId;
		std::string type;
		std::string title;
		std::string director;
		std::string cast;
		std::string country;
		std::string date_added;
		int release_year;
		std::string rating;
		std::string duration;
		std::string listed_in;
		std::string description;

		std::string aux;

		std::getline(inputString, ignoredId, ';');

		std::getline(inputString, type, ';');
		if(!type.empty()) film.SetType(type);

		std::getline(inputString, title, ';');
		if(!title.empty()) film.SetTitle(title);

		std::getline(inputString, director, ';');
		if (!director.empty()) film.SetDirector(director);

		std::getline(inputString, cast, ';');
		if (!cast.empty()) film.SetCast(cast);

		std::getline(inputString, country, ';');
		if (!country.empty()) film.SetCountry(country);

		std::getline(inputString, date_added, ';');

		std::getline(inputString, aux, ';');
		release_year = atoi(aux.c_str());
		if (release_year >= 1900 && release_year <= 2050) film.SetReleaseYear(release_year);

		std::getline(inputString, rating, ';');
		if (!rating.empty()) film.SetAgeRange(rating);

		std::getline(inputString, duration, ';');
		if (!duration.empty()) film.SetDuration(duration);

		std::getline(inputString, listed_in, ';');
		if (!listed_in.empty()) film.SetGenres(listed_in);

		std::getline(inputString, description, ';');
		if (!description.empty()) film.SetDescription(description);

		storage.AddFilm(film);

		line = "";
	}

}