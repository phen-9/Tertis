#pragma once
#include "cell.hpp"
#include "tetromino.hpp"

using sf::RenderWindow;

class Board {
public:
	Board(sf::Vector2f position = {0.0,0.0});

	Cell get(int x, int y);

	void update();

private:
	Cell cells[10][20];
	sf::Vector2f origin;
	Tetromino current;
};