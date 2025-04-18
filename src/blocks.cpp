#include "blocks.hpp"

// SQUARE FUNCTIONS
//  **
//  **
SquareBlock::SquareBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { 0, 1 };
	arr[1] = { 1, 0 };
	arr[2] = { 1, 1 };
	col = sf::Color::Yellow;
}

void SquareBlock::rotate()
{
	// Do nothing because squares cant rotate lol
}

// LINE FUNCTIONS
//  *
//  *
//  *
//  *
LineBlock::LineBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { 0, 1 };
	arr[1] = { 0, -1 };
	arr[2] = { 0, -2 };
	col = sf::Color{ 10, 224, 240 };
}

void LineBlock::rotate()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
	if (orientation % 2 == 0) {
		// Vertical
		arr[0] = { 0, 1 };
		arr[1] = { 0, -1 };
		arr[2] = { 0, -2 };
	}
	else {
		// Horizontal
		arr[0] = { 1, 0 };
		arr[1] = { -1, 0 };
		arr[2] = { -2, 0 };
	}
}

// L FUNCTIONS
//  *
//  *
//  **
LBlock::LBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { 0, 1 };
	arr[1] = { 0, -1 };
	arr[2] = { 1, -1 };
	col = sf::Color{ 255, 146, 3 };
}

void LBlock::rotate()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
	switch (orientation) {
	case 0:
		//  *
		//  *
		//  **
		arr[0] = { 0, 1 };
		arr[1] = { 0, -1 };
		arr[2] = { 1, -1 };
		break;
	case 1:
		//
		// ***
		// *
		arr[0] = { -1, -1 };
		arr[1] = { -1, 0 };
		arr[2] = { 1, 0 };
		break;
	case 2:
		// **
		//  *
		//  *
		arr[0] = { -1, 1 };
		arr[1] = { 0, 1 };
		arr[2] = { 0, -1 };
		break;
	case 3:
		//   *
		// ***
		//  
		arr[0] = { -1, 0 };
		arr[1] = { 1, 1 };
		arr[2] = { 1, 0 };
		break;
	}
}

// J FUNCTIONS
//  *
//  *
// **
JBlock::JBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { 0, 1 };
	arr[1] = { 0, -1 };
	arr[2] = { -1, -1 };
	col = sf::Color{ 21, 37, 209 };
}

void JBlock::rotate()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
	switch (orientation) {
	case 0:
		//  *
		//  *
		// **
		arr[0] = { 0, 1 };
		arr[1] = { 0, -1 };
		arr[2] = { -1, -1 };
		break;
	case 1:
		// *
		// ***
		// 
		arr[0] = { -1, 1 };
		arr[1] = { -1, 0 };
		arr[2] = { 1, 0 };
		break;
	case 2:
		//  **
		//  *
		//  *
		arr[0] = { 1, 1 };
		arr[1] = { 0, 1 };
		arr[2] = { 0, -1 };
		break;
	case 3:
		//   
		// ***
		//   *
		arr[0] = { -1, 0 };
		arr[1] = { 1, -1 };
		arr[2] = { 1, 0 };
		break;
	}
}

// T FUNCTIONS
//   *
//  ***
TBlock::TBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { -1, 0 };
	arr[1] = { 1, 0 };
	arr[2] = { 0, 1 };
	col = sf::Color{ 136, 27, 209 };
}

void TBlock::rotate()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
	switch (orientation) {
	case 0:
		//   *
		//  ***
		//
		arr[0] = { -1, 0 };
		arr[1] = { 1, 0 };
		arr[2] = { 0, 1 };
		break;
	case 1:
		//  *
		//  **
		//  *
		arr[0] = { 0, 1 };
		arr[1] = { 1, 0 };
		arr[2] = { 0, -1 };
		break;
	case 2:
		//  
		// ***
		//  *
		arr[0] = { -1, 0 };
		arr[1] = { 1, 0 };
		arr[2] = { 0, -1 };
		break;
	case 3:
		//  *
		// **
		//  *
		arr[0] = { 0, -1 };
		arr[1] = { 1, 0 };
		arr[2] = { 0, -1 };
		break;
	}
}

// S FUNCTIONS
//  **
// **
SBlock::SBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { 1, 0 };
	arr[1] = { 0, -1 };
	arr[2] = { -1, -1 };
	col = sf::Color{ 235, 40, 19 };
}

void SBlock::rotate()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
	if (orientation % 2 == 0) {
		//
		//  **
		// **
		arr[0] = { 1, 0 };
		arr[1] = { 0, -1 };
		arr[2] = { -1, -1 };
	}
	else {
		//  *
		//  **
		//   *
		arr[0] = { 0, 1 };
		arr[1] = { 1, 0 };
		arr[2] = { 1, -1 };
	}
}

// Z FUNCTIONS
//  **
//   **
ZBlock::ZBlock() {
	this->center = { 5, 20 };
	orientation = 0;
	arr = new Vector2i[3];
	arr[0] = { -1, 1 };
	arr[1] = { 0, -1 };
	arr[2] = { 1, 0 };
	col = sf::Color{ 72, 212, 34 };
}

void ZBlock::rotate()
{
	if (orientation < 3) { orientation++; }
	else { orientation = 0; }
	if (orientation % 2 == 0) {
		//
		// **
		//  **
		arr[0] = { -1, 1 };
		arr[1] = { 0, -1 };
		arr[2] = { 1, 0 };
	}
	else {
		//   *
		//  **
		//  *
		arr[0] = { 1, 1 };
		arr[1] = { 1, 0 };
		arr[2] = { 0, -1 };
	}
}