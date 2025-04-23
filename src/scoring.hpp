#include <iostream>
#include <fstream>
#include <string>

class Scoring {
public:
	Scoring();
	Scoring(Scoring& ref);
	~Scoring();

	int updateScore(int add);

	int getCurrentScore();

	int getHighScore();

	void resetScore();

private:
	std::fstream saveData;
	int currentScore;
	int highScore;
};