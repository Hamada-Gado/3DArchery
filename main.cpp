#include <iostream>
#include <cmath>
#include <glut.h>

#include "include/game.h"

#include "include/vector3f.h"
#include "include/camera.h"

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

using namespace std;

Game game;

// Archery field dimensions
const float FIELD_WIDTH = 10.0f;
const float FIELD_LENGTH = 20.0f;
const float FIELD_HEIGHT = 1.0f;

// Target dimensions
const float TARGET_RADIUS = 0.5f;
const float TARGET_HEIGHT = 1.0f;

// Arrow parameters
float arrowX = 0.0f, arrowY = 0.5f, arrowZ = 0.0f;
float arrowVelocity = 1.0f;
float arrowAngle = 0.0f;
bool arrowShot = false;

void setupLights()
{
    GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
    GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
    GLfloat shininess[] = { 50 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
    GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)game.getWidth() / game.getHeight(), 0.001, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    game.getCamera().look();
}

void drawField()
{
    // Draw the ground
    glColor3f(0.5f, 0.8f, 0.5f);
    glBegin(GL_QUADS);
    glVertex3f(-FIELD_WIDTH / 2, 0.0f, -FIELD_LENGTH / 2);
    glVertex3f(-FIELD_WIDTH / 2, 0.0f, FIELD_LENGTH / 2);
    glVertex3f(FIELD_WIDTH / 2, 0.0f, FIELD_LENGTH / 2);
    glVertex3f(FIELD_WIDTH / 2, 0.0f, -FIELD_LENGTH / 2);
    glEnd();

    // Draw the target
    glColor3f(0.8f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(0.0f, TARGET_HEIGHT / 2, FIELD_LENGTH / 2 - 1.0f);
    glutSolidSphere(TARGET_RADIUS, 20, 20);
    glPopMatrix();
}

void drawArrow()
{
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(arrowX, arrowY, arrowZ);
    glRotatef(arrowAngle, 0.0f, 1.0f, 0.0f);
    glutSolidCone(0.1f, 1.0f, 10, 10);
    glPopMatrix();
}

void display()
{
    setupCamera();
    setupLights();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawField();
    drawArrow();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    float d = 0.1;
    Camera &camera = game.getCamera();

    switch (key)
    {
    case ' ':
        if (!arrowShot)
            arrowShot = true;
        break;
    case 'j':
        arrowAngle -= 1.0f;
        break;
    case 'k':
        arrowAngle += 1.0f;
        break;
    case 'w':
        camera.moveY(d);
        break;
    case 's':
        camera.moveY(-d);
        break;
    case 'a':
        camera.moveX(d);
        break;
    case 'd':
        camera.moveX(-d);
        break;
    case 'q':
        camera.moveZ(d);
        break;
    case 'e':
        camera.moveZ(-d);
        break;

    case GLUT_KEY_ESCAPE:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void update(int value)
{
    if (arrowShot)
    {
        // Update arrow position
        arrowX += arrowVelocity * sin(DEG2RAD(arrowAngle));
        arrowZ += arrowVelocity * cos(DEG2RAD(arrowAngle));

        // Check if arrow has hit the target
        if (arrowX * arrowX + arrowZ * arrowZ <= TARGET_RADIUS * TARGET_RADIUS &&
            arrowY >= TARGET_HEIGHT / 2 && arrowY <= TARGET_HEIGHT + 0.1f)
        {
            // Target hit, reset arrow
            arrowShot = false;
            arrowX = 0.0f;
            arrowY = 1.0f;
            arrowZ = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / game.getFPS(), update, 0);
}

void special(int key, int x, int y)
{
    float a = 3.0;
    Camera &camera = game.getCamera();

    switch (key)
    {
    case GLUT_KEY_UP:
        camera.rotateX(a);
        break;
    case GLUT_KEY_DOWN:
        camera.rotateX(-a);
        break;
    case GLUT_KEY_LEFT:
        camera.rotateY(a);
        break;
    case GLUT_KEY_RIGHT:
        camera.rotateY(-a);
        break;
    case GLUT_KEY_PAGE_UP:
        camera.rotateZ(a);
        break;
    case GLUT_KEY_PAGE_DOWN:
        camera.rotateZ(-a);
        break;
    }

    glutPostRedisplay();
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(game.getWidth(), game.getHeight());
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