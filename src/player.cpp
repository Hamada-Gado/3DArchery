#include <glut.h>

#include "include/player.h"

Player::Player(float x, float y, float z, float _angle): Object(x, y, y), angle(_angle) {}

void Player::render() const
{
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
}