#include "object.h"

class Table : public Object {
private:
    float width;
    float height;
    
public:
    Table(float x, float y, float z, float angleX, float angleY, float angleZ,
                 float width = 2.0f, float height = 1.0f);
    void render() const override;
    float color[3] = {0.9f, 0.1f, 0.9f};
};
