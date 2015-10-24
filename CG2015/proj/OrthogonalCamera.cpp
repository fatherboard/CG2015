/*
 * OrthogonalCamera.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */
#include "OrthogonalCamera.h"
OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far):Camera(near,far) {
	_left=left;
	_right=right;		
	_bottom=bottom;
	_top=top;
}

OrthogonalCamera::~OrthogonalCamera() {}

void OrthogonalCamera::update(GLsizei w, GLsizei h){
	float ratio = (_right - _left) / (_top - _bottom);
	float aspect = (float)w / h;
	if (ratio < aspect) {
		float aux = ((_top - _bottom) * aspect - (_right - _left)) / 2;
		glOrtho(_left - aux, _right + aux, _bottom, _top, getNear(), getFar());
	}
	else
	{
		float aux = ((_right - _left) / aspect - (_top - _bottom)) / 2;
		glOrtho(_left, _right, _bottom - aux, _top + aux, getNear(), getFar());
	}
}
void OrthogonalCamera::computeProjectionMatrix(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
void OrthogonalCamera::computeVisualizationMatrix(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}