#include "board.hpp"

using sf::Vector2f;

Board::Board(Vector2f position) {
	origin = position;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell cell = cells[x][y];
			cell.setOccupied(true);
		}
	}
}

Cell Board::get(int x, int y) {
	return cells[x][y];
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
