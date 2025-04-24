#pragma once
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using sf::Text;

//class for the screen to display on player game over
class DeathScreen {
public:
	DeathScreen();
	void run(RenderWindow& window);

private:
	void displayDeathMessage(RenderWindow& window);
	void displayStartText(RenderWindow& window);

	sf::Font comicSans;
	Text died;
	Text start;
};

DeathScreen::DeathScreen() : comicSans("../../../../assets/ComicSansMS.ttf"), died(comicSans), start(comicSans) {

}

//display main menu through given window
void DeathScreen::run(RenderWindow& window) {
	window.clear();
	displayDeathMessage(window);
	displayStartText(window);

	window.display();
}

void DeathScreen::displayDeathMessage(RenderWindow& window) {
	died.setString("You Died :(");
	died.setCharacterSize(60);
	died.setPosition({ 800.0, 500.0 });
	window.draw(died);
}

void DeathScreen::displayStartText(RenderWindow& window) {
	start.setString("Press enter to try again, or ESC to exit!");
	start.setCharacterSize(20);
	start.setPosition({ 750 , 900 });
	window.draw(start);
}
