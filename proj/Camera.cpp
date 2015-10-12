/*
 * Camera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "Camera.h"

Camera::Camera(double near, double far) {
	_near = near;
	_far = far;
}
Camera::~Camera(){}

double Camera::getNear(){ 
	return _near; 
}
double Camera::getFar(){ 
	return _far; 
}

void Camera::update(GLsizei w, GLsizei h)
{
}



