/*
 * Butter.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Butter.h"
#include <math.h>

Butter::Butter(Vector3 position, float width, float length) {
	setColor(Vector3(1.0f, 1.0f, 0.0f));
	_position = position;
	this->width = width;
	this->length = length;

	setObjRadius(sqrt(pow(width,2)+pow(length,2))/2);
}

Butter::~Butter() {
	// TODO Auto-generated destructor stub
}

void Butter::draw(){
	draw(0);
}

void Butter::setColor(Vector3 color){
	this->color = color;
}

Vector3 Butter::getColor(){
	return this->color;
}

void Butter::draw(int wf){

	glColor3f(color.getX(), color.getY(), color.getZ());

	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glScalef(width, length, 1.0f);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();
}
