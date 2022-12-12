#include "pch.h"
////#include "../ProjectModern/User.h"
//
//
//class UserTest : public ::testing::Test
//{
//public:
//	void SetUp() override
//	{
//		u1 = new User(1, "Alex", "Alex036", "31-05-2002", "chelmus.alexanther@gmail.com", "123456", "Romania");
//		u2 = new User(2, "Andrei", "Witcher66", "27-04-2017", "andreiwitcher@yahoo.ro", "AAAAAAA", "Deutschland");
//	}
//
//	void TearDown() override
//	{
//		delete u1;
//		delete u2;
//	}
//
//protected:
//	User* u1 = nullptr, * u2 = nullptr;
//};
//
//TEST_F(UserTest, CheckNameGetter)
//{
//	EXPECT_EQ(u1->GetName(), "Alex");
//	EXPECT_EQ(u2->GetName(), "Andrei");
//}
//
//TEST_F(UserTest, CheckUsernameGetter)
//{
//	EXPECT_EQ(u1->GetUsername(), "Alex036");
//	EXPECT_EQ(u2->GetUsername(), "Witcher66");
//}
//
//TEST_F(UserTest, CheckDoBGetter)
//{
//	EXPECT_EQ(u1->GetDateOfBirth(), "31-05-2002");
//	EXPECT_EQ(u2->GetDateOfBirth(), "27-04-2017");
//}
//
//TEST_F(UserTest, CheckEmailGetter)
//{
//	EXPECT_EQ(u1->GetDateOfBirth(), "chelmus.alexanther@gmail.com");
//	EXPECT_EQ(u2->GetDateOfBirth(), "andreiwitcher@yahoo.ro");
//}
//
//TEST_F(UserTest, CheckPasswordGetter)
//{
//	EXPECT_EQ(u1->GetDateOfBirth(), "123456");
//	EXPECT_EQ(u2->GetDateOfBirth(), "AAAAAAA");
//}
//
//TEST_F(UserTest, CheckCountryGetter)
//{
//	EXPECT_EQ(u1->GetCountry(), "Romania");
//	EXPECT_EQ(u2->GetCountry(), "Deutschland");
//}