#include "board.hpp"
#include <ctime>
#include <cstdlib>

Board::Board(Vector2f position) :
	texture("../../../../assets/bg.png"),
	cellTexture("../../../../assets/block.png"),
	sprite(texture){
	current = new Tetromino();

	srand(time(0));

	origin = position;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			cells[x][y] = Cell({ 0,0 }, cellTexture);
			Vector2f cellPosition;
			if (y <= 5){
				cells[x][y].setPlaced(true);
			}
			else {
				cells[x][y].setOccupied(false);
			}
			cellPosition.x = origin.x + (CELL_SIZE * x) - (5*CELL_SIZE);
			cellPosition.y = origin.y + (CELL_SIZE * (19 - y)) - (10*CELL_SIZE);
			cells[x][y].setPosition(cellPosition);

		}
	}
}

Board::~Board()
{
	for (int x = 0; x < 10; x++) {
		delete[] cells[x];
	}
	delete current;
}

void Board::draw(RenderWindow& window) {
	sprite.setPosition({ origin.x - (5 * CELL_SIZE) , origin.y - (10 * CELL_SIZE) });
	window.draw(sprite);
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell cell = cells[x][y];
			if (cell.isOccupied() && !cell.isPlaced()) {
				cell.setColor(current->getColor());
				cell.draw(window);
			}
			else if (cell.isPlaced()) {
				cell.setColor(sf::Color{ 130, 130, 130 });
				cell.draw(window);
			}
		}
	}
}

void Board::setCurrent(Tetromino* newBlock)
{
	this->current = newBlock;
}

bool Board::moveBlock(Vector2i vec)
{
	Vector2i center = current->getCenter() + vec;
	Vector2i* positions = current->getPositions();
	if (isValid(center) && isValid(center + positions[0]) && isValid(center + positions[1]) && isValid(center + positions[2])) {
		current->setPosition(center);
		return true;
	}
	// else delete system32
	return false;
}

bool Board::rotateBlock(bool direction)
{
	Tetromino temp = *current;
	if (direction) {
		temp.orientationLeft();
	}
	else {
		temp.orientationRight();
	}
	temp.rotate();
	Vector2i center = temp.getCenter();
	Vector2i* positions = temp.getPositions();
	if (isValid(center) && isValid(center + positions[0]) && isValid(center + positions[1]) && isValid(center + positions[2])) {
		if (direction) {
			current->orientationLeft();
		}
		else {
			current->orientationRight();
		}
		current->rotate();
		return true;
	}
	return false;
}

void Board::placeBlock()
{
	Vector2i center = current->getCenter();
	Vector2i* positions = current->getPositions();
	cells[center.x][center.y].setPlaced(true);
	for (int i = 0; i < 3; i++) {
		cells[center.x + positions[i].x][center.y + positions[i].y].setPlaced(true);
	}
}

void Board::update()
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell* cell = &cells[x][y];
			if (!cell->isPlaced()) {
				// Check if cell is in the current tetromino
				if (current->isOccupying({ x, y })) {
					cell->setOccupied(true);
				}
				else {
					cell->setOccupied(false);
				}
			}
			else {
				cell->setOccupied(true);
			}
		}
	}
}

bool Board::isValid(Vector2i& pos)
{
	// Placed
	if (cells[pos.x][pos.y].isPlaced()) {
		return false;
	}

	// OOB
	if (pos.x < 0 || pos.x > 9 || pos.y < 0) {
		return false;
	}
	return true;
}
