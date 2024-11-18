#include <cmath>
#include <glut.h>

#include "include/quiver.h"

// Quiver Implementation
Quiver::Quiver(float x, float y, float z, float angleX, float angleY, float angleZ,
               float height, float radius)
    : Object(x, y, z, angleX, angleY, angleZ), height(height), radius(radius) {}

void Quiver::render() const {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glScalef(scale, scale, scale);
    glRotatef(angle.x, 1.0f, 0.0f, 0.0f);
    glRotatef(angle.y, 0.0f, 1.0f, 0.0f);
    glRotatef(angle.z, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.1f);
    glScalef(radius, height, radius * 0.7f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, height/2 + 0.02f, 0.0f);
    glColor3f(0.8f, 0.6f, 0.2f);
    for(int i = 0; i < 8; i++) {
        glPushMatrix();
        glRotatef(45.0f * i, 0.0f, 1.0f, 0.0f);
        glTranslatef(radius, 0.0f, 0.0f);
        glScalef(0.05f, 0.04f, 0.05f);
        glutSolidCube(1.0f);
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.1f);
    glTranslatef(radius, 0.0f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.05f, height * 1.2f, 0.05f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
}