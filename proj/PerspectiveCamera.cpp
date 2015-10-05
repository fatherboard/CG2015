/*
 * PerspectiveCamera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(double fovy,double aspect, double zNear, double zFar):Camera(zFar, zNear) {
	_fovy=fovy;
	_aspect=aspect;
}

PerspectiveCamera::~PerspectiveCamera() {
	// TODO Auto-generated destructor stub
}

void PerspectiveCamera::update(GLsizei w, GLsizei h){
	// TODO
}
void PerspectiveCamera::computeProjectionMatrix(){
	// TODO
}
void PerspectiveCamera::computeVisualizationMatrix(){
	// TODO
}

