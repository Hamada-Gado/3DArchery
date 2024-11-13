#pragma once

#include "object.h"
#include "vector3f.h"

class Player : public Object
{
public:
    Player(float x, float y, float z, float _angle);
    void render() const override;
    void move(float dx, float dy, float dz);
    void rotate(float angle);
    void shoot();
    void reset();
    void setArrowVelocity(float velocity);
    void setArrowAngle(float angle);
    void setArrowShot(bool shot);
    float getAngle();
    float getArrowVelocity();
    float getArrowAngle();
    bool getArrowShot();

private:
    float angle;
    float arrowVelocity;
    float arrowAngle;
    bool arrowShot;
};