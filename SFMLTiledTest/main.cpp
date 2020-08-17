#include "Utils.h"
#include "Game.h"
#include "Window.h"

const bool FULLSCREEN = true;
const float ZOOM_FACTOR = 1.0f;

Window *window;
Game *game;

void init()
{
    window = new Window(FULLSCREEN, ZOOM_FACTOR);
    game = new Game((*window));
}

void render()
{
    (*window).render();
    (*game).render((*window));
    (*window).display();
}

void destroy()
{
    delete game;
    delete window;
}

int main()
{
    init();

    while ((*window).isOpen())
    {
        render();
    }
    
    destroy();

    return 0;
}