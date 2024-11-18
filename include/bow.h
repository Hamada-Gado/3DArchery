#pragma once

#include "object.h"
#include "vector3f.h"

class Bow : public Object
{
public:
    Bow(float x, float y, float z, float angleX, float angleY, float angleZ);

    void render() const override;
    void setLength(float length);
    void setWidth(float width);
    void setColor(float r, float g, float b);

    float length;
    float width;
    float r, g, b;
};