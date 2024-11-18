#pragma once

#include "object.h"
#include "include/arrow.h"
#include "include/bow.h"

#include "vector3f.h"

class Player : public Object
{
public:
    Player(float x, float y, float z, float angleX, float angleY, float angleZ);
    void render() const override;
    void moveSideway(float d);
    void moveForward(float d);
    void rotateRightArmX(float a);
    void rotateY(float a);

    Bow bow;
    Vector3f rightArmPosition;
    Vector3f rightArmRotation;
};