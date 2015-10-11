/*
 * Orange.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Orange.h"
#include <GL/glut.h>

Orange::Orange() {
	// TODO Auto-generated constructor stub

}

Orange::~Orange() {
	// TODO Auto-generated destructor stub
}

void Orange::draw() {
	draw(0);
}

void Orange::draw(int wf) {
	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.0f);
	glTranslated(-39.0, 34.0, 0.0);
	glScalef(4.0f, 4.0f, 4.0f);
	if (wf)
		glutWireSphere(1, 50, 5);
	else
		glutSolidSphere(1, 50, 5);
	glPopMatrix();
}
