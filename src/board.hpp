#pragma once
#include "cell.hpp"
#include "tetromino.hpp"

using sf::RenderWindow;

class Board {
public:
	Board(Vector2f position = {0.0,0.0});

	~Board();

	void draw(RenderWindow &window);

	void setCurrent(Tetromino* newBlock);

	bool moveBlock(Vector2i vec);

	void placeBlock();

	void update();

private:
	bool isValid(Vector2i& pos);

	Cell cells[10][20];
	Vector2f origin;
	Tetromino* current;
	Texture texture;
	Texture cellTexture;
	Sprite sprite;
};