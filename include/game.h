#pragma once

#include "keyhandler.h"
#include "camera.h"
#include "player.h"
#include "arrow.h"
#include "target.h"
#include "bow.h"
#include "quiver.h"
#include "traning_dummy.h"
#include "table.h"

class Game
{
public:
    Game();
    void update();
    void render() const;
    void shoot();
    void setFrontView();
    void setSideView();
    void setTopView();

    const int WINDOW_WIDTH, WINDOW_HEIGHT, FPS;
    const float GAME_TIME = 100.0f;

    int mode = 0; // 0 - camera, 1 - player
    bool gameOver = false;
    int score = 0;
    float time = GAME_TIME;
    bool arrowShot = false;
    float boundariesColors[2][3] = {{0.9f, 0.9f, 0.9f}, {0.6f, 0.6f, 0.6f}};
    float boundariesColorsDx = -0.01;

    Camera camera;
    KeyHandler keyHandler;

    Player player;
    Arrow arrow;
    ArcheryTarget target;

    Bow bow;
    Arrow arrowSecondary;
    Quiver quiver;
    TrainingDummy dummy;
    Table table;

    float quiverScaleDx = 0.01f;
    float tableColorDx = -0.01f;
    float dummyPositionDx = 0.01f;
    float targetColorDx = -0.01f;

    bool arrowAnimation = false;
    bool bowAnimation = false;
    bool quiverAnimation = false;
    bool dummyAnimation = false;
    bool tableAnimation = false;
};