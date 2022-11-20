#pragma once
#include <iostream>
#include <list>

class Film {

	// ---- ENUMS ----
public:
	enum class Genre : uint8_t {
		action,
		adventure,
		comedy,
		drama,
		fantasy,
		horror,
		musicals,
		mystery,
		romance,
		science_fiction,
		sports,
		thriller,
		western,
		family,
		none
	};

	enum class Actor {
		A1,
		A2
		// collected from database
	};

	enum class Producer {
		P1,
		P2
		// collected from database
	};

	enum class Studios {
		// collected from database
	};

	// ---- METHODS ----
public:
	// ---- CONSTRUCTORS ----
	Film(unsigned int id, unsigned int numberOfReviews, unsigned int duration, float rating, std::string name, std::string releaseDate,
		std::list<Genre> genres, std::list<Actor> actors, std::list<Producer> producers);

	// ---- GETTERS ----
	unsigned int GetId() const;

	unsigned int GetDuration() const;

	unsigned int GetNumberOfReviews() const;

	float GetRating() const;

	std::string GetName() const;

	std::string GetReleaseDate() const;

	std::list<Genre> GetGenres() const;

	std::list<Actor> GetActors() const;

	std::list<Producer> GetProducers() const;

	// ---- SETTERS ----

	void SetNumberOfReviews(const unsigned int numberOfReviews);

	void SetRating(float rating);

	void SetName(const std::string name);

	void SetGenres(const std::list<Genre> genres);

	void SetActors(const std::list<Actor> actors);

	void SetProducers(const std::list<Producer> producers);

	// ---- MEMBERS ----
private:
	unsigned int m_id;
	unsigned int m_duration;
	unsigned int m_numberOfReviews;

	float m_rating;

	std::string m_name;
	std::string m_releaseDate;

	std::list<Genre> m_genres;
	std::list<Actor> m_actors;
	std::list<Producer> m_producers;

};