#pragma once
#include "cell.hpp"

class Board {
public:

	void draw();

private:
	Cell cells[10][20];
	int origin;
};