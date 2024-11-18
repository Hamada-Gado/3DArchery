#include <cmath>
#include <glut.h>

#include "include/bow.h"

Bow::Bow(float x, float y, float z,
         float angleX, float angleY, float angleZ) : Object(x, y, z, angleX, angleY, angleZ),
                                                     length(1.0f), width(0.1f),
                                                     r(1.0f), g(1.0f), b(0.0f) {}

void drawBowString()
{
    glPushMatrix();
    glScalef(7.0, 0.5, 0.5);
    glutSolidCube(0.1);
    glPopMatrix();
}

void drawBowBody()
{
    float radius = 0.3f;
    float angle = 0.0f;
    float angle_stepsize = 0.1f;

    for (angle = -3.14159f / 2; angle < 0.5 * 3.14159f; angle += angle_stepsize)
    {
        float x = radius * sin(angle);
        float y = radius * cos(angle);
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glutSolidCube(0.05);
        glPopMatrix();
    }
}

void Bow::render() const
{
    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle.x, 1.0f, 0.0f, 0.0f);
    glRotatef(angle.y, 0.0f, 1.0f, 0.0f);
    glRotatef(angle.z, 0.0f, 0.0f, 1.0f);
    drawBowBody();
    drawBowString();
    glPopMatrix();
}

void Bow::setLength(float length)
{
    this->length = length;
}

void Bow::setWidth(float width)
{
    this->width = width;
}

void Bow::setColor(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
