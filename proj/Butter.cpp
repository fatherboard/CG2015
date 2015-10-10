/*
 * Butter.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Butter.h"
#include <GL/glut.h>

Butter::Butter() {
	// TODO Auto-generated constructor stub

}

Butter::~Butter() {
	// TODO Auto-generated destructor stub
}

void Butter::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3f(1.0f, 1.0f, 0.0f);
	glScalef(1.0f, 1.5f, 1.0f);
	glutSolidCube(1);
	glFlush();
	glPopMatrix();
}
