#pragma once
#include "cell.hpp"
#include "tetromino.hpp"

using sf::RenderWindow;

class Board {
public:
	Board(Vector2f position = {0.0,0.0});

	~Board();

	void draw(RenderWindow &window);

	void setCurrent(Tetromino& newBlock);

	void moveBlock(Vector2i& vec);

	void update();

private:
	Cell cells[10][20];
	Vector2f origin;
	Tetromino current;
	Texture texture;
	Texture cellTexture;
	Sprite sprite;
};