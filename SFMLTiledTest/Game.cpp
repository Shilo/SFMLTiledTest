#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"

sf::CircleShape shape(100.f);

Game::Game() {
	log("Game init");
	shape.setFillColor(sf::Color::Green);
}

void Game::loop(sf::RenderWindow &window) {
	log("Game loop");
	window.draw(shape);
}