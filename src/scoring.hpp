#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

class Scoring {
public:
	Scoring();
	Scoring(const Scoring& ref);
	~Scoring();

	int updateScore(int add, bool sound);

	int getCurrentScore();

	int getHighScore();

	void setHighScore(int newScore);

	void resetScore();

	void draw(sf::RenderWindow& window);

private:
	std::fstream saveData;
	int currentScore;
	int highScore;
	sf::SoundBuffer clear;
	sf::SoundBuffer tertis;
	sf::Sound* audioman;
};