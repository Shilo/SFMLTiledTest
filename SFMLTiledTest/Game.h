#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public:
	Game();
	void loop(sf::RenderWindow &window);
private:
	void renderMap(sf::RenderWindow& window);
};