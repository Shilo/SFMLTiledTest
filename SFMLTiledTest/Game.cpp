#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFMLOrthogonalLayer.hpp"

tmx::Map map;
boolean mapLoaded = false;

Game::Game() {
    mapLoaded = map.load("assets/maps/demo.tmx");
    if (!mapLoaded) {
        Utils::log("Error: Map failed to load.");
    }
}

void Game::loop(sf::RenderWindow &window) {
    renderMap(window);
}

void Game::renderMap(sf::RenderWindow& window) {
    if (!mapLoaded) return;

    const auto& layers = map.getLayers();
    int layerIndex = 0;

    for (const auto& layer : layers)
    {
        if (layer->getType() == tmx::Layer::Type::Tile)
        {
            MapLayer mapLayer(map, layerIndex);
            window.draw(mapLayer);
        }
        layerIndex++;
    }
}