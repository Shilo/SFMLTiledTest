#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Window.h"
class Game
{
public:
	Map map;

	Game(Window& window);
	void render(Window& window);
	void positionView(Window& window);
};