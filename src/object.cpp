#include "include/object.h"

Object::Object(float x, float y, float z,
               float angleX, float angleY, float angleZ) : position(x, y, z),
                                                           angle(angleX, angleY, angleZ) {}
