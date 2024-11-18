#include <glut.h>

#include "include/table.h"

Table::Table(float x, float y, float z, float angleX, float angleY, float angleZ,
                         float width, float height)
    : Object(x, y, z, angleX, angleY, angleZ), width(width), height(height) {}

void drawTableLeg(double thick, double len) {
	glPushMatrix();
	glTranslated(0, len / 2, 0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawTable(double topWid, double topThick, double legThick, double legLen){
	glPushMatrix();
	glTranslated(0, legLen, 0);
	glScaled(topWid, topThick, topWid);
	glutSolidCube(1.0);
	glPopMatrix();

	double dist = 0.95*topWid / 2.0 - legThick / 2.0;
	glPushMatrix();
	glTranslated(dist, 0, dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(-2 * dist, 0, 2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glPopMatrix();
}


void Table::render() const {
    glPushMatrix();
	glColor3f(color[0], color[1], color[2]);
    glTranslated(position.x, position.y, position.z);
    glRotatef(angle.x, 1.0, 0.0, 0.0);
    glRotatef(angle.y, 0.0, 1.0, 0.0);
    glRotatef(angle.z, 0.0, 0.0, 1.0);
    drawTable(width, 0.1, 0.02, 0.3);
    glPopMatrix();
}