#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"

const std::string& MAP_FILENAME = "island.tmx";

Game::Game()
{
    map.load(MAP_FILENAME);
}

void Game::render(sf::RenderWindow &window)
{
    map.render(window);
}