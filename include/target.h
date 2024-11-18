#include "object.h"

class ArcheryTarget : public Object
{
private:
    float radius;
    float thickness;
    float height;

public:
    ArcheryTarget(float x, float y, float z,
                  float angleX, float angleY, float angleZ,
                  float radius = 1.0f, float thickness = 0.2f, float height = 1.5f);

    void render() const override;
    void setRadius(float radius);
    void setHeight(float height);
    void setThickness(float thickness);

    float color[3] = {3.0f, 3.0f, 3.0f};
};