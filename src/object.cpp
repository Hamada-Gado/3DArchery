#include "include/object.h"

Object::Object(float x, float y, float z) : position(x, y, z) {}

void Object::setPosition(float x, float y, float z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void Object::setPosition(Vector3f &v)
{
    position.x = v.x;
    position.y = v.y;
    position.z = v.z;
}

void Object::getPosition(float &x, float &y, float &z) const
{
    x = position.x;
    y = position.y;
    z = position.z;
}

void Object::getPosition(Vector3f &v) const
{
    v.x = position.x;
    v.y = position.y;
    v.z = position.z;
}