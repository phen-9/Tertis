
#pragma once
#include <SFML/Graphics.hpp>


using sf::Vector2i;
using sf::Time;
using sf::Clock;

class InputHandler {
public:
	InputHandler(Clock &time);
	Vector2i getArrowInput();
	bool canMoveX();
	bool canMoveY();
	bool canRotate();
	int getRotate();
	bool getHold();
	void updateLastVals();

private:
	Clock time;
	Time lastXMovePress;
	Time lastYMovePress;
	Vector2i lastArrowInput;
	int lastRotate;
	bool lastHold;

};