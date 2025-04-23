#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Scoring {
public:
	Scoring();
	Scoring(const Scoring& ref);
	~Scoring();

	int updateScore(int add);

	int getCurrentScore();

	int getHighScore();

	void resetScore();

	void draw(sf::RenderWindow& window);

private:
	std::fstream saveData;
	int currentScore;
	int highScore;
};