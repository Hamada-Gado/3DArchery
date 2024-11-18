#pragma once

#include "vector3f.h"

// abstract class
class Object
{
public:
    Vector3f position;
    Vector3f angle;

    Object(float x = 0.0f, float y = 0.0f, float z = 0.0f,
           float angleX = 0.0f, float angleY = 0.0f, float angleZ = 0.0f);
    virtual ~Object() = default;

    virtual void render() const = 0;
};
