#include <cmath>
#include <glut.h>

#include "include/util.h"

void util::setupLights()
{
    GLfloat ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat shininess[] = {50};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    GLfloat lightIntensity[] = {1.0f, 1.0f, 1, 1.0f};
    GLfloat lightPosition[] = {-5.0f, 2.0f, -3.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void util::setupCamera(int width, int height, Camera &camera)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, width / height, 0.001, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera.look();
}

void util::moveForward(Vector3f &position, Vector3f &angle, float distance)
{
    position.z += distance * cos(angle.y * 3.14159 / 180);
    position.x += distance * sin(angle.y * 3.14159 / 180);
    position.y -= distance * sin(angle.x * 3.14159 / 180);
}

void util::drawWall(double thickness, const float colors[2][3])
{
    const int checkerSize = 2; 

    glPushMatrix();
    glTranslated(0.5, 0.5 * thickness, 0.5);
    glScaled(1.0, thickness, 1.0);

    glBegin(GL_QUADS);

    for (int i = 0; i < checkerSize; i++)
    {
        for (int j = 0; j < checkerSize; j++)
        {
            float x1 = -0.5f + i * (1.0f / checkerSize);
            float x2 = -0.5f + (i + 1) * (1.0f / checkerSize);
            float z1 = -0.5f + j * (1.0f / checkerSize);
            float z2 = -0.5f + (j + 1) * (1.0f / checkerSize);

            const float *color = colors[(i + j) % 2];
            glColor3fv(color);

            glNormal3f(0.0f, 1.0f, 0.0f);
            glVertex3f(x1, 0.5f, z1);
            glVertex3f(x2, 0.5f, z1);
            glVertex3f(x2, 0.5f, z2);
            glVertex3f(x1, 0.5f, z2);

            glVertex3f(x1, -0.5f, z1);
            glVertex3f(x2, -0.5f, z1);
            glVertex3f(x2, -0.5f, z2);
            glVertex3f(x1, -0.5f, z2);
        }
    }

    for (int i = 0; i < checkerSize; i++)
    {
        for (int j = 0; j < checkerSize; j++)
        {
            float y1 = -0.5f + i * (1.0f / checkerSize);
            float y2 = -0.5f + (i + 1) * (1.0f / checkerSize);
            float z1 = -0.5f + j * (1.0f / checkerSize);
            float z2 = -0.5f + (j + 1) * (1.0f / checkerSize);

            const float *color = colors[(i + j) % 2];
            glColor3fv(color);

            glNormal3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.5f, y1, z1);
            glVertex3f(0.5f, y2, z1);
            glVertex3f(0.5f, y2, z2);
            glVertex3f(0.5f, y1, z2);

            glNormal3f(-1.0f, 0.0f, 0.0f);
            glVertex3f(-0.5f, y1, z1);
            glVertex3f(-0.5f, y2, z1);
            glVertex3f(-0.5f, y2, z2);
            glVertex3f(-0.5f, y1, z2);
        }
    }

    glEnd();
    glPopMatrix();
}

void util::drawText(float x, float y, float z, const char *text)
{
    glRasterPos3f(x, y, z);
    for (const char *c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void util::drawText(float x, float y, const char *text)
{
    glRasterPos2f(x, y);
    for (const char *c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void util::drawText(float x, float y, float z, std::string text) {
    util::drawText(x, y, z, text.c_str());
}

void util::drawText(float x, float y, std::string text) {
    util::drawText(x, y, text.c_str());
}