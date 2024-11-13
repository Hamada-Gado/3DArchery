#include <glut.h>

#include "include/keyhandler.h"
#include "include/game.h"

KeyHandler::KeyHandler(Game &game) : game(game) {}

void KeyHandler::keyDown(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}