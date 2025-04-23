#pragma once


#include <SFML/Graphics.hpp>

#define CELL_SIZE 32

using sf::Vector2f;
using sf::Color;
using sf::Sprite;
using sf::Texture;

class Cell {
public:
	Cell(Vector2f newPosition = Vector2f(0, 0), Texture& tex = Texture());
	~Cell();

	void draw(sf::RenderWindow &window);

	void setColor(Color newColor);
	Color getColor();

	void setPosition(Vector2f newPos);

	Sprite getSprite();

	void setOccupied(bool isOccupied);
	bool isOccupied();
	void setPlaced(bool isPlaced);
	bool isPlaced();

private:
	bool occupied;
	Color color;
	Vector2f position;
	bool placed;
	Sprite sprite;
};
