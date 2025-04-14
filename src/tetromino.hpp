#pragma once
#include "cell.hpp"
#include <SFML/Graphics.hpp>

using sf::Vector2i;

class Tetromino {
public:
	Tetromino(Vector2i center = { 5, 20 });
	Tetromino(const Tetromino& ref);
	~Tetromino();

	Vector2i getCenter();

	void setPosition(Vector2i newPos);

	Vector2i* getPositions();

	void rotate();

	bool isOccupying(Vector2i target);
protected:
	Vector2i center;
	Vector2i* arr;
	Color col;
};