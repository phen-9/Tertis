#include "blocks.hpp"

// SQUARE FUNCTIONS
//  **
//  **
SquareBlock::SquareBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { 0, 1 };
	arr[1] = { 1, 0 };
	arr[2] = { 1, 1 };
	col = sf::Color::Yellow;
}

// LINE FUNCTIONS
//  *
//  *
//  *
//  *
LineBlock::LineBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { 0, 1 };
	arr[1] = { 0, -1 };
	arr[2] = { 0, -2 };
	col = sf::Color{ 10, 224, 240 };
}

// L FUNCTIONS
//  *
//  *
//  **
LBlock::LBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { 0, 2 };
	arr[1] = { 0, 1 };
	arr[2] = { 1, 0 };
	col = sf::Color{ 255, 146, 3 };
}

// J FUNCTIONS
//  *
//  *
// **
JBlock::JBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { 0, 2 };
	arr[1] = { 0, 1 };
	arr[2] = { -1, 0 };
	col = sf::Color{ 21, 37, 209 };
}

// T FUNCTIONS
//   *
//  ***
TBlock::TBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { -1, 0 };
	arr[1] = { 1, 0 };
	arr[2] = { 0, 1 };
	col = sf::Color{ 136, 27, 209 };
}

// S FUNCTIONS
//   **
//  **
SBlock::SBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { 1, 1 };
	arr[1] = { 0, 1 };
	arr[2] = { -1, 0 };
	col = sf::Color{ 235, 40, 19 };
}

// Z FUNCTIONS
//  **
//   **
ZBlock::ZBlock() {
	this->center = { 5, 20 };
	arr = new Vector2i[3];
	arr[0] = { -1, 1 };
	arr[1] = { 0, 1 };
	arr[2] = { 1, 0 };
	col = sf::Color{ 72, 212, 34 };
}