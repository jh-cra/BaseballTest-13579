#include "pch.h"
#include "../BaseballTest/baseballTest.cpp"

#include <string>

using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, Exception1) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}


