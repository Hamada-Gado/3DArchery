#include <cmath>
#include <glut.h>

#include "include/util.h"

#include "include/game.h"

#include "include/player.h"

#include "include/vector3f.h"
#include "include/camera.h"

Game game;

void display()
{
    util::setupCamera(game.WINDOW_WIDTH, game.WINDOW_HEIGHT, game.camera);
    util::setupLights();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    game.render();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    game.keyHandler.keyDown(key, x, y);
    glutPostRedisplay();
}

void update(int value)
{
    game.update();
    glutPostRedisplay();
    glutTimerFunc(1000 / game.FPS, update, 0);
}

void special(int key, int x, int y)
{
    game.keyHandler.specialKeyDown(key, x, y);
    glutPostRedisplay();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(game.WINDOW_WIDTH, game.WINDOW_HEIGHT);
    glutCreateWindow("Bulls Eye");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutTimerFunc(0, update, 0);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);

    glutMainLoop();
}