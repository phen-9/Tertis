#include "scoring.hpp"

using std::to_string;

Scoring::Scoring()
{
	highScore = 0;
	currentScore = 0;
	clear = sf::SoundBuffer("../../../../assets/lineclear.wav");
	tertis = sf::SoundBuffer ("../../../../assets/tertisclear.wav");
	audioman = new sf::Sound(clear);

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

Scoring::Scoring(const Scoring& ref)
{
	this->currentScore = ref.currentScore;
	this->highScore = ref.highScore;
	saveData = std::fstream("../../../../src/savedata.txt", std::ios::in);
	this->audioman = ref.audioman;

}

Scoring::~Scoring()
{
	// Save highscore to file
	saveData = std::fstream("../../../../src/savedata.txt", std::ios::out);
	saveData << highScore;
	saveData.close();
	delete audioman;
}

int Scoring::updateScore(int add, bool sound)
{
	if (add >= 0) {
		currentScore += add;
		if (currentScore > highScore) {
			highScore = currentScore;
		}

		sf::SoundBuffer buf;

		if (sound) {
			if (add >= 4000) {
				// play tertis sound
				audioman->setBuffer(tertis);
				audioman->setVolume(75);
				audioman->play();
			}
			else if (add >= 0) {
				// play normal clear sound
				audioman->setBuffer(clear);
				audioman->setVolume(50);
				audioman->play();
			}
		}
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

void Scoring::setHighScore(int newScore)
{
	highScore = newScore;
}

void Scoring::resetScore()
{
	currentScore = 0;
}

void Scoring::draw(sf::RenderWindow& window)
{
	sf::Font f("../../../../assets/ComicSansMS.ttf");
	sf::Text text(f);

	std::string str = "Current Score: ";
	str += to_string(currentScore) + "\n\nHigh Score: " + to_string(highScore);

	text.setString(str);

	text.setCharacterSize(50);

	text.setFillColor(sf::Color::White);

	text.setPosition({ 200, 400 });

	window.draw(text);
}
