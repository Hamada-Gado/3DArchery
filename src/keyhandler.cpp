#include <glut.h>

#include "include/keyhandler.h"
#include "include/game.h"

KeyHandler::KeyHandler(Game &game) : game(game) {}

void KeyHandler::keyDown(unsigned char key, int x, int y)
{
    float d = 0.5;
    float a = 3.0;

    Camera &camera = game.camera;

    switch (key)
    {
    case 'r':
        game.mode = 0;
        game.gameOver = false;
        game.score = 0;
        game.time = game.GAME_TIME;
        return;
    case 'c':
        game.mode = 0;
        return;
    case 'p':
        game.mode = 1;
        return;
    case '1':
        game.setFrontView();
        return;
    case '2':
        game.setSideView();
        return;
    case '3':
        game.setTopView();
        return;
    case '4':
        game.arrowAnimation = !game.arrowAnimation;
        return;
    case '5':
        game.bowAnimation = !game.bowAnimation;
        return;
    case '6':
        game.quiverAnimation = !game.quiverAnimation;
        return;
    case '7':
        game.dummyAnimation = !game.dummyAnimation;
        return;
    case '8':
        game.tableAnimation = !game.tableAnimation;
        return;
    case 27:
        exit(0);
    }

    if (game.mode == 0)
        switch (key)
        {
        case 'w':
            camera.moveY(d);
            return;
        case 's':
            camera.moveY(-d);
            return;
        case 'a':
            camera.moveX(d);
            return;
        case 'd':
            camera.moveX(-d);
            return;
        case 'q':
            camera.moveZ(d);
            return;
        case 'e':
            camera.moveZ(-d);
            return;
        default:
            return;
        }

    if (game.mode == 1)
        switch (key)
        {
        case ' ':
            game.shoot();
            return;
        case 'k':
            game.player.rotateRightArmX(-a);
            return;
        case 'j':
            game.player.rotateRightArmX(a);
            return;
        case 'w':
            game.player.moveForward(d);
            return;
        case 's':
            game.player.moveForward(-d);
            return;
        case 'a':
            game.player.moveSideway(d);
            return;
        case 'd':
            game.player.moveSideway(-d);
            return;
        case 'q':
            game.player.rotateY(a);
            return;
        case 'e':
            game.player.rotateY(-a);
            return;
        default:
            return;
        }
}

void KeyHandler::specialKeyDown(int key, int x, int y)
{
    float a = 3.0;
    Camera &camera = game.camera;
    if (game.mode == 0)
        switch (key)
        {
        case GLUT_KEY_UP:
            camera.rotateX(a);
            return;
        case GLUT_KEY_DOWN:
            if (game.mode == 0)
                camera.rotateX(-a);
            return;
        case GLUT_KEY_LEFT:
            camera.rotateY(a);
            return;
        case GLUT_KEY_RIGHT:
            camera.rotateY(-a);
            return;
        case GLUT_KEY_PAGE_UP:
            camera.rotateZ(a);
            return;
        case GLUT_KEY_PAGE_DOWN:
            camera.rotateZ(-a);
            return;
        default:
            return;
        }

    if (game.mode == 1)
        switch (key)
        {
        default:
            return;
        }
}