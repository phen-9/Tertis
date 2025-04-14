#pragma once


#include <SFML/Graphics.hpp>

#define CELL_SIZE 32

using sf::Vector2f;
using sf::Color;
using sf::Sprite;
using sf::Texture;

class Cell {
public:
	Cell(Vector2f newPosition = Vector2f(0,0));
	void draw(sf::RenderWindow &window);

	void setColor(Color newColor);
	void setPosition(Vector2f newPos);

private:
	bool isOccupied;
	Color color;
	Vector2f position;
	Texture texture;
};
