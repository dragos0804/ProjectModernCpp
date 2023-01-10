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

void AppStorage::SearchFilmByTitle(std::string title)
{
	/*auto whereTitleLike = m_db.select(columns(&Film::GetId, &Film::GetTitle, &Film::GetType, &Film::GetDuration, &Film::GetAgeRange), where(like(&Film::GetTitle, "%"+title+"%")));
	for (auto& i : whereTitleLike)
	{
		auto& id = std::get<0>(i);
		auto& title = std::get<1>(i);
		auto& type = std::get<2>(i);
		auto& duration = std::get<3>(i);
		auto& ageRange = std::get<4>(i);
		
		std::cout << "\t" << id << "\t" << type << "\t" << duration << "\t" << ageRange << "\t" << title << std::endl;
	}*/

	int current = 1;

	auto whereTitleLike = m_db.select(columns(&Film::GetTitle), where(like(&Film::GetTitle, "%" + title + "%")));
	for (auto& i : whereTitleLike)
	{
		auto& title = std::get<0>(i);

		std::cout << "\t\t" << current << ".  " << "\t" << title << std::endl;
		current++;
	}
}

Film AppStorage::SelectFilmFromCurrentList(std::string title, int currentNumber)
{
	int current = 1;
	int idFilmSelectat = 0;
	auto whereTitleLike = m_db.select(columns(&Film::GetId, &Film::GetTitle, &Film::GetType,
		&Film::GetDuration, &Film::GetAgeRange, &Film::GetCast, &Film::GetGenres,
		&Film::GetRating, &Film::GetNumberOfReviews, &Film::GetDescription),
		where(like(&Film::GetTitle, "%" + title + "%")));
	for (auto& i : whereTitleLike)
	{
		if (current == currentNumber) {
			auto& idFilm = std::get<0>(i);
			auto& title = std::get<1>(i);
			auto& type = std::get<2>(i);
			auto& duration = std::get<3>(i);
			auto& ageRange = std::get<4>(i);
			auto& cast = std::get<5>(i);
			auto& genres = std::get<6>(i);
			auto& rating = std::get<7>(i);
			auto& reviews = std::get<8>(i);
			auto& description = std::get<9>(i);

			std::cout << "\t\t" << title << std::endl;
			std::cout << "\t\t+----------------------------------------------------+\n";

			std::cout << "\t\t" << "Type: " << type << std::endl;
			std::cout << "\t\t" << "Duration: " << duration << std::endl;
			std::cout << "\t\t" << "Age Restriction: " << ageRange << std::endl;
			std::cout << "\t\t" << "Cast: " << cast << std::endl;
			std::cout << "\t\t" << "Genres: " << genres << std::endl;
			std::cout << "\t\t" << "Rating: " << rating << " (" << reviews << " reviews) " << std::endl;
			std::cout << "\t\t" << "Description: " << description << "\n\n";

			idFilmSelectat = idFilm;

			break;

		}

		current++;
	}

	Film filmSelectat = m_db.get<Film>(idFilmSelectat);
	return filmSelectat;
}
