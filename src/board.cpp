#include "board.hpp"
#include <ctime>
#include <cstdlib>

Board::Board(Vector2f position) :
	texture("../../../../assets/bg.png"),
	cellTexture("../../../../assets/block.png"),
	sprite(texture){

	srand(time(0));

	origin = position;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			cells[x][y] = Cell({ 0,0 }, cellTexture);
			Vector2f cellPosition;
			if (y >= 15){
				cells[x][y].setOccupied(true);
			}
			else {
				cells[x][y].setOccupied(false);
			}
			cellPosition.x = origin.x + (CELL_SIZE * x) - (5*CELL_SIZE);
			cellPosition.y = origin.y + (CELL_SIZE * y) - (10*CELL_SIZE);
			cells[x][y].setPosition(cellPosition);

		}
	}
}

Board::~Board()
{
	for (int x = 0; x < 10; x++) {
		delete[] cells[x];
	}
}

void Board::draw(RenderWindow& window) {
	sprite.setPosition({ origin.x - (5 * CELL_SIZE) , origin.y - (10 * CELL_SIZE) });
	window.draw(sprite);
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell cell = cells[x][y];
			if (cell.isOccupied()) {
				cell.setColor(Color(rand() % 255, 0, 255));
				cell.draw(window);
			}
		}
	}
}

void Board::update()
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell* cell = &cells[x][y];
			if (!cell->isPlaced()) {
				// Check if cell is in the current tetromino
				if (current.isOccupying({ x, y })) {
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
