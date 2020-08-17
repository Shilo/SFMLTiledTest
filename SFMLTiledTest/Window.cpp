#include "Window.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Game.h"

Window::Window()
   : sf::RenderWindow(sf::VideoMode().getDesktopMode(),
        "SFML Tiled Test",
        sf::Style::None)
{
    update();
}

Window::Window(bool fullscreen, float zoomFactor)
    : sf::RenderWindow(fullscreen ? sf::VideoMode().getDesktopMode() : sf::VideoMode(1024, 768),
        "SFML Tiled Test",
        fullscreen ? sf::Style::None : sf::Style::Default)
{
    this->zoomFactor = zoomFactor;
    update();
}

void Window::update()
{
    sf::FloatRect visibleArea(0, 0, getSize().x * zoomFactor, getSize().y * zoomFactor);
    sf::View view = sf::View(visibleArea);
    view.setCenter(sf::Vector2f(viewCenterX, viewCenterY));
    setView(view);
}

void Window::render()
{
    sf::Event event;
    while (pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
            close();
        else if (event.type == sf::Event::Resized)
        {
            update();
        }
        else if (game != NULL) {
            game->onEvent(event, *this);
        }
    }
    clear();
}

void Window::setViewCenter(int x, int y) {
    viewCenterX = x;
    viewCenterY = y;
    update();
}