/*
 * OrthogonalCamera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top) {
	this->_left = left;
	this->_right = right;
	this->_bottom = bottom;
	this->_top = top;
}

OrthogonalCamera::~OrthogonalCamera() {
	// TODO Auto-generated destructor stub
}

void OrthogonalCamera::update(){
	// TODO
}
void OrthogonalCamera::computeProjectionMatrix(){
	// TODO
}
void OrthogonalCamera::computeVisualizationMatrix(){
	// TODO
}
