/*
 * Orange.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Orange.h"

Orange::Orange() {
	// TODO Auto-generated constructor stub

}

Orange::~Orange() {
	// TODO Auto-generated destructor stub
}

void Orange::draw(){
	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.0f);
	glTranslated(-39.0, 34.0, 0.0);
	glScalef(4.0f, 4.0f, 4.0f);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
}
