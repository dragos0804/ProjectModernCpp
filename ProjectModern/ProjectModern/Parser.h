#pragma once

#include "Film.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


struct Movie {
public:
	Movie(
		std::string type, std::string title, std::string director, std::string cast, std::string country, std::string data_added, int release_year,
		std::string rating, std::string duration, std::string listed_in, std::string description)
		: m_type(type)
		, m_title(title)
		, m_director(director)
		, m_cast(cast)
		, m_country(country)
		, m_data_added(data_added)
		, m_release_year(release_year)
		, m_rating(rating)
		, m_duration(duration)
		, m_listed_in(listed_in)
		, m_description(description)
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Movie& movie)
	{
		out << movie.m_type << "\n" << movie.m_title << "\n" << movie.m_director << "\n" << movie.m_cast << "\n" << movie.m_country << "\n" << movie.m_data_added
			<< "\n" << movie.m_release_year << "\n" << movie.m_rating << "\n" << movie.m_duration << "\n" << movie.m_listed_in << "\n" << movie.m_description << "\n";

		return out;
	}

	std::string m_type;
	std::string m_title;
	std::string m_director;
	std::string m_cast;
	std::string m_country;
	std::string m_data_added;
	int m_release_year;
	std::string m_rating;
	std::string m_duration;
	std::string m_listed_in;
	std::string m_description;

};

void displayMovies(const std::vector<Movie>& movies) 
{
	std::ofstream fout("filme.out");

	for (auto movie : movies) {
		fout << movie;
	}
}

void ParseMethod()
{
	std::ifstream inputFile;
	inputFile.open("netflix_titles.csv");
	std::ofstream fout("filme.out");
	std::string line = "";

	std::vector<Movie> movies;

	while (std::getline(inputFile, line))
	{
		std::stringstream inputString(line);

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

		std::getline(inputString, type, ',');
		std::getline(inputString, title, ',');
		std::getline(inputString, director, ',');
		std::getline(inputString, cast, ',');
		std::getline(inputString, country, ',');
		std::getline(inputString, date_added, ',');
		std::getline(inputString, aux, ',');
		release_year = atoi(aux.c_str());
		std::getline(inputString, rating, ',');
		std::getline(inputString, duration, ',');
		std::getline(inputString, listed_in, ',');
		std::getline(inputString, description, ',');

		Movie movie(type, title, director, cast, country, date_added, release_year,
			rating, duration, listed_in, description);

		movies.push_back(movie);
		line = "";

	}


	displayMovies(movies);
}