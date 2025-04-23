#include "scoring.hpp"

Scoring::Scoring()
{
	highScore = 0;
	currentScore = 0;
	saveData = std::fstream("../../../../src/savedata.txt", std::ios::in);
	if (saveData.is_open()) {
		std::string temp = "";
		saveData >> temp;
		bool allDigits = true;
		for (char i : temp) {
			if (!std::isdigit(i)) {
				allDigits = false;
				break;
			}
		}
		if (allDigits) {
			this->highScore = stoi(temp);
		}
	}
}

Scoring::Scoring(Scoring& ref)
{
	this->currentScore = ref.currentScore;
	this->highScore = ref.highScore;
	saveData = std::fstream("../../../../src/savedata.txt", std::ios::in);

}

Scoring::~Scoring()
{
	// Save highscore to file
	saveData = std::fstream("../../../../src/savedata.txt", std::ios::out);
	saveData << highScore;
	saveData.close();
}

int Scoring::updateScore(int add)
{
	currentScore += add;
	if (currentScore > highScore) {
		highScore = currentScore;
	}
	return currentScore;
}

int Scoring::getCurrentScore()
{
	return currentScore;
}

int Scoring::getHighScore()
{
	return highScore;
}

void Scoring::resetScore()
{
	currentScore = 0;
}
