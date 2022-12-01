#include "Storage.h"

void AppStorage::AddUser(User& user)
{
	m_db.sync_schema();
	auto initUserCount = m_db.count<User>();
	
	auto insertedId = m_db.insert(user);
	std::cout << "insertedId = " << insertedId << std::endl;
	auto initUserCount2 = m_db.count<User>();
}

void AppStorage::AddFilm(Film& film)
{
	m_db.sync_schema();
	auto initFilmCount = m_db.count<Film>();

	auto insertedId = m_db.insert(film);
	std::cout << "insertedId = " << insertedId << std::endl;
	auto initFilmCount2 = m_db.count<Film>();
}