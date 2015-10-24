#pragma once

#ifndef __PERSPECTIVECAMERA__
#define __PERSPECTIVECAMERA__

#include "Camera.h"

class PerspectiveCamera: public Camera {

	double _fovy, _aspect;
	Car* car = NULL;

	public:
		PerspectiveCamera();
		PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
		PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Car *a);
		~PerspectiveCamera();

		void update(GLsizei w, GLsizei h);
		void computeProjectionMatrix();
		void computeVisualizationMatrix();
};

#endif
