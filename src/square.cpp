#include "square.hpp"

Square::Square()
{
	this->center = { 5, 20 };
	arr = new Vector2i[4];
	arr[1] = { 0, 1 };
	arr[2] = { 1, 0 };
	arr[3] = { 1, 1 };
	col = sf::Color::Yellow;
}
