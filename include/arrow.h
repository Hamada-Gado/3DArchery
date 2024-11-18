#pragma once

#include "object.h"
#include "vector3f.h"

class Arrow : public Object
{
public:
    Arrow(float x, float y, float z, float angleX, float angleY, float angleZ);

    void render() const override;
    void setLength(float length);
    void setWidth(float width);
    void setHeadLength(float length);
    void setHeadWidth(float width);
    void setColor(float r, float g, float b);
    void setHeadColor(float r, float g, float b);

    float length;
    float width;
    float headLength;
    float headWidth;
    float r, g, b;
    float headR, headG, headB;
};