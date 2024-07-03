#include "pch.h"
#include "../BaseballTest/baseballTest.cpp"

#include <string>

using namespace std;

TEST(BaseballTest, Exception1) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballTest, Exception2) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}


