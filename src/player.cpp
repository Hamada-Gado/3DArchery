#include <iostream>
#include <cmath>
#include <glut.h>

#include "include/player.h"

using namespace std;

Player::Player(float x, float y, float z, float angleX, float angleY, float angleZ)
    : Object(x, y, y, angleX, angleY, angleZ),
      bow(-0.2, 0.5, 0.3, angleX, angleY, angleZ),
      rightArmPosition(-0.2f, 0.0f, 0.3f),
      rightArmRotation(360.0f, 90.0f, -45.0f)
{
    this->bow.position = rightArmPosition;
    this->bow.angle = rightArmRotation;
    this->bow.angle.z += 165;
}

void drawHead()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();
}

void drawBody()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.3f, 0.7f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawArm(float x, float y, float z, float rotationX, float rotationY, float rotationZ)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationZ, 0.0f, 0.0f, 1.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void drawLeg(float x, float y, float z, float rotationX, float rotationY, float rotationZ)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationZ, 0.0f, 0.0f, 1.0f);
    glScalef(0.1f, 0.7f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void Player::render() const
{
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle.y, 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    drawLeg(-0.1f, -0.5f, 0.0f, 0.0f, 0, 0);
    drawLeg(0.1f, -0.5f, 0.0f, 0.0f, 0, 0);

    glColor3f(1.0f, 0.8f, 0.6f);
    drawArm(rightArmPosition.x, rightArmPosition.y, rightArmPosition.z, rightArmRotation.x, rightArmRotation.y, rightArmRotation.z);
    drawArm(0.3f, 0.0f, 0.0f, 0, 0, 45.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawBody();

    glColor3f(1.0f, 0.8f, 0.6f);
    drawHead();

    this->bow.render();

    glPopMatrix();
}

void Player::moveSideway(float d)
{
    position.x += d * cos(angle.y * 3.14159 / 180);
    position.z -= d * sin(angle.y * 3.14159 / 180);

    if (position.z > 44)
        position.z = 44;
    else if (position.z < -49)
        position.z = -49;

    if (position.x > 44)
        position.x = 44;
    else if (position.x < -49)
        position.x = -49;
}

void Player::moveForward(float d)
{
    position.z += d * cos(angle.y * 3.14159 / 180);
    position.x += d * sin(angle.y * 3.14159 / 180);

    if (position.z > 44)
        position.z = 44;
    else if (position.z < -49)
        position.z = -49;

    if (position.x > 44)
        position.x = 44;
    else if (position.x < -49)
        position.x = -49;
}

void Player::rotateRightArmX(float a)
{
    rightArmRotation.x += a;
    if (rightArmRotation.x < 270)
        rightArmRotation.x = 270;
    else if (rightArmRotation.x > 360)
        rightArmRotation.x = 360;

    rightArmPosition.y = 0.6f * sin(rightArmRotation.x * 3.14159 / 360);

    bow.angle.x = rightArmRotation.x;
    bow.angle.y = rightArmRotation.y;
    bow.angle.z = rightArmRotation.z + 165;

    bow.position.x = rightArmPosition.x;
    bow.position.y = rightArmPosition.y + 0.1f * cos(rightArmRotation.x * 3.14159 / 360);
    bow.position.z = rightArmPosition.z - 0.2f * sin(rightArmRotation.x * 3.14159 / 360);
}

void Player::rotateY(float a)
{
    angle.y += a;
}