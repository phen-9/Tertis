
#pragma once
#include "blocks.hpp"

//supplies new tetromino objects to board goes through all possible tetrominos before repeating (bag system)
class BlockQueue {
public:
	BlockQueue();
	Tetromino* getBlock();

	void draw(sf::RenderWindow &window);
	
private:
	void updateTexture(int id);
	void setNext();
	bool blockUsed[7];
	int blocksUsed;
	Tetromino *next;

	Texture tex;
	Sprite sprite;
	Texture blockTex;
	Sprite blockSprite;
};
