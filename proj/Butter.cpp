/*
 * Butter.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Butter.h"
#include <math.h>

extern int _wireframe;

Butter::Butter(Vector3 position, float width, float length) {
	setColor(Vector3(1, 1, 0));
	_position = position;
	this->width = width;
	this->length = length;
	pushed = false;

	setObjRadius(sqrt(pow(width,2)+pow(length,2))/2);
}

Butter::~Butter() {
	// TODO Auto-generated destructor stub
}

void Butter::setColor(Vector3 color){
	this->color = color;
}

Vector3 Butter::getColor(){
	return this->color;
}

void Butter::draw(){

	glColor3f(color.getX(), color.getY(), color.getZ());

	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glScalef(width, length, 1);
	if (_wireframe)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();
}
