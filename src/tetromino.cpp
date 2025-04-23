#include "tetromino.hpp"
#include <iostream>

Tetromino::Tetromino(Vector2i center)
{
	this->center = center;
	arr = new Vector2i[3];
	col = sf::Color{ 130, 130, 130 };
	this->orientation = 0;
}

Tetromino::Tetromino(const Tetromino& ref)
{
	arr = new Vector2i[3];
	this->center = ref.center;
	for (int i = 0; i < 3; i++) {
		arr[i] = ref.arr[i];
	}
	col = ref.col;
	orientation = ref.orientation;
}

Tetromino::~Tetromino()
{
	delete[] arr;
}

Tetromino* Tetromino::clone()
{
	return new Tetromino(*this);
}

Vector2i Tetromino::getCenter()
{
	return center;
}

void Tetromino::setPosition(Vector2i newPos)
{
	center = newPos;
}

Vector2i* Tetromino::getPositions()
{
	return arr;
}

Color Tetromino::getColor()
{
	return this->col;
}

void Tetromino::rotate()
{
	
}

void Tetromino::orientationRight()
{
	if (orientation > 0) { orientation--; }
	else { orientation = 3; }
}

void Tetromino::orientationLeft()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
}

bool Tetromino::isOccupying(Vector2i target)
{
	if (center == target) {
		return true;
	}
	for (int i = 0; i < 3; i++) {
		if (center + arr[i] == target) {
			return true;
		}
	}
	return false;
}
