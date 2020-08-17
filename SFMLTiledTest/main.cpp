#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode().getDesktopMode(), "SFML Tiled Test", sf::Style::None);

    Game game;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear();
        game.loop(window);
        window.display();
    }

    return 0;
}