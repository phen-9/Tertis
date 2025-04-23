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
    current.setPosition({ 5, 19 });

    int ticksOnGround = 0;
  
    while (window.isOpen()) {
        delta = time.getElapsedTime() - prevTime;
        
        board->setCurrent(&current);

        if (delta >= tickRate) {
            if (board->moveBlock({ 0, -1 })) {
                // Not on ground
                ticksOnGround = 0;
            }
            else {
                ticksOnGround++;
                if (ticksOnGround >= 4) {
                    board->placeBlock();
                }
            }
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
