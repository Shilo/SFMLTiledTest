#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"

Game::Game() {
    map.load("demo.tmx");
}

void Game::render(sf::RenderWindow &window) {
    map.render(window);
}