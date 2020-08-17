#include "Map.h"
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFMLOrthogonalLayer.hpp"
#include "Utils.h"

bool Map::load(const std::string& fileName)
{
    loaded = map.load("assets/maps/"+ fileName);
    if (!loaded) {
        Utils::log("Error: Map failed to load.");
    }
    return loaded;
}

void Map::render(sf::RenderWindow& window)
{
    if (!loaded) return;

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