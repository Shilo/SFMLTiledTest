#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Window : public sf::RenderWindow
{
public:
	Game *game;

	Window();
	Window(bool fullscreen, float zoomFactor);
	void update();
	void render();
	void setViewCenter(int x, int y);

private:
	float zoomFactor = 1.0f;
	int viewCenterX = 0;
	int viewCenterY = 0;
};