#pragma once
#include "blocks.hpp"

class Holdblock {
public:
	Holdblock();
	Tetromino* swap();

	void draw(sf::RenderWindow& window);
	Tetromino* getBlock();
	void setBlock(Tetromino* newBlock);


private:
	void updateTexture(int id);

	Tetromino* block;
	Texture tex;
	Sprite sprite;

	Texture blockTex;
	Sprite blockSprite;
};