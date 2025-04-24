
#include "holdblock.hpp"
#include <iostream>

Holdblock::Holdblock() : tex("../../../../assets/hold_bg.png"), sprite(tex),
blockTex("../../../../assets/blank.png"), blockSprite(blockTex)
{
	sprite.setOrigin({ 100.0, 100.0 });
	blockSprite.setOrigin({ 100.0, 100.0 });
	block = nullptr;
}

Holdblock::~Holdblock()
{
	if (this->block != nullptr) {
		delete block;
	}
}


void Holdblock::draw(sf::RenderWindow& window) {
	sprite.setPosition({ 670.0, 200.0 });
	blockSprite.setPosition(sprite.getPosition());
	window.draw(sprite);
	window.draw(blockSprite);

}

Tetromino* Holdblock::getBlock() {
	return block;
}


void Holdblock::setBlock(Tetromino* newBlock) {
	block = newBlock->clone();
	updateTexture(block->getId());
	std::cout << block->getId() << ", " << newBlock->getId() << "\n";
}


void Holdblock::updateTexture(int id) {
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