#include "pch.h"
#include "User.h"

class UserTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		u1 = new User(1, "Alex", "Alex036", "31-05-2002", "chelmus.alexanther@gmail.com", "123456", "Romania", "235,245,289", "289");
		u2 = new User(2, "Andrei", "Witcher66", "27-04-2017", "andreiwitcher@yahoo.ro", "AAAAAAA", "Deutschland", "1000,6589", "2,36,753");
		u3 = new User();
	}

	void TearDown() override
	{
		delete u1;
		delete u2;
		delete u3;
	}

protected:
	User* u1 = nullptr, * u2 = nullptr, *u3;
};

TEST_F(UserTest, CheckNameGetter)
{
	EXPECT_EQ(u1->GetName(), "Alex");
	EXPECT_EQ(u2->GetName(), "Andrei");
}

TEST_F(UserTest, CheckNameSetter)
{
	u3->SetName("Ionut");
	EXPECT_EQ(u3->GetName(), "Ionut");
}

TEST_F(UserTest, CheckUsernameGetter)
{
	EXPECT_EQ(u1->GetUsername(), "Alex036");
	EXPECT_EQ(u2->GetUsername(), "Witcher66");
}

TEST_F(UserTest, CheckWatchedMoviesGetter)
{
	EXPECT_EQ(u1->GetWatchedMovies(), "235,245,289");
	EXPECT_EQ(u2->GetWatchedMovies(), "1000,6589");
}

TEST_F(UserTest, CheckFavouritesMoviesGetter)
{
	EXPECT_EQ(u1->GetFavouriteMovies(), "289");
	EXPECT_EQ(u2->GetFavouriteMovies(), "2,36,753");
}

//Setter tests
TEST_F(UserTest, CheckUsernameSetter)
{
	u3->SetUsername("Ion34Ionut");
	EXPECT_EQ(u3->GetUsername(), "Ion34Ionut");
}

TEST_F(UserTest, CheckDoBGetter)
{
	EXPECT_EQ(u1->GetDateOfBirth(), "31-05-2002");
	EXPECT_EQ(u2->GetDateOfBirth(), "27-04-2017");
}

TEST_F(UserTest, CheckDoBSetter)
{
	u3->SetDateOfBirth("25-03-1995");
	EXPECT_EQ(u3->GetDateOfBirth(), "25-03-1995");
}

TEST_F(UserTest, CheckPasswordGetter)
{
	EXPECT_EQ(u1->GetPassword(), "123456");
	EXPECT_EQ(u2->GetPassword(), "AAAAAAA");
}

TEST_F(UserTest, CheckPasswordSetter)
{
	u3->SetPassword("AbraCadabra222");
	EXPECT_EQ(u3->GetPassword(), "AbraCadabra222");
}

TEST_F(UserTest, CheckCountryGetter)
{
	EXPECT_EQ(u1->GetCountry(), "Romania");
	EXPECT_EQ(u2->GetCountry(), "Deutschland");
}

TEST_F(UserTest, CheckCountrySetter)
{
	u3->SetCountry("Italy");
	EXPECT_EQ(u3->GetCountry(), "Italy");
}