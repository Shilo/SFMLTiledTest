#pragma once
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
class Map
{
public:
	tmx::Map map;
	bool loaded;

	bool load(const std::string& fileName);
	void render(sf::RenderWindow& window);
};

