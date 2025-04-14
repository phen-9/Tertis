
#include "cell.hpp"

//implement cell class

Cell::Cell(Vector2f newPosition) {
	occupied = false;
	color = *new Color();
	position = newPosition;
	texture.loadFromFile("assets/block.png");
	
}

void Cell::setColor(Color newColor) {
	color = newColor;
}

void Cell::setPosition(Vector2f newPos) {
	position = newPos;
}

void Cell::setOccupied(bool isOccupied) {
	occupied = isOccupied;
}

bool Cell::isOccupied() {
	return occupied;
}

void Cell::draw(sf::RenderWindow &window) {
	sf::RectangleShape test;
	Sprite sprite = *new Sprite(texture);

	sprite.setColor(color);
	sprite.setPosition(position);
	window.draw(sprite);

}

