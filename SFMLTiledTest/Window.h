#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Window : public sf::RenderWindow
{
public:
	Game *game;
	float zoomFactor = 1.0f;

	Window();
	Window(bool fullscreen, float zoomFactor);
	void update();
	void render();
	void renderGUI();
	void setViewCenter(int x, int y);

private:
	int viewCenterX = 0;
	int viewCenterY = 0;
};