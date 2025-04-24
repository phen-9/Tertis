/*
* Class: Cpts 122
* Professor: Andrew O'Fallon
* Assignment: PA9
* TA: Melvin Manning
* Lab Section: 8
* Due: 4/23/25
* Programmers: Gavin Gaetos-Puzon, Logan Spinali
* Description: Runs the game of Tertis (a legally distinct version of tetris)
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "board.hpp"
#include <math.h>
#include <iostream>
#include "blocks.hpp"
#include "blockqueue.hpp"
#include "inputhandler.hpp"
#include "mainmenu.hpp"
#include "deathscreen.hpp"

#include "testcases/holdblocktest.hpp"
#include "testcases/blockqueuetest.hpp"
#include "testcases/scoringtest.hpp"

using sf::Vector2f;
using sf::Clock;
using sf::Time;

int main()
{
   
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Tertis");
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

    int state = 0;
    //state 1: menu, 2: gameplay, 3: death

    MainMenu menu;
    DeathScreen death;

    sf::Music mus("../../../../assets/TertisTheme.ogg");
    sf::SoundBuffer buff("../../../../assets/death.mp3");
    sf::Sound s(buff);
    s.setVolume(80);
    mus.setVolume(60);
    mus.setLooping(true);
    mus.play();

    int ticksOnGround = 0;
  
    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        if (state == 0) {
            //menu state
            menu.run(window);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter)) {
                state = 1;
                time.start();
            }

        }
        else if(state == 1) {
            //gameplay state

            //1 physics tick every 1 second/ the cubed root of the elapsed seconds
            tickRate = sf::seconds(1.0 / (cbrt(time.getElapsedTime().asSeconds())));

            delta = time.getElapsedTime() - prevTime;

            if (delta >= tickRate) {
                if (board->moveBlock({ 0, -1 })) {
                    // Not on ground
                    ticksOnGround = 0;
                }
                else {
                    ticksOnGround++;
                    if (ticksOnGround >= 3) {
                        board->update(window);
                        if (board->checkDeath()) {
                            s.play();
                            state = 2;
                        }
                        board->placeBlock();
                        
                        ticksOnGround = 0;
                    }
                }
                board->update(window);
                prevTime = time.getElapsedTime();
            }

            //QUICKDROP
            if (input.canQuickDrop()) {
                while (board->moveBlock({ 0,-1 }));
                board->update(window);
                if (board->checkDeath()) {
                    state = 2;
                }
                board->placeBlock();
               
            }

            //HOLD BLOCK
            if (input.canHold()) {
                board->holdBlock();
                board->update(window);
            }

            // MOVEMENT HANDLER
            if (input.canMoveX()) {
                board->moveBlock({ input.getArrowInput().x, 0 });
                board->update(window);
            }
            if (input.canMoveY()) {
                board->moveBlock({ 0, input.getArrowInput().y });
                board->update(window);

            }



            // ROTATION HANDLER
            if (input.canRotate()) {
                board->rotateBlock(input.getRotate());
                board->update(window);

            }

            input.updateLastVals();
        }
        else {
            //game over state
            death.run(window);
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter)) {
                state = 1;
                board->reset();
                time.start();
            }
        }

    }
    delete board;
}
