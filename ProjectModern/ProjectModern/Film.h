#pragma once
#include <iostream>
#include <vector>


class Film {

public:
	// ---- CONSTRUCTORS ----
	Film(unsigned int id,
		unsigned int numberOfReviews, 
		unsigned int sumOfGrades,
		std::string duration, 
		float rating, 
		std::string type,
		std::string title, 
		std::string ageRange,
		std::string description, 
		uint16_t releaseYear,
		std::string genres,
		std::string cast, 
		std::string director,
		std::string country);

	Film() = default;

	// ---- GETTERS ----
	unsigned int GetId() const;

	std::string GetType() const;

	std::string GetDuration() const;

	unsigned int GetNumberOfReviews() const;

	float GetRating() const;

	std::string GetTitle() const;

	uint16_t GetReleaseYear() const;

	std::string GetGenres() const;

	std::string GetCast() const;

	std::string GetDirector() const;

	std::string GetDescription() const;
	
	std::string GetCountry() const;

	std::string GetAgeRange() const;

	unsigned int GetSumOfGrades() const;

	// ---- SETTERS ----

	void SetId(const unsigned int& id);

	void SetType(const std::string& type);

	void SetDuration(const std::string& duration);

	void SetNumberOfReviews(const unsigned int& numberofreviews);

	void SetRating(const float& rating);

	void SetTitle(const std::string& title);

	void SetReleaseYear(const uint16_t& releaseYear);

	void SetGenres(const std::string& genres);

	void SetCast(const std::string& cast);

	void SetDirector(const std::string& director);

	void SetDescription(const std::string& description);

	void SetCountry(const std::string& country);

	void SetAgeRange(const std::string& ageRange);

	void SetSumOfGrades(const unsigned int& sumOfGrades);


	// ---- MEMBERS ----
private:
	unsigned int m_id;
	unsigned int m_numberOfReviews;
	unsigned int m_sumOfGrades;


	float m_rating;
	
	std::string m_type; //should be changed to bool once we know we are doing with the set functions
	std::string m_title;
	std::string m_ageRange;
	std::string m_description;
	std::string m_duration;

	uint16_t m_releaseYear;

	std::string m_genres;
	std::string m_cast;
	std::string m_director;
	std::string m_country;

	//add getter setter for description, country, ageRange
	//add description to constructor
	//decomment make_table
};