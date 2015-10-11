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

void Orange::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidCube(1);
	glFlush();
	glPopMatrix();
}
