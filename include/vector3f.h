#pragma once

class Vector3f {
public:
    float x, y, z;

    Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
    Vector3f operator+(const Vector3f &v);
    Vector3f operator-(const Vector3f &v);
    Vector3f operator*(float n);
    Vector3f operator/(float n);
    Vector3f unit();
    float dot(const Vector3f &v);
    Vector3f cross(const Vector3f &v);
};