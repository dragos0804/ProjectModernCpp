#include "Storage.h"

std::vector<std::string> AppStorage::split(const std::string& str, const std::string& delim)
{
	std::vector<std::string> result;
	size_t startIndex = 0;

	for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, startIndex))
	{
		result.emplace_back(str.begin() + startIndex, str.begin() + found);
		startIndex = found + delim.size();
	}
	if (startIndex != str.size())
		result.emplace_back(str.begin() + startIndex, str.end());
	return result;
}

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

std::vector<Film> AppStorage::SearchFilmByTitle(const std::string& title)
{
	auto whereTitleLike = m_db.get_all<Film>(where(like(&Film::GetTitle, "%" + title + "%")));
	return whereTitleLike;

}

Film AppStorage::SelectFilmFromCurrentList(const std::vector<Film>& listOfFilms, int& currentNumber)
{
	Film selectedFilm;
	int contor = 0;
	for (const auto& film : listOfFilms)
	{
		contor++;
		if (contor == currentNumber)
			selectedFilm = film;
	}
	return selectedFilm;
}

std::vector<Film> AppStorage::GetFilmsByCategory(const std::vector<std::string>& categories, const std::string& ageRange)
{
	using namespace sqlite_orm;
	std::vector <Film> films;
	for (const auto& category : categories)
	{
		auto rows = m_db.select(sqlite_orm::columns
		(
			&Film::GetId,
			&Film::GetNumberOfReviews,
			&Film::GetSumOfGrades,
			&Film::GetDuration,
			&Film::GetRating,
			&Film::GetType,
			&Film::GetTitle,
			&Film::GetAgeRange,
			&Film::GetDescription,
			&Film::GetReleaseYear,
			&Film::GetGenres,
			&Film::GetCast,
			&Film::GetDirector,
			&Film::GetCountry
		),
			sqlite_orm::where(like(&Film::GetGenres, "%" + category + "%") and c(&Film::GetAgeRange) == ageRange));

		for (auto& row : rows)
		{
			Film film(
				std::get<0>(row),
				std::get<1>(row),
				std::get<2>(row),
				std::get<3>(row),
				std::get<4>(row),
				std::get<5>(row),
				std::get<6>(row),
				std::get<7>(row),
				std::get<8>(row),
				std::get<9>(row),
				std::get<10>(row),
				std::get<11>(row),
				std::get<12>(row),
				std::get<13>(row)
			);
			films.emplace_back(film);
		}
	}
	return films;

}
