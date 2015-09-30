/*
 * PerspectiveCamera.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_PERSPECTIVECAMERA_H_
#define PROJ_PERSPECTIVECAMERA_H_

#include "Camera.h"

class PerspectiveCamera: public Camera {
private:
	double _fovy;
	double _aspect;

public:
	PerspectiveCamera(double fovy, double aspect);
	~PerspectiveCamera();

	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif /* PROJ_PERSPECTIVECAMERA_H_ */
