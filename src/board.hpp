#pragma once
#include "cell.hpp"
#include "tetromino.hpp"
#include "blockqueue.hpp"
#include <Vector>
#include <iostream>

using sf::RenderWindow;

class Board {
public:
	Board(Vector2f position = {0.0,0.0});

	~Board();

	void setCurrent(Tetromino* newBlock);

	bool moveBlock(Vector2i vec);

	bool rotateBlock(int direction);

	void placeBlock();

	void update(RenderWindow &window);

	void lineClearCheck();

private:
	bool isValid(Vector2i& pos);

	Cell cells[10][20];
	Vector2f origin;
	Tetromino* current;
	Texture texture;
	Texture cellTexture;
	Sprite sprite;
	BlockQueue queue;
};