#include "pch.h"
#include "../ProjectModern/User.h"


class UserTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		u1 = new User(1, "Alex", "Alex036", "31-05-2002", "chelmus.alexanther@gmail.com", "123456", "Romania");
		u2 = new User(2, "Andrei", "Witcher66", "27-04-2017", "andreiwitcher@yahoo.ro", "AAAAAAA", "Deutschland");
	}

	void TearDown() override
	{
		delete u1;
		delete u2;
	}

protected:
	User* u1 = nullptr, * u2 = nullptr;
};