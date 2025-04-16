#pragma once


#include <SFML/Graphics.hpp>

#define CELL_SIZE 32

using sf::Color;
using sf::Sprite;

class Cell {
public:
	Cell();

	void setColor(Color newColor);
	void setOccupied(bool isOccupied);
	void setPlaced(bool isPlaced);

	Color getColor();
	bool isOccupied();
	bool isPlaced();

private:
	bool occupied;
	Color color;
	bool placed;
};
