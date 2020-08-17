#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Window.h"
class Game
{
public:
	Map map;
	int centerX;
	int centerY;
	float defaultZoom;

	Game(Window& window);
	void loadMap();
	void loadGUI(Window& window);
	void render(Window& window);
	void renderGUI(Window& window);
	void positionView(Window& window);
	void onEvent(sf::Event event, Window& window);

private:
	sf::Font font;
	sf::Text instructions;
};