#pragma once

#ifndef __CAMERA__
#define __CAMERA__

#include "Entity.h"
#include "Vector3.h"
#include "stdlib.h"
#include "GL/glut.h"

class Camera : public Entity{

	double _near;
	double _far;
	Vector3 _up;
	Vector3 _center;
	Vector3 _at;

	public:
		Camera(double near, double far);
		~Camera();

		double getNear();
		double getFar();
		virtual void update(GLsizei w, GLsizei h) = 0;
		virtual void computeProjectionMatrix() = 0;
		virtual void computeVisualizationMatrix() = 0;
};

#endif