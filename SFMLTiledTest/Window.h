#pragma once
#include <SFML/Graphics.hpp>
class Window : public sf::RenderWindow
{
public:
	Window();
	Window(bool fullscreen, float zoomFactor);
	void update();
	void render();

	float zoomFactor = 1.0f;
};