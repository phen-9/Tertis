
#include "cell.hpp"

//implement cell class

Cell::Cell() {
	occupied = false;
	placed = false;
	color = *new Color();
	
}

Color Cell::getColor() {
	return color;
}

void Cell::setColor(Color newColor) {
	color = newColor;
}

void Cell::setOccupied(bool isOccupied) {
	occupied = isOccupied;
}

bool Cell::isOccupied() {
	return occupied;
}

void Cell::setPlaced(bool isPlaced) {
	placed = isPlaced;
}

bool Cell::isPlaced()
{
	return placed;
}


