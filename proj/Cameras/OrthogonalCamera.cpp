/*
 * OrthogonalCamera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "OrthogonalCamera.h"

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far) {
	_left = left;
	_right = right;
	_bottom = bottom;
	_top = top;
	_near = near;
	_far = far;
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
