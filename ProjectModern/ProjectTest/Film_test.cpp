#include "pch.h"
#include "Film.h"

class FilmTest : public ::testing::Test
{
public:
	void SetUp() override
	{
		f1 = new Film(1, 2, "120min", 3.6, "Movie", "Robin Hood", "PG", "There once was a man who...", 2003,
			"Action", "No ideea", "Spielberg", "USA");
		f2 = new Film(2, 500, "103min", 4.8, "Movie", "Code 4", "TV_MA", "Action movie with nice cars", 2008, 
			"Action, Drama", "Hollywood", "Jason Statam", "England");
		f3 = new Film();
	}

	void TearDown() override
	{
		delete f1;
		delete f2;
		delete f3;
	}

protected:
	Film* f1 = nullptr, * f2 = nullptr, * f3 = nullptr;
};

TEST_F(FilmTest, CheckIdGetter)
{
	EXPECT_EQ(f1->GetId(), 1);
	EXPECT_EQ(f2->GetId(), 2);
}

TEST_F(FilmTest, CheckTypeGetter)
{
	EXPECT_EQ(f1->GetType(), "Movie");
	EXPECT_EQ(f2->GetType(), "Movie");
}

TEST_F(FilmTest, CheckDurationGetter)
{
	EXPECT_EQ(f1->GetDuration(), "120min");
	EXPECT_EQ(f2->GetDuration(), "103min");
}

TEST_F(FilmTest, CheckRatingGetter)
{
	EXPECT_EQ(f1->GetRating(), 3.6f);
	EXPECT_EQ(f2->GetRating(), 4.8f);
}

TEST_F(FilmTest, CheckTitleGetter)
{
	EXPECT_EQ(f1->GetTitle(), "Robin Hood");
	EXPECT_EQ(f2->GetTitle(), "Code 4");
}

TEST_F(FilmTest, CheckReleaseYearGetter)
{
	EXPECT_EQ(f1->GetReleaseYear(), 2003);
	EXPECT_EQ(f2->GetReleaseYear(), 2008);
}

TEST_F(FilmTest, CheckGenreGetter)
{
	EXPECT_EQ(f1->GetGenres(), "Action");
	EXPECT_EQ(f2->GetGenres(), "Action, Drama");
}

TEST_F(FilmTest, CheckCastGetter)
{
	EXPECT_EQ(f1->GetCast(), "No ideea");
	EXPECT_EQ(f2->GetCast(), "Hollywood");
}

TEST_F(FilmTest, CheckDirectorGetter)
{
	EXPECT_EQ(f1->GetDirector(), "Spielberg");
	EXPECT_EQ(f2->GetDirector(), "Jason Statam");
}

TEST_F(FilmTest, CheckDescriptionGetter)
{
	EXPECT_EQ(f1->GetDescription(), "There once was a man who...");
	EXPECT_EQ(f2->GetDescription(), "Action movie with nice cars");
}

TEST_F(FilmTest, CheckCountryGetter)
{
	EXPECT_EQ(f1->GetCountry(), "USA");
	EXPECT_EQ(f2->GetCountry(), "England");
}

TEST_F(FilmTest, CheckAgeRestrictionGetter)
{
	EXPECT_EQ(f1->GetAgeRange(), "PG");
	EXPECT_EQ(f2->GetAgeRange(), "TV_MA");
}

TEST_F(FilmTest, CheckTypeSetter)
{
	f3->SetType("Movie");
	EXPECT_EQ(f3->GetType(), "Movie");
}

TEST_F(FilmTest, CheckDurationSetter)
{
	f3->SetDuration("90min");
	EXPECT_EQ(f3->GetDuration(), "90min");
}

TEST_F(FilmTest, CheckTitleSetter)
{
	f3->SetTitle("Fast and furious");
	EXPECT_EQ(f3->GetTitle(), "Fast and furious");
}

TEST_F(FilmTest, CheckReleaseYearSetter)
{
	f3->SetReleaseYear(2020);
	EXPECT_EQ(f3->GetReleaseYear(), 2020);
}

TEST_F(FilmTest, CheckGenreSetter)
{
	f3->SetGenres("Action");
	EXPECT_EQ(f3->GetGenres(), "Action");
}

TEST_F(FilmTest, CheckCastSetter)
{
	f3->SetCast("Margot Robbie");
	EXPECT_EQ(f3->GetCast(), "Margot Robbie");
}

TEST_F(FilmTest, CheckDirectorSetter)
{
	f3->SetDirector("Spielberg");
	EXPECT_EQ(f3->GetDirector(), "Spielberg");
}

TEST_F(FilmTest, CheckDescriptionSetter)
{
	f3->SetDescription("There once was a girl named S");
	EXPECT_EQ(f3->GetDescription(), "There once was a girl named S");
}

TEST_F(FilmTest, CheckCountrySetter)
{
	f3->SetCountry("Romania");
	EXPECT_EQ(f3->GetCountry(), "Romania");
}

TEST_F(FilmTest, CheckAgeRestrictionSetter)
{
	f3->SetAgeRange("TV_13");
	EXPECT_EQ(f3->GetAgeRange(), "TV_13");
}