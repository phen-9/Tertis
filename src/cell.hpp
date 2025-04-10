#pragma once


#include <SFML/Graphics.hpp>

using sf::Vector2i;
using sf::Color;

class Cell {
public:
	Cell(int x = 0, int y = 0);

	void draw();


private:
	bool isOccupied;
	Color color;
	Vector2i coordinate;
};