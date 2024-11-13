#pragma once

#include "vector3f.h"

// abstract class
class Object
{
public:
    Object(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    virtual ~Object() = default;
    virtual void render() const = 0;
    virtual void setPosition(float x, float y, float z);
    virtual void setPosition(Vector3f &v);
    virtual void getPosition(float &x, float &y, float &z) const;
    virtual void getPosition(Vector3f &v) const;

protected:
    Vector3f position;
};
