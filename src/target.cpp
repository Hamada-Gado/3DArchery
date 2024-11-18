#include <cmath>
#include <glut.h>

#include "include/target.h"

ArcheryTarget::ArcheryTarget(float x, float y, float z,
                           float angleX, float angleY, float angleZ,
                           float radius, float thickness, float height)
    : Object(x, y, z, angleX, angleY, angleZ),
      radius(radius), thickness(thickness), height(height) {}

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f);  // Center point
    for(int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.14159f * float(i) / float(segments);
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void ArcheryTarget::render() const {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(angle.x, 1.0f, 0.0f, 0.0f);
    glRotatef(angle.y, 0.0f, 1.0f, 0.0f);
    glRotatef(angle.z, 0.0f, 0.0f, 1.0f);
    
    glPushMatrix();
    glColor3f(0.9f, 0.6f, 0.0f);
    glTranslatef(0.0f, -height/2, 0.0f);
    glScalef(radius * 0.1f, height, radius * 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.45f, 0.3f, 0.0f);
    glTranslatef(0.0f, 0.0f, -thickness/2);
    glScalef(radius * 2.2f, radius * 2.2f, thickness);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, thickness/2 + 0.001f);
    
    glColor3f(0.0f, 0.0f, color[2]);
    drawCircle(radius, 32);
    
    glTranslatef(0.0f, 0.0f, 0.03f);
    glColor3f(color[0], 0.0f, 0.0f);
    drawCircle(radius * 0.7f, 32);
    
    glTranslatef(0.0f, 0.0f, 0.04f);
    glColor3f(color[0], color[1], 0.0f);
    drawCircle(radius * 0.3f, 32);
    glPopMatrix();
    
    glPopMatrix();
}

void ArcheryTarget::setRadius(float radius) {
    this->radius = radius;
}

void ArcheryTarget::setHeight(float height) {
    this->height = height;
}

void ArcheryTarget::setThickness(float thickness) {
    this->thickness = thickness;
}