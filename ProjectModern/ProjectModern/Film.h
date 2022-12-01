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
		std::vector<std::string> genres,
		std::vector<std::string> cast, 
		std::vector<std::string> director,
		std::vector<std::string> country);

	// ---- GETTERS ----
	unsigned int GetId() const;

	std::string GetType() const;

	unsigned int GetDuration() const;

	unsigned int GetNumberOfReviews() const;

	float GetRating() const;

	std::string GetTitle() const;

	uint16_t GetReleaseYear() const;

	std::vector<std::string> GetGenres() const;

	std::vector<std::string> GetCast() const;

	std::vector<std::string> GetDirector() const;

	std::string GetDescription() const;
	
	std::vector<std::string> GetCountry() const;

	std::string GetAgeRange() const;

	// ---- SETTERS ----

	void SetId(const unsigned int id);

	void SetType(const std::string type);

	void SetDuration(const unsigned int duration);

	void SetNumberOfReviews(const unsigned int numberOfReviews);

	void SetRating(float rating);

	void SetTitle(const std::string title);

	void SetReleaseYear(const uint16_t releaseYear);

	void SetGenres(const std::vector<std::string> genres);

	void SetCast(const std::vector<std::string> cast);

	void SetDirector(const std::vector<std::string> director);

	void SetDescription(const std::string description);

	void SetCountry(const std::vector<std::string> country);

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

	std::vector<std::string> m_genres;
	std::vector<std::string> m_cast;
	std::vector<std::string> m_director;
	std::vector<std::string> m_country;

	//add getter setter for description, country, ageRange
	//add description to constructor
	//decomment make_table
};