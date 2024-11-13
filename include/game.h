#pragma once

#include "keyhandler.h"
#include "camera.h"

class Game
{
public:
    Game();
    void update();
    void render() const;
    int getWidth() const;
    int getHeight() const;
    int getFPS() const;
    Camera &getCamera();

private:
    const int WINDOW_WIDTH, WINDOW_HEIGHT, FPS;
    Camera camera;
    KeyHandler keyHandler;
};