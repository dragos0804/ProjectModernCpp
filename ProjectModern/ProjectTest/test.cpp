#include "pch.h"
#include "User.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  User u1 = User(1, "Alex", "Alex036", "31-05-2002", "chelmus.alexanther@gmail.com", "123456", "Romania");

  EXPECT_EQ(u1.GetName(), "Alex");
}