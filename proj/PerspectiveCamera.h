#pragma once
#include "camera.h"
class PerspectiveCamera :
	public Camera
{
protected:
	double _fovy;
	double _aspect;
public:
	~PerspectiveCamera(void);
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);

};

