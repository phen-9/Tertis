#pragma once
#include "cell.hpp"

using sf::RenderWindow;

class Board {
public:
	Board(Vector2f position = {0.0,0.0});

	void draw(RenderWindow &window);

private:
	Cell cells[10][20];
	Vector2f origin;
	Texture bgTexture;
};