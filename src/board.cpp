#include "board.hpp"

void Board::draw() {

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Vector2i position;
			position.x = origin + (CELL_SIZE * x);
			position.y = origin + (CELL_SIZE * y);
			cells[x][y].draw(position);

		}

	}
}