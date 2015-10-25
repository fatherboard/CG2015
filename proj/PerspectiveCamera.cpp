/*
 * PerspectiveCamera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "Header.h"
#include "PerspectiveCamera.h"
#include <iostream>

PerspectiveCamera::PerspectiveCamera() : Camera(0, 200) {}
PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar):Camera(zFar, zNear) {
	_fovy = fovy;
	_aspect = aspect;
	car = NULL;
}

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Car *a) : PerspectiveCamera(fovy, aspect, zNear, zFar){
	car = a;
}

PerspectiveCamera::~PerspectiveCamera() {}

void PerspectiveCamera::update(GLsizei w, GLsizei h) {
	float xmin = -100;
	float xmax = 100;
	float ymin = 0;
	float ymax = 200;
	float aspect = (float)w / h;

	float ratio = (xmax - xmin) / (ymax - ymin);
	if (ratio < 0 || aspect < 0) std::cout << "NEGATIVE SCALE";

	if (ratio < aspect) glScalef(ratio / aspect, 1, 1);
	else glScalef(1, aspect / ratio, 1);
}

void PerspectiveCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _aspect, getNear(), getFar());
}
void PerspectiveCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(car != NULL){
        gluLookAt(getAt().getX()-cos(car->getRadian())*10, getAt().getY()-sin(car->getRadian())*10, getAt().getZ()+60,	// posicao
                getAt().getX(), getAt().getY(), getAt().getZ()+50,		// look at
                getUp().getX(), getUp().getY(),	getUp().getZ());	// Up Vector
    }else{
        gluLookAt(getAt().getX(), getAt().getY(), getAt().getZ(),	// posicao
					0, 0, 0,										// look at
                    getUp().getX(), getUp().getY(),	getUp().getZ());// Up Vector
    }
	//glPopMatrix();
}

