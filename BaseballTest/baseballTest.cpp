#include <stdexcept>
#include <string>


using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question) : question(question) {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3, 0 };
		}		

		return countStrikesAndBalls(guessNumber);
	}

	GuessResult countStrikesAndBalls(const std::string& guessNumber)
	{
		GuessResult result = { false, 0, 0 };
		result.strikes = countStrikes(guessNumber);
		result.balls = countBalls(guessNumber);
		return result;
	}

	int countStrikes(const std::string& guessNumber)
	{
		int strikes = 0;
		for (int i = 0; i < QUESTION_LENGTH; i++) {
			if (guessNumber[i] == question[i]) strikes++;
		}
		return strikes;
	}

	int countBalls(const std::string& guessNumber)
	{
		int balls = 0;
		for (int guessIndex = 0; guessIndex < QUESTION_LENGTH; guessIndex++) {
			for (int questionIndex = 0; questionIndex < QUESTION_LENGTH; questionIndex++) {
				if (guessNumber[guessIndex] == question[questionIndex]) {
					if (guessIndex != questionIndex) {
						balls++;
					}
					break;
				}
			}
		}
		return balls;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != QUESTION_LENGTH) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]);
	}

private:
	string question;	
	const int QUESTION_LENGTH = 3;
};