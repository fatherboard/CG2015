/*
 * Camera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "Camera.h"

Camera::Camera(){
	_far=0;
	_near=0;
}

Camera::Camera(double near, double far) {
	_near = near;
	_far = far;
}
Camera::~Camera(){}


