/*
 * Butter.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Butter.h"
#include "GameManager.h"
#include <math.h>

extern int _wireframe;
extern GameManager* gameManager;

Butter::Butter(Vector3 position, float width, float length) {
	setColor(Vector3(1, 1, 0));
	_position = position;
	this->width = width;
	this->length = length;

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

	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glScalef(width, length, 1);

    if(gameManager->getLightsOn() || gameManager->getCar()->getLightState()){
        defineMaterial(	color.getX(), color.getY(), color.getZ(), 1.00,
                        0.90, 0.00, 0.00, 1.00,
                        1.00, 1.00, 1.00, 1.00,
                        0,0,0,1,
                        128);
    }else if(gameManager->getModoDia()){
        defineMaterial( color.getX(), color.getY(), color.getZ(), 1.00,
                        0.40, 0.25, 0.00, 1.00,
                        0.10, 1.00, 0.00, 1.00,
                        0,0,0,1,
                        128);
    }else{
        defineMaterial(	0,0,0,1,
                        0,0,0,1,
                        0,0,0,1,
                        0,0,0,1,
                        0);
    }

    glNormal3f(0,0,1);

    glColor3f(color.getX(), color.getY(), color.getZ());

	if (_wireframe)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();
}
