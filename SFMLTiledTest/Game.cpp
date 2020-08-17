#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"

const std::string& MAP_FILENAME = "island.tmx";
int moveSpeed = 10;

Game::Game(Window& window)
{
    map.load(MAP_FILENAME);
    if (map.loaded) {
        tmx::FloatRect bounds = map.map.getBounds();
        centerX = bounds.width / 2;
        centerY = bounds.height / 2;
    }

    positionView(window);
}

void Game::render(Window& window)
{
    map.render(window);
    positionView(window);
}

void Game::positionView(Window& window)
{
    window.setViewCenter(centerX, centerY);
}

void Game::onEvent(sf::Event event, Window& window) {
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            centerX -= moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            centerX += moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            centerY -= moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            centerY += moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            if (map.loaded) {
                tmx::FloatRect bounds = map.map.getBounds();
                centerX = bounds.width / 2;
                centerY = bounds.height / 2;
                positionView(window);
            }

        }
    }
}