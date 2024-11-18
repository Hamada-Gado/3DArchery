#pragma once

#include "object.h"

class Quiver : public Object {
private:
    float height;
    float radius;
    
public:
    Quiver(float x, float y, float z, float angleX, float angleY, float angleZ,
           float height = 0.8f, float radius = 0.2f);
    void render() const override;

    float scale = 1.0f;
};