#include "tetromino.hpp"

Tetromino::Tetromino(Vector2i center)
{
	this->center = center;
	arr = new Vector2i[4];
	col = sf::Color{ 130, 130, 130 };
}

Tetromino::Tetromino(Tetromino& ref)
{
	this->center = ref.center;
	for (int i = 0; i < 4; i++) {
		arr[i] = ref.arr[i];
	}
}

Tetromino::~Tetromino()
{
	delete[] arr;
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

void Tetromino::rotate()
{

}
