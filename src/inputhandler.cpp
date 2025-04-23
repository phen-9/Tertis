
#include "inputhandler.hpp"
#include <iostream>
using std::cout;

InputHandler::InputHandler(Clock &newTime) {
	time = newTime;
	lastArrowInput = { 0,0 };
	lastRotate = 0;
	lastHold = false;
	lastQuickDrop = false;
}

Vector2i InputHandler::getArrowInput() {
	int x = 0, y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
		x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
		x++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
		y--;
	}
	return {x, y};
}

bool InputHandler::canMoveX() {
	//movement key pressed
	int x = getArrowInput().x;
	if (x != 0) {
		//holding down button (button was pressed last loop, last initial press was long enough ago):
		if (lastArrowInput.x == x) {
			if (time.getElapsedTime() - lastXMovePress >= sf::seconds(0.2)) {
				lastXMovePress = time.getElapsedTime();
				return true;
			}
		}
		//buton was not pressed last loop
		else {
			lastXMovePress = time.getElapsedTime();
			return true;
		}
	}	
	return false;
}

bool InputHandler::canMoveY() {
	//movement key pressed
	int y = getArrowInput().y;
	if (y != 0) {
		//holding down button (button was pressed last loop, last initial press was long enough ago):
		if (lastArrowInput.y == y) {
			if (time.getElapsedTime() - lastYMovePress >= sf::seconds(0.3)) {
				lastYMovePress = time.getElapsedTime();
				return true;
			}
		}
		//buton was not pressed last loop
		else {
			lastYMovePress = time.getElapsedTime();

			return true;
		}
	}
	return false;
}

bool InputHandler::canRotate() {
	int r = getRotate();
	return r != 0 && lastRotate != r;
}

int InputHandler::getRotate() {
	int r = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Z)) {
		r--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::X)) {
		r++;
	}
	return r;
}

bool InputHandler::canQuickDrop() {
	bool q = getQuickDrop();

	return q && lastQuickDrop != q;
}
bool InputHandler::canHold() {
	bool q = getQuickDrop();

	return q && lastQuickDrop != q;
}

bool InputHandler::getQuickDrop() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up);
}

bool InputHandler::getHold() {
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left);
}

void InputHandler::updateLastVals() {
	lastArrowInput = getArrowInput();
	lastHold = getHold();
	lastRotate = getRotate();
	lastQuickDrop = getQuickDrop();
}