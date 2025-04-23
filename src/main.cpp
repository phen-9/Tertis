#include <SFML/Graphics.hpp>
#include "board.hpp"
#include <math.h>

using sf::Vector2f;
using sf::Clock;
using sf::Time;

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    Clock time;
    Time prevTime;
    time.start();
    Vector2f midpoint;
    midpoint.x = (double)window.getSize().x / 2;
    midpoint.y = (double)window.getSize().y / 2;
    Board board = *new Board(midpoint);
  

    while (window.isOpen()) {
        Time delta = time.getElapsedTime() - prevTime;
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();

            }


            window.clear();
            board.draw(window);

            window.display();
        }

    }
}
