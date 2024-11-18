#include "object.h"

class TrainingDummy : public Object {
private:
    float scale;
    
public:
    TrainingDummy(float x, float y, float z, float angleX, float angleY, float angleZ,
                 float scale = 1.0f);
    void render() const override;
};