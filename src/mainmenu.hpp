#pragma once
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using sf::Text;


//menu displayed upon opening the game
class MainMenu {
public:
	MainMenu();
	void run(RenderWindow& window);

private:
	void displayControls(RenderWindow& window);
	void displayStartText(RenderWindow& window);

	Texture tex;
	Sprite sprite;
	sf::Font comicSans;
	Text controls;
	Text start;
	Clock time;
};

MainMenu::MainMenu() : tex("../../../../assets/logo.png"), sprite(tex), comicSans("../../../../assets/ComicSansMS.ttf"), controls(comicSans), start(comicSans) {
	sprite.setOrigin({ 864.0 / 2,160.0 / 2 });
	sprite.setPosition({ 960.0, 150.0 });
	time.start();
}

//display main menu through given window
void MainMenu::run(RenderWindow& window) {
	window.clear();
	window.draw(sprite);
	displayControls(window);
	sprite.setPosition({ 960.0, 150 + (20 * sin(time.getElapsedTime().asSeconds()))});
	displayStartText(window);

	
	window.display();
}

void MainMenu::displayControls(RenderWindow& window) {
	controls.setString("Controls:\nMove Block: Arrow keys\nQuick Drop: Up Arrow\nRotate Left/Right: Z/X\nHold Block: C\nExit Game: ESC");
	controls.setCharacterSize(25);
	controls.setPosition({20.0, 800.0});
	window.draw(controls);
}

void MainMenu::displayStartText(RenderWindow& window) {
	start.setString("Press enter to play!");
	start.setCharacterSize(20);
	start.setPosition({850, 900});
	window.draw(start);
}
