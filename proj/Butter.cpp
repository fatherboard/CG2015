/*
 * Butter.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Butter.h"

Butter::Butter(Vector3 location, float width, float length) {
	setColor(Vector3(1.0f, 1.0f, 0.0f));
	this->location = location;
	this->width = width;
	this->length = length;
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
	glTranslated(location.getX(), location.getY(), location.getZ());
	glScalef(width, length, 1.0f);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();
}
