
#pragma once
#include "blocks.hpp"


class BlockQueue {
public:
	BlockQueue();
	Tetromino* getBlock();

	void draw(sf::RenderWindow &window);
	void updateTexture(int id);
	
private:
	void setNext();
	bool blockUsed[7];
	int blocksUsed;
	Tetromino *next;
	Texture tex;
	Sprite sprite;
};
