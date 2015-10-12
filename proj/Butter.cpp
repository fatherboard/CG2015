/*
 * Butter.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Butter.h"

Butter::Butter() {
	// TODO Auto-generated constructor stub

}

Butter::~Butter() {
	// TODO Auto-generated destructor stub
}

void Butter::draw(int wf){

	glColor3f(1.0f, 1.0f, 0.0f);

	//#1
	glPushMatrix();
	glTranslated(10.0, 36.0, 0.0);
	glScalef(1.0f, 1.5f, 1.0f);
	if (wf)
		glutWireCube(2);
	else
		glutSolidCube(2);
	glPopMatrix();
	//#2
	glPushMatrix();
	glTranslated(-9.0, 16.0, 0.0);
	glScalef(1.0f, 1.5f, 1.0f);
	if (wf)
		glutWireCube(2);
	else
		glutSolidCube(2);
	glPopMatrix();
	//#3
	glPushMatrix();
	glTranslated(-15.0, -8.0, 0.0);
	glScalef(1.0f, 1.5f, 1.0f);
	if (wf)
		glutWireCube(2);
	else
		glutSolidCube(2);
	glPopMatrix();
	//#4
	glPushMatrix();
	glTranslated(20.0, -17.0, 0.0);
	glScalef(1.0f, 1.5f, 1.0f);
	if (wf)
		glutWireCube(2);
	else
		glutSolidCube(2);
	glPopMatrix();
	//#5
	glPushMatrix();
	glTranslated(-28.0, -32.0, 0.0);
	glScalef(1.0f, 1.5f, 1.0f);
	if (wf)
		glutWireCube(2);
	else
		glutSolidCube(2);
	glPopMatrix();
}
