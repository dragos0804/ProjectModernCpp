#pragma once
#include <string>
#include<sqlite_orm/sqlite_orm.h>
#include "User.h"

using namespace sqlite_orm;

const std::string dbFile = "App_db.sqlite";


inline auto createStorage(const std::string& filename)
{
	return make_storage(
		filename,
		make_table(
			"Users",
			make_column("id", &User::SetID, &User::GetID, autoincrement(), primary_key()),
			make_column("name", &User::SetName, &User::GetName),
			make_column("username", &User::SetUsername, &User::GetUsername),
			make_column("dateOfBirth", &User::SetDateOfBirth, &User::GetDateOfBirth),
			make_column("email", &User::SetEmail, &User::GetEmail),
			make_column("password", &User::SetPassword, &User::GetPassword),
			make_column("country", &User::SetCountry, &User::GetCountry)
		)
	);
}

using Storage = decltype(createStorage(""));

class AppStorage
{
public:
	bool Initialize(const std::string& csvDataFilePath);

private:
	void PopulateStorage(const std::string& dataFilePath);

private:
	Storage m_db = createStorage(dbFile);
};
