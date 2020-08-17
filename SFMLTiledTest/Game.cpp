#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"

const std::string& MAP_FILENAME = "island.tmx";

Game::Game(Window& window)
{
    map.load(MAP_FILENAME);
    positionView(window);
}

void Game::render(Window& window)
{
    map.render(window);
    positionView(window);
}

void Game::positionView(Window& window)
{
    if (!map.loaded) return;

    tmx::FloatRect bounds = map.map.getBounds();
    window.setViewCenter(bounds.width / 2, bounds.height / 2);
}