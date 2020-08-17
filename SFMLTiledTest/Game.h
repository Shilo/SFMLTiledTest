#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
class Game
{
public:
	Map map;

	Game();
	void render(sf::RenderWindow &window);
private:
	void renderMap(sf::RenderWindow& window);
};