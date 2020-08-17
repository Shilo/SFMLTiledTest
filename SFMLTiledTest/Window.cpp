#include "Window.h"
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Game.h"

const std::string& VERSION = "1.0";
const std::string& TITLE = "SFML Tiled Test - " + VERSION;

Window::Window()
   : sf::RenderWindow(sf::VideoMode().getDesktopMode(),
       TITLE,
        sf::Style::None)
{
    title = TITLE;
    update();
}

Window::Window(bool fullscreen, float zoomFactor)
    : sf::RenderWindow(fullscreen ? sf::VideoMode().getDesktopMode() : sf::VideoMode(1024, 768),
        TITLE,
        fullscreen ? sf::Style::None : sf::Style::Default)
{
    title = TITLE;
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

void Window::renderGUI()
{
    sf::View lastView = getView();
    sf::FloatRect visibleArea(0, 0, getSize().x, getSize().y);
    sf::View view = sf::View(visibleArea);
    setView(view);

    game->renderGUI(*this);

    setView(lastView);
}

void Window::setViewCenter(int x, int y) {
    viewCenterX = x;
    viewCenterY = y;
    update();
}