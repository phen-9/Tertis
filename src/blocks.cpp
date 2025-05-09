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
	id = 0;
}

void SquareBlock::rotate()
{
	// Do nothing because squares cant rotate lol
}

SquareBlock* SquareBlock::clone()
{
	return new SquareBlock(*this);
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
	id = 1;
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

LineBlock* LineBlock::clone()
{
	return new LineBlock(*this);;
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
	id = 2;
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

LBlock* LBlock::clone()
{
	return new LBlock(*this);;
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
	id = 3;
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

JBlock* JBlock::clone()
{
	return new JBlock(*this);;
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
	id = 4;
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

TBlock* TBlock::clone()
{
	return new TBlock(*this);;
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
	id = 5;
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

SBlock* SBlock::clone()
{
	return new SBlock(*this);;
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
	id = 6;
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

ZBlock* ZBlock::clone()
{
	return new ZBlock(*this);;
}
