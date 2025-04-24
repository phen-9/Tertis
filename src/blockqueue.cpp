
#include "blockqueue.hpp"
#include <iostream>
#include <random>

BlockQueue::BlockQueue() : tex("../../../../assets/next_bg.png"), sprite(tex),
blockTex("../../../../assets/blank.png"), blockSprite(blockTex)
{
	for (int i = 0; i < 7; i++) {
		blockUsed[i] = false;
	}
	sprite.setOrigin({ 100.0, 100.0 });
	blockSprite.setOrigin({ 100.0, 100.0 });
	next = nullptr;
	blocksUsed = 0;
	setNext();
}

void BlockQueue::draw(sf::RenderWindow& window) {
	sprite.setPosition({ 1250.0, 200.0});
	blockSprite.setPosition(sprite.getPosition());
	window.draw(sprite);
	window.draw(blockSprite);

}

Tetromino* BlockQueue::getBlock() {
	Tetromino* current = next;
	setNext();
	if (blocksUsed == 7) {
		for (int i = 0; i < 7; i++) {
			blockUsed[i] = false;
		}
		blocksUsed = 0;
	}
	return current;
}

void BlockQueue::updateTexture(int id) {
	std::string filepath;
	switch (id) {
	case 0:
		filepath = "../../../../assets/square.png";
		break;
	case 1:
		filepath = "../../../../assets/line.png";
		break;
	case 2:
		filepath = "../../../../assets/l.png";
		break;
	case 3:
		filepath = "../../../../assets/j.png";
		break;
	case 4:
		filepath = "../../../../assets/t.png";
		break;
	case 5:
		filepath = "../../../../assets/s.png";
		break;
	case 6:
		filepath = "../../../../assets/z.png";
		break;
	}
	blockTex.loadFromFile(filepath);
	blockSprite.setTexture(blockTex);
}

void BlockQueue::setNext() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 7);
	bool valid = false;
	int r = 0;
	Tetromino* newBlock = nullptr;
	while (!valid) {
		r = distrib(gen);
		if (blockUsed[r] == false) {
			valid = true;
		}
	}
	switch (r) {
	case 0:
		newBlock = new SquareBlock();
		break;
	case 1:
		newBlock = new LineBlock();
		break;
	case 2:
		newBlock = new LBlock();
		break;
	case 3:
		newBlock = new JBlock();
		break;
	case 4:
		newBlock = new TBlock();
		break;
	case 5:
		newBlock = new SBlock();
		break;
	case 6:
		newBlock = new ZBlock();
		break;
	}
	updateTexture(r);
	blockUsed[r] = true;
	blocksUsed++;
	next =  newBlock;
}