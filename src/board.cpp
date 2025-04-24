#include "board.hpp"
#include <ctime>
#include <cstdlib>

Board::Board(Vector2f position) :
	texture("../../../../assets/bg.png"),
	cellTexture("../../../../assets/block.png"),
	sprite(texture){
	current = queue.getBlock();

	srand(time(0));

	origin = position;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			cells[x][y] = Cell({ 0,0 }, cellTexture);
			Vector2f cellPosition;
			cells[x][y].setOccupied(false);
			cells[x][y].setColor(Color(130, 130, 130));
			cellPosition.x = origin.x + (CELL_SIZE * x) - (5*CELL_SIZE);
			cellPosition.y = origin.y + (CELL_SIZE * (19 - y)) - (10*CELL_SIZE);
			cells[x][y].setPosition(cellPosition);

		}
	}
	hasSwapped = false;
}

Board::~Board()
{
	for (int x = 0; x < 10; x++) {
		delete[] cells[x];
	}
	delete current;
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

bool Board::rotateBlock(int direction)
{
	Tetromino* temp = current->clone();
	if (direction == -1) {
		temp->orientationLeft();
	}
	else {
		temp->orientationRight();
	}
	temp->rotate();
	Vector2i center = temp->getCenter();
	Vector2i* positions = temp->getPositions();
	if (isValid(center) && isValid(center + positions[0]) && isValid(center + positions[1]) && isValid(center + positions[2])) {
		if (direction == -1) {
			current->orientationLeft();
		}
		else {
			current->orientationRight();
		}
		current->rotate();
		delete temp;
		return true;
	}
	delete temp;
	return false;
}

void Board::placeBlock()
{
	Vector2i center = current->getCenter();
	Vector2i* positions = current->getPositions();
	cells[center.x][center.y].setPlaced(true);
	cells[center.x][center.y].setOccupied(false);
	for (int i = 0; i < 3; i++) {
		cells[center.x + positions[i].x][center.y + positions[i].y].setPlaced(true);
		cells[center.x + positions[i].x][center.y + positions[i].y].setOccupied(false);
	}
	lineClearCheck();
	delete current;
	setCurrent(queue.getBlock());
	hasSwapped = false;
}

void Board::holdBlock() {
	if (!hasSwapped) {
		if (hold.getBlock() == nullptr) {
			hold.setBlock(current);
			setCurrent(queue.getBlock());
		}
		else {
			Tetromino* temp = current->clone();
			current = hold.getBlock()->clone();
			hold.setBlock(temp);
			current->setPosition({ 5,20 });
		}
		hasSwapped = true;
	}
}

void Board::update(RenderWindow &window)
{
	window.clear();
	sprite.setPosition({ origin.x - (5 * CELL_SIZE) , origin.y - (10 * CELL_SIZE) });
	hold.draw(window);
	queue.draw(window);
	window.draw(sprite);
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell* cell = &cells[x][y];
			if (!cell->isPlaced()) {
				// Check if cell is in the current tetromino
				if (current->isOccupying({ x, y })) {
					cell->setOccupied(true);
					cell->setColor(current->getColor());
					cell->draw(window);
				}
				else {
					cell->setOccupied(false);
				}
			}
			else {
				cell->draw(window);
			}
		}
	}
	score.draw(window);
	window.display();
}

void Board::lineClearCheck()
{
	std::vector<int> arr;
	for (int y = 0; y < 20; y++) {
		bool full = true;
		for (int x = 0; x < 10; x++) {
			if (!cells[x][y].isPlaced()) {
				full = false;
			}
		}
		if (full) {
			arr.push_back(y);
			for (int x = 0; x < 10; x++) {
				cells[x][y].setPlaced(false);
				cells[x][y].setOccupied(false);
			}
		}
	}
	if (arr.size() > 0) {
		// Move all lines down
		int y = 0;
		for (int temp : arr) {
			if (temp > y) {
				y = temp; // Find the top line cleared
			}
		}
		for (; y < 20; y++) {
			// Check only lines above the cleared ones
			for (int x = 0; x < 10; x++) {
				if (cells[x][y].isPlaced()) {
					cells[x][y - arr.size()].setPlaced(true);
					cells[x][y - arr.size()].setColor(cells[x][y].getColor());
					cells[x][y].setPlaced(false);
				}
			}
		}

		if (arr.size() == 1) {
			// score + 150
			score.updateScore(150);
		}
		else if (arr.size() == 2) {
			// score + 450
			score.updateScore(450);
		}
		else if (arr.size() == 3) {
			// score + 1000
			score.updateScore(1000);
		}
		else if (arr.size() == 4) {
			// score + 4000
			score.updateScore(4000);
		}
		else {
			// impossible
			// score + 999,999,999
			score.updateScore(999999999);
		}
	}
}

bool Board::isValid(Vector2i& pos)
{
	// OOB
	if (pos.x < 0 || pos.x > 9 || pos.y < 0) {
		return false;
	}

	if (pos.y > 19) {
		return true;
	}

	// Placed
	if (cells[pos.x][pos.y].isPlaced()) {
		return false;
	}
	return true;
}
