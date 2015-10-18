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

Vector3 Camera::getUp(){
	return _up;
}

Vector3 Camera::getCenter(){
	return _center;
}

Vector3 Camera::getAt(){
	return _at;
}

void Camera::update(GLsizei w, GLsizei h){
}



