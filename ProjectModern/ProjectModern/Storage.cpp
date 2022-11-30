#include "Storage.h"

void AppStorage::AddUser(User& user)
{
	m_db.sync_schema();
	auto initBooksCount = m_db.count<User>();
	
	auto insertedId = m_db.insert(user);
	std::cout << "insertedId = " << insertedId << std::endl;
	auto initBooksCount2 = m_db.count<User>();//  insertedId = 8
	//user.id = insertedId;
}