#pragma once
#include "camera.h"
class OrthogonalCamera :
	public Camera
{
protected:
	double _left;
	double _right;
	double _bottom;
	double _top;
public:
	OrthogonalCamera(double left, double rigth, double bottom, double top, double near, double far);
	~OrthogonalCamera(void);
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

