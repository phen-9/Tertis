#include "scoring.hpp"
#include <iostream>

class ScoringTest {
public:
	ScoringTest();
	void run();
private:
	Scoring tempscore;
	int saveHighScore;
};

ScoringTest::ScoringTest()
{
	tempscore.resetScore();
	saveHighScore = tempscore.getHighScore();
}

inline void ScoringTest::run()
{
	bool hasfailed = false;
	
	int currentScore = tempscore.getCurrentScore();
	// Tests to see if numbers are successfully added when add is called
	if (currentScore + 500 != tempscore.updateScore(500, false)) {
		std::cout << "Test failed: score was not added\n";
		hasfailed = true;
	}
	
	currentScore = tempscore.getCurrentScore();
	// Tests to see if negative numbers are blocked from being added
	if (currentScore != tempscore.updateScore(-500, false)) {
		std::cout << "Test failed: negative score was added\n";
		hasfailed = true;
	}

	tempscore.setHighScore(5000);
	tempscore.resetScore();
	tempscore.updateScore(10000, false);
	// Tests to see if a current score > high score will result in the high score being set to the current score
	if (tempscore.getHighScore() == 5000) {
		std::cout << "Test failed: highscore was not overridden by a higher current score\n";
		hasfailed = true;
	}

	if (!hasfailed) {
		std::cout << "ScoringTest Succeeded!\n";
	}

	tempscore.setHighScore(saveHighScore); // so save file high score is not overridden
}