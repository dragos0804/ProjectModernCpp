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

void AppStorage::SelectFilmFromCurrentList(std::string title, int currentNumber)
{
	int current = 1;

	auto whereTitleLike = m_db.select(columns(&Film::GetId, &Film::GetTitle, &Film::GetType, &Film::GetDuration, &Film::GetAgeRange), where(like(&Film::GetTitle, "%" + title + "%")));
	for (auto& i : whereTitleLike)
	{
		if (current == currentNumber) {
			auto& id = std::get<0>(i);
			auto& title = std::get<1>(i);
			auto& type = std::get<2>(i);
			auto& duration = std::get<3>(i);
			auto& ageRange = std::get<4>(i);

			std::cout << "\t\t" << title << "\t" << type << "\t" << duration << "\t" << ageRange << std::endl;
			break;
		}

		current++;
	}
}
