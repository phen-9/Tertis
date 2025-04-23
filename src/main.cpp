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
    Tetromino current = SquareBlock();
  
    while (window.isOpen()) {
        delta = time.getElapsedTime() - prevTime;
        std::cout << delta.asSeconds() << std::endl;

        if (delta >= tickRate) {
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
