#include <SFML/Graphics.hpp>
#include <math.h>

using sf::Vector2f;
using sf::Clock;
using sf::Time;

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    Clock time;
    Time prevTime;
    time.start();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        Time delta = time.getElapsedTime() - prevTime;
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        
        //wiggle circle x position on a sin wave based on time
        double x = 8 * sin(time.getElapsedTime().asMilliseconds() * 0.01);
        Vector2f pos(x, shape.getPosition().y);
        shape.setPosition(pos);

        window.clear();
        window.draw(shape);
        window.display();
    }
}
