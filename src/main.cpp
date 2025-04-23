#include <SFML/Graphics.hpp>
#include "board.hpp"
#include <math.h>
#include <iostream>
#include "blocks.hpp"

using sf::Vector2f;
using sf::Clock;
using sf::Time;

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    Clock time;
    time.start();
    Vector2f midpoint;
    midpoint.x = (double)window.getSize().x / 2;
    midpoint.y = (double)window.getSize().y / 2;
    Board* board = new Board(midpoint);
    Time prevTime;
    Time delta;
    Time tickRate = sf::seconds(1.0f);
    Tetromino current = TBlock();
    current.setPosition({ 6,6 });
  
    while (window.isOpen()) {
        delta = time.getElapsedTime() - prevTime;
        std::cout << delta.asSeconds() << std::endl;
        
        board->setCurrent(current);

        if (delta >= tickRate) {
            board->update();
            prevTime = time.getElapsedTime();
            window.clear();
            board->draw(window);
            window.display();
        }
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();

            }
        }
    }
    delete board;
}
