#include <SFML/Graphics.hpp>
#include "board.hpp"
#include <math.h>
#include <iostream>
#include "blocks.hpp"
#include "blockqueue.hpp"

using sf::Vector2f;
using sf::Clock;
using sf::Time;

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    BlockQueue queue;

    Clock time;
    time.start();
    Vector2f midpoint;
    midpoint.x = (double)window.getSize().x / 2;
    midpoint.y = (double)window.getSize().y / 2;
    Board* board = new Board(midpoint);
    Time prevTime;
    Time delta;
    Time tickRate = sf::seconds(1.0f);
    Tetromino* current = new TBlock();
    current->rotate();
    current->setPosition({ 5, 19 });

    sf::Keyboard::Scan pastKeyPress = sf::Keyboard::Scan::F1;
    sf::Keyboard::Scan pastRotation = sf::Keyboard::Scan::F1;

    int ticksOnGround = 0;
  
    while (window.isOpen()) {
        delta = time.getElapsedTime() - prevTime;
        
        board->setCurrent(current);

        if (delta >= tickRate) {
            queue.getBlock();
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
            queue.draw(window);
            board->draw(window);
            window.display();
        }
        
        // MOVEMENT HANDLER
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
        {
            if (pastKeyPress != sf::Keyboard::Scan::Left) {
                pastKeyPress = sf::Keyboard::Scan::Left;
                board->moveBlock({ -1, 0 });
                board->update();
                window.clear();
                board->draw(window);
                window.display();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
        {
            if (pastKeyPress != sf::Keyboard::Scan::Right) {
                pastKeyPress = sf::Keyboard::Scan::Right;
                board->moveBlock({ 1, 0 });
                board->update();
                window.clear();
                board->draw(window);
                window.display();
            }
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
            pastKeyPress = sf::Keyboard::Scan::F1;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            pastKeyPress = sf::Keyboard::Scan::F1;
        }

        // ROTATION HANDLER
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Z))
        {
            if (pastRotation != sf::Keyboard::Scan::Z) {
                pastRotation = sf::Keyboard::Scan::Z;
                board->rotateBlock(true);
                board->update();
                window.clear();
                board->draw(window);
                window.display();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::X))
        {
            if (pastRotation != sf::Keyboard::Scan::X) {
                pastRotation = sf::Keyboard::Scan::X;
                board->rotateBlock(false);
                board->update();
                window.clear();
                board->draw(window);
                window.display();
            }
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Z)) {
            pastRotation = sf::Keyboard::Scan::F1;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::X)) {
            pastRotation = sf::Keyboard::Scan::F1;
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
