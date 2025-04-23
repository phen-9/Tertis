
#include "blockqueue.hpp"
#include <iostream>
#include <random>


BlockQueue::BlockQueue() : tex("../../../../assets/next.png"), sprite(tex)
{
	for (int i = 0; i < 7; i++) {
		blockUsed[i] = false;
	}
	sprite.setOrigin({100.0, 100.0});
	next = nullptr;
	blocksUsed = 0;
	setNext();
}

void BlockQueue::draw(sf::RenderWindow& window) {
	sprite.setPosition({ 1200.0, 200.0});
	window.draw(sprite);

}

Tetromino* BlockQueue::getBlock() {
	Tetromino* current = next;
	setNext();
	for (int i = 0; i < 7; i++) {
		if (blockUsed[i]) {
			std::cout << i << ", ";
		}
	}
	std::cout << "\n";
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
		filepath = "../../../../assets/next_square.png";
		break;
	case 1:
		filepath = "../../../../assets/next_line.png";
		break;
	case 2:
		filepath = "../../../../assets/next_l.png";
		break;
	case 3:
		filepath = "../../../../assets/next_j.png";
		break;
	case 4:
		filepath = "../../../../assets/next_t.png";
		break;
	case 5:
		filepath = "../../../../assets/next_s.png";
		break;
	case 6:
		filepath = "../../../../assets/next_z.png";
		break;
	}
	tex.loadFromFile(filepath);
	sprite.setTexture(tex);
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
		newBlock = new LineBlock();
		break;
	case 1:
		newBlock = new SquareBlock();
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
		break;
		newBlock = new SBlock();
	case 6:
		newBlock = new ZBlock();
		break;
	}
	updateTexture(r);
	blockUsed[r] = true;
	blocksUsed++;
	next =  newBlock;
}