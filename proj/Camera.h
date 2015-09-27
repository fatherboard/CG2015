#pragma once
#include "entity.h"

class Camera abstract :
	public Entity
{
protected:
	double _near;
	double _far;

public:
	Camera(double near, double far);
	~Camera(void);
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

