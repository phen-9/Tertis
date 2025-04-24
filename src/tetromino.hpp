#pragma once
#include "cell.hpp"
#include <SFML/Graphics.hpp>

using sf::Vector2i;

//class definition for a single tetromino, consisting of a center coordinate on a board and 3 relative coordinates of other pieces of the block
class Tetromino {
public:
	Tetromino(Vector2i center = { 5, 20 });
	Tetromino(const Tetromino& ref);
	~Tetromino();

	virtual Tetromino* clone();

	Vector2i getCenter();

	void setPosition(Vector2i newPos);

	Vector2i* getPositions();
	Color getColor();
	virtual int getId();

	virtual void rotate();
	void orientationRight();
	void orientationLeft();

	bool isOccupying(Vector2i target);
protected:
	int id;
	Vector2i center;
	Vector2i* arr;
	Color col;
	int orientation; // int 0 - 3 that determines the current rotation of the block
};