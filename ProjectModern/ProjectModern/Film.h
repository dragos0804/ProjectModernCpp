#pragma once
#include <iostream>
#include <vector>


class Film {

public:
	// ---- CONSTRUCTORS ----
	Film(unsigned int id,
		unsigned int numberOfReviews, 
		unsigned int duration, 
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

	// ---- GETTERS ----
	unsigned int GetId() const;

	std::string GetType() const;

	unsigned int GetDuration() const;

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

	// ---- SETTERS ----

	void SetId(const unsigned int id);

	void SetType(const std::string type);

	void SetDuration(const unsigned int duration);

	void SetNumberOfReviews(const unsigned int numberOfReviews);

	void SetRating(float rating);

	void SetTitle(const std::string title);

	void SetReleaseYear(const uint16_t releaseYear);

	void SetGenres(const std::string genres);

	void SetCast(const std::string cast);

	void SetDirector(const std::string director);

	void SetDescription(const std::string description);

	void SetCountry(const std::string country);

	void SetAgeRange(const std::string ageRange);

	// ---- MEMBERS ----
private:
	unsigned int m_id;
	unsigned int m_duration;
	unsigned int m_numberOfReviews;

	float m_rating;
	
	std::string m_type; //should be changed to bool once we know we are doing with the set functions
	std::string m_title;
	std::string m_ageRange;
	std::string m_description;

	uint16_t m_releaseYear;

	std::string m_genres;
	std::string m_cast;
	std::string m_director;
	std::string m_country;

	//add getter setter for description, country, ageRange
	//add description to constructor
	//decomment make_table
};