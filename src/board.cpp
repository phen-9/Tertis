#include "board.hpp"

Board::Board(Vector2f position) {
	origin = position;

	bgTexture.loadFromFile("../../../../assets/bg.png");

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Vector2f cellPosition;
			if (y >= 15){
				cells[x][y].setOccupied(true);
			}
			cellPosition.x = origin.x + (CELL_SIZE * x) - (5*CELL_SIZE);
			cellPosition.y = origin.y + (CELL_SIZE * y) - (10*CELL_SIZE);
			cells[x][y].setPosition(cellPosition);

		}
	}
}

void Board::draw(RenderWindow& window) {
	Sprite background = *new Sprite(bgTexture);
	background.setPosition({ origin.x - (5 * CELL_SIZE) , origin.y - (10 * CELL_SIZE) });
	window.draw(background);
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell cell = cells[x][y];
			if (cell.isOccupied()) {
				cell.setColor(Color(0, 0, 255));
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
