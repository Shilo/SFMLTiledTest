#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML Tiled Test");

    Game game;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        game.loop(window);
        window.display();
    }

    return 0;
}