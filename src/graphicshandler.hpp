
#pragma once
#include <SFML/Graphics.hpp>
#include "board.hpp"

using std::string;
using sf::Texture;

class GraphicsHandler {
public:
	GraphicsHandler(RenderWindow &newWindow);

	void renderCell(Cell cell, sf::Vector2f position);
	void renderBoard(Board board);

private:
	RenderWindow window;
	string assetPath;
	Texture cellTexture;
	Texture boardBackgroundTexture;
};