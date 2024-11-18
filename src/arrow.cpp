#include <glut.h>

#include "include/arrow.h"
#include "include/vector3f.h"

Arrow::Arrow(float x, float y, float z,
             float angleX, float angleY, float angleZ) : Object(x, y, z, angleX, angleY, angleZ),
                                                         length(1.0f), width(0.1f),
                                                         headLength(0.3f), headWidth(0.3f), r(1.0f), g(0.0f), b(0.0f),
                                                         headR(0.0f), headG(1.0f), headB(0.0f) {}

void drawArrowHead()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -1.2f);
    glutSolidCone(0.3f, 0.3f, 10, 10);
    glPopMatrix();
}

void drawArrowBody()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.7f);
    glScalef(0.07f, 0.07f, 0.7f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawArrowFeathers(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.2f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glEnd();
    glPopMatrix();
}

void Arrow::render() const
{
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle.x, 1.0f, 0.0f, 0.0f);
    glRotatef(angle.y, 0.0f, 1.0f, 0.0f);
    glRotatef(angle.z, 0.0f, 0.0f, 1.0f);
    glScalef(width, width, length);

    // Draw the arrow body
    glColor3f(r, g, b);
    drawArrowBody();

    // Draw the arrow head
    glColor3f(headR, headG, headB);
    glPushMatrix();
    glScalef(headWidth, headWidth, headLength);
    drawArrowHead();
    glPopMatrix();

    // Draw 3 arrow feathers
    drawArrowFeathers(0.0f, 0.0f, -1.0f);

    glPushMatrix();
    glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
    drawArrowFeathers(0.0f, 0.0f, -1.0f);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-120.0f, 0.0f, 0.0f, 1.0f);
    drawArrowFeathers(0.0f, 0.0f, -1.0f);
    glPopMatrix();

    glPopMatrix();
};

void Arrow::setLength(float length)
{
    this->length = length;
}

void Arrow::setWidth(float width)
{
    this->width = width;
}

void Arrow::setHeadLength(float length)
{
    headLength = length;
}

void Arrow::setHeadWidth(float width)
{
    headWidth = width;
}

void Arrow::setColor(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void Arrow::setHeadColor(float r, float g, float b)
{
    headR = r;
    headG = g;
    headB = b;
}