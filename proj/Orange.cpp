/*
 * Orange.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "GameManager.h"
#include "Orange.h"

extern GameManager* gameManager;
extern int _wireframe;

unsigned long inicio;
unsigned long tempo_atual;

Orange::Orange(Vector3 position, float radius){
	setColor(Vector3(1, 0.5f, 0));
	_position = position;
	_radius = radius;
	_angle = 0;
	dX = (rand() % 2) == 0 ? -1 : 1;
	dY = (rand() % 2) == 0 ? -1 : 1;

	_tempoInicial= glutGet(GLUT_ELAPSED_TIME);
	setSpeed(0.5,0.5,0);

	setObjRadius(radius);

}

Orange::~Orange() {
	// TODO Auto-generated destructor stub
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

void Orange::draw() {

	glColor3f(color.getX(), color.getY(), color.getZ());

	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glRotated(_angle, 0, 0, 1);


        defineMaterial(	color.getX(), color.getY(), color.getZ(), 1.00,
                        color.getX(), color.getY(), color.getZ(), 1.00,
                        0.00, 0.00, 0.00, 0.00,
                        0,0,0,1,
                        128);


	if (_wireframe) {
		glutWireSphere(_radius, 50, 10);
	} else {
		glutSolidSphere(_radius, 50, 10);
	}


	glPushMatrix();
	glColor3d(0.035,0.67,0);
	glTranslatef(0,-1,3);
	glScalef(0.5,1,0.5);

    if(gameManager->getLightsOn() || gameManager->getModoDia() || gameManager->getCar()->getLightState()){
        defineMaterial(	0.035, 0.67, 0.0, 1.00,
                        0.90, 0.50, 0.00, 1.00,
                        0,0,0,1,
                        0,0,0,1,
                        128);
    }else{
        defineMaterial(	0, 0, 0, 1,
                        0, 0, 0, 1,
                        0, 0, 0, 1,
                        0, 0, 0, 1,
                        0);
    }

	if (_wireframe) {
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
	Vector3* pos = getPosition();
	_tempoAgora= glutGet(GLUT_ELAPSED_TIME);
	if (_tempoAgora - _tempoInicial > 5000) {
		_tempoInicial = _tempoAgora;
		setSpeed(getSpeed()->getX() + 0.5, getSpeed()->getY() + 0.5, 0);
	}
	setPosition(pos->getX() + getSpeed()->getX()*dX, pos->getY() + getSpeed()->getY()*dY, pos->getZ());
}
