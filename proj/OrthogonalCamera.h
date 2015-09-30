/*
 * OrthogonalCamera.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_ORTHOGONALCAMERA_H_
#define PROJ_ORTHOGONALCAMERA_H_

#include "Camera.h"

class OrthogonalCamera: public Camera {
private:
	double _left;
	double _right;
	double _bottom;
	double _top;

public:
	OrthogonalCamera(double left, double right, double bottom, double top);
	~OrthogonalCamera();

	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif /* PROJ_ORTHOGONALCAMERA_H_ */
