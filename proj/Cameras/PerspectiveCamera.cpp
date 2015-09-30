/*
 * PerspectiveCamera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect) {
	this->_fovy = fovy;
	this->_aspect = aspect;
}

PerspectiveCamera::~PerspectiveCamera() {
	// TODO Auto-generated destructor stub
}

void PerspectiveCamera::update(){
	// TODO
}
void PerspectiveCamera::computeProjectionMatrix(){
	// TODO
}
void PerspectiveCamera::computeVisualizationMatrix(){
	// TODO
}

