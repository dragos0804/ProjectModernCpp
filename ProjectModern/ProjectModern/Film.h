#pragma once
#include <iostream>
#include <vector>

class Film {

// -- ENUMS --
public:
	// ar trebui sa fie legat de string cumva? 
	//din cate stiu uint8_t ul de aici semnaleaza ca nu o sa am valori mai mult decat 2^8-1
	enum class Genre : uint8_t{
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
		family 
	};

	enum class Actors {
		// TODO: implement
	};

	enum class Producers {
		// TODO: implement
	};

	enum class Studios {
		// TODO: implement
	};

// ---- FUNCTIONS ----
public:
	// constructor???

	const void getFilm(const std::string name) const; // getter si dupa alti parametrii? cum?

	const unsigned int getLength() const;

	void setFilm(const std::string name, std::vector<Genre> genres); // setam un film si dupa genuri, right?

	void sortBy(std::vector<Film> films);

// ---- MEMBERS ----
private:
	unsigned int m_id;
	std::string m_name;
	Genre m_genre : 1;
	std::string m_dateOfRelease; // posibila schimbare in alt tip in functie de utilitati
	Actors m_actors;
	Producers m_producers;
	Studios m_studios;
	float m_rating;
	unsigned int m_numberOfReviews;
	unsigned int m_duration; // setter using ceil for seconds 

	// ---- EXTRA ----
	// 
	// sequel/ prequel?
	// age restriction?
	// 
	// -----------
};