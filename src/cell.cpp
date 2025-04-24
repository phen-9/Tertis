
#include "cell.hpp"


//single square on a board, stores the color to render, as well as if it is occupied by the current block or settled
Cell::Cell(Vector2f newPosition, Texture& tex) :
	sprite(tex) {
	occupied = false;
	placed = false;
	color = Color();
	position = newPosition;
}

Cell::~Cell()
{
}

Sprite Cell::getSprite() {
	return sprite;
}

void Cell::setColor(Color newColor) {
	color = newColor;
}

Color Cell::getColor()
{
	return this->color;
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

void Cell::setPlaced(bool isPlaced)
{
	placed = isPlaced;
}

bool Cell::isPlaced()
{
	return placed;
}

void Cell::draw(sf::RenderWindow &window) {
	sprite.setColor(color);
	sprite.setPosition(position);
	window.draw(sprite);

}
