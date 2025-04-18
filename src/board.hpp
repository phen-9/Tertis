#pragma once
#include "cell.hpp"
#include "tetromino.hpp"

using sf::RenderWindow;

class Board {
public:
	Board(Vector2f position = {0.0,0.0});

	void draw(RenderWindow &window);

	void update();

private:
	Cell cells[10][20];
	Vector2f origin;
	Texture bgTexture;
	Tetromino current;
};