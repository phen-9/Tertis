
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include <math.h>
#include <iostream>
#include "blocks.hpp"
#include "blockqueue.hpp"
#include "inputhandler.hpp"

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
    InputHandler input(time);
    BlockQueue queue;
    Tetromino* current = new TBlock();
    current->setPosition({ 5, 19 });

    sf::Keyboard::Scan pastKeyPress = sf::Keyboard::Scan::F1;
    sf::Keyboard::Scan pastRotation = sf::Keyboard::Scan::F1;

    int ticksOnGround = 0;
  
    while (window.isOpen()) {
        delta = time.getElapsedTime() - prevTime;
        
        board->setCurrent(current);

        if (delta >= tickRate) {
            if (board->moveBlock({ 0, -1 })) {
                // Not on ground
                ticksOnGround = 0;
            }
            else {
                ticksOnGround++;
                if (ticksOnGround >= 4) {
                    board->placeBlock();
                    current = queue.getBlock();
                    board->setCurrent(current);
                    ticksOnGround = 0;
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
        if (input.canMoveX()) {
            board->moveBlock({ input.getArrowInput().x, 0 });
            board->update();
            window.clear();
            board->draw(window);
            window.display();
        }
        if (input.canMoveY()) {
            board->moveBlock({ 0, input.getArrowInput().y });
            board->update();
            window.clear();
            board->draw(window);
            window.display();
        }


        // ROTATION HANDLER
        if (input.canRotate()) {
            board->rotateBlock(input.getRotate());
            board->update();
            window.clear();
            board->draw(window);
            window.display();
        }
        

        input.updateLastVals();

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
