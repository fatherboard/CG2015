/*
 * Orange.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Orange.h"
#include <GL/glut.h>

unsigned long inicio;
unsigned long tempo_atual;

Orange::Orange(Vector3 position, float radius){
	setColor(Vector3(1.0f, 0.5f, 0.0f));
	_position = position;
	_radius = radius;
	_angle = 0;

	setObjRadius(radius);
}

Orange::~Orange() {
	// TODO Auto-generated destructor stub
}

void Orange::draw() {
	draw(0);
}

void Orange::setColor(Vector3 color){
	this->color = color;
}

Vector3 Orange::getColor(){
	return color;
}

double Orange::getAngle(){
    return _angle;
}

void Orange::setAngle(double angle){
    _angle = angle;
}

void Orange::draw(int wf) {

	glColor3f(color.getX(), color.getY(), color.getZ());

	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glRotated(_angle, 0, 0, 1);

	if (wf) {
		glutWireSphere(_radius, 50, 5);
	} else {
		glutSolidSphere(_radius, 50, 5);
	}

	//glPopMatrix();

	glPushMatrix();
	glColor3d(0.035,0.67,0);
	glTranslatef(0,-1,3);
	glScalef(0.5,1,0.5);
	if (wf) {
		glutWireCube(2);
	} else {
		glutSolidCube(2);
	}
	glPopMatrix();
	glPopMatrix();
}

void Orange::update(unsigned long delta_t) {
    _angle += 45;
    if(_angle >= 360)
        _angle = 0;

    //Vector3* pos = getPosition();
    //setPosition(pos->getX()+(rand() % 2) == 0 ? -1 : 1, pos->getY()+(rand() % 2) == 0 ? -1 : 1, pos->getZ());
}
