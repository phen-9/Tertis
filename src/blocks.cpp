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
	col = sf::Color(255, 255, 0);
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
	col = sf::Color{ 62, 250, 255 };
}

void LineBlock::rotate()
{
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
	col = sf::Color{ 255, 159, 0 };
}

void LBlock::rotate()
{
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
	col = sf::Color{ 0, 62, 255 };
}

void JBlock::rotate()
{
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
	col = sf::Color{ 197, 73, 255 };
}

void TBlock::rotate()
{
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
		arr[0] = { 0, 1 };
		arr[1] = { -1, 0 };
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
	col = sf::Color{ 62, 255, 51 };
}

void SBlock::rotate()
{
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
	arr[0] = { -1, 0 };
	arr[1] = { 0, -1 };
	arr[2] = { 1, -1 };
	col = sf::Color{ 255, 31, 31 };
}

void ZBlock::rotate()
{
	if (orientation % 2 == 0) {
		//
		// **
		//  **
		arr[0] = { -1, 0 };
		arr[1] = { 0, -1 };
		arr[2] = { 1, -1 };
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