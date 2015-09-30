/*
 * Camera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "Camera.h"

Camera::Camera(double near, double far, Vector3 up, Vector3 center, Vector3 at) {
	this->_near = near;
	this->_far = far;
	this->_up = up;
	this->_center = center;
	this->_at = at;
}


