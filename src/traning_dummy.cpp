#include <glut.h>

#include "include/traning_dummy.h"

TrainingDummy::TrainingDummy(float x, float y, float z, float angleX, float angleY, float angleZ,
                           float scale)
    : Object(x, y, z, angleX, angleY, angleZ), scale(scale) {}

void TrainingDummy::render() const {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle.x, 1.0f, 0.0f, 0.0f);
    glRotatef(angle.y, 0.0f, 1.0f, 0.0f);
    glRotatef(angle.z, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);

    // Base post
    glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.1f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Body (hay bale)
    glPushMatrix();
    glColor3f(0.9f, 0.8f, 0.2f);
    glTranslatef(0.0f, 0.2f, 0.0f);
    glScalef(0.4f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Head sphere
    glPushMatrix();
    glColor3f(0.9f, 0.8f, 0.2f);
    glTranslatef(0.0f, 0.6f, 0.0f);
    glutSolidSphere(0.15f, 10, 10);
    glPopMatrix();

    glPopMatrix();
}