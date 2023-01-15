#include "pch.h"
#include <string>
#include <fstream>
#include "Login.h"

class LoginTest : public ::testing::Test
{
public:
	
	void SetUp() override
	{
		l1 = new Login("cristi", "Cristi0");
	}

	void TearDown() override
	{
		delete l1;
	}

protected:
	Login* l1;
};

TEST_F(LoginTest, CheckUsernameInput)
{
	EXPECT_EQ(l1->GetUsernameInput(), "cristi");
}

TEST_F(LoginTest, CheckPasswordInput)
{
	EXPECT_EQ(l1->GetPasswordInput(), "Cristi0");
}