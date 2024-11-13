#include "include/game.h"

Game::Game() : WINDOW_WIDTH(640), WINDOW_HEIGHT(480), FPS(60),
               camera(0.0f, 3.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f),
                keyHandler(*this) {}

int Game::getWidth() const
{
    return WINDOW_WIDTH;
}

int Game::getHeight() const
{
    return WINDOW_HEIGHT;
}

int Game::getFPS() const
{
    return FPS;
}

Camera &Game::getCamera()
{
    return camera;
}