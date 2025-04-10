#pragma once


#include <SFML/Graphics.hpp>

#define CELL_SIZE 10

using sf::Vector2i;
using sf::Color;

class Cell {
public:
	Cell();
	void draw(Vector2i position);


private:
	bool isOccupied;
	Color color;
};