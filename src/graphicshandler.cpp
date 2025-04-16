
#include "graphicshandler.hpp"

using sf::Vector2f;

GraphicsHandler::GraphicsHandler(RenderWindow &newWindow) {
	assetPath = "../../../../assets/";
	cellTexture.loadFromFile(assetPath + "block.png");
	boardBackgroundTexture.loadFromFile(assetPath + "bg.png");
	window = newWindow;
}

void GraphicsHandler::renderCell(Cell cell, Vector2f position) {
	Sprite sprite = *new Sprite(cellTexture);
	sprite.setPosition(position);
	sprite.setColor(cell.setColor());
	window.draw(sprite);
}

void GraphicsHandler::renderBoard(Board board) {
	Sprite background = *new Sprite(boardBackgroundTexture);
	background.setPosition({ origin.x - (5 * CELL_SIZE) , origin.y - (10 * CELL_SIZE) });
	window.draw(background);
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 20; y++) {
			Cell cell = board.get({ x,y });
			if (cell.isOccupied()) {
				Vector2f cellposition;
				cell.setColor(Color(0, 0, 255));
				cellPosition.x = origin.x + (CELL_SIZE * x) - (5 * CELL_SIZE);
				cellPosition.y = origin.y + (CELL_SIZE * y) - (10 * CELL_SIZE);
				renderCell(cell, cellposition);
			}

		}
	}
}
