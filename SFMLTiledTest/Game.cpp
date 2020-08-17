#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include <algorithm>
#include <string>

const std::string& MAP_FILENAME = "assets/map.tmx";
const std::string& FONT_FILENAME = "assets/arial.ttf";
int moveSpeed = 10;
float scrollSensitivity = 0.1f;

Game::Game(Window& window)
{
    loadMap();
    loadGUI(window);

    positionView(window);
}

void Game::loadMap()
{
    map.load(MAP_FILENAME);
    if (map.loaded) {
        tmx::FloatRect bounds = map.map.getBounds();
        centerX = bounds.width / 2;
        centerY = bounds.height / 2;
    }
}

void Game::loadGUI(Window& window)
{
    if (font.loadFromFile(FONT_FILENAME)) {
        std::string windowTitle = window.title;
        std::transform(windowTitle.begin(), windowTitle.end(), windowTitle.begin(), ::toupper);

        std::string mapFileName = MAP_FILENAME;
        std::transform(mapFileName.begin(), mapFileName.end(), mapFileName.begin(), ::toupper);

        std::string mapText = map.loaded ? "MAP = " + mapFileName : "[ERROR] FAILED TO LOAD MAP = " + mapFileName;

        instructions.setFont(font);
        instructions.setString(windowTitle + "\n\nPAN = WASD/ARROW KEYS\nZOOM = MOUSE WHEEL UP/DOWN\nRESET PAN = SPACEBAR KEY\nRESET ZOOM = MOUSE WHEEL CLICK\nEXIT = ESC KEY\n\n" + mapText);
        instructions.setPosition(10, 10);
        instructions.setCharacterSize(14);
        instructions.setFillColor(sf::Color::White);
        instructions.setOutlineColor(sf::Color::Black);
        instructions.setOutlineThickness(2);
    }
}

void Game::render(Window& window)
{
    map.render(window);
    positionView(window);
}

void Game::renderGUI(Window& window)
{
    window.draw(instructions);
}

void Game::positionView(Window& window)
{
    window.setViewCenter(centerX, centerY);
}

void Game::onEvent(sf::Event event, Window& window) {
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            centerX -= moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            centerX += moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            centerY -= moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            centerY += moveSpeed;
            positionView(window);
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            if (map.loaded) {
                tmx::FloatRect bounds = map.map.getBounds();
                centerX = bounds.width / 2;
                centerY = bounds.height / 2;
                positionView(window);
            }
        }
    }
    else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
    {
        float scrollDelta = -event.mouseWheelScroll.delta * scrollSensitivity;
        window.zoomFactor = std::min(std::max(0.1f, window.zoomFactor+scrollDelta), 5.0f);
    }
    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
    {
        window.zoomFactor = defaultZoom;
    }
}