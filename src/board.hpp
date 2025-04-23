#pragma once
#include "cell.hpp"
#include "tetromino.hpp"
#include "blockqueue.hpp"
<<<<<<< HEAD
#include "holdblock.hpp"
=======
#include "scoring.hpp"
>>>>>>> 9b70b82de9c6524c419981b4c2720db5f082d840
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

	void holdBlock();

	void update(RenderWindow &window);

	void lineClearCheck();

private:
	bool isValid(Vector2i& pos);

	Scoring score;
	Cell cells[10][20];
	Vector2f origin;
	Tetromino* current;
	Texture texture;
	Texture cellTexture;
	Sprite sprite;
	BlockQueue queue;
	Holdblock hold;
};