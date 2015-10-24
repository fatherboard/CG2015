#pragma once

#ifndef __CAMERA__
#define __CAMERA__

#include "Entity.h"
#include "Vector3.h"
#include "stdlib.h"
#include "GL/glut.h"

class Camera : public Entity{
public:
	double _near;
	double _far;
	Vector3 _up;
	Vector3 _at;

	
		Camera(double near, double far);
		~Camera();

		double getNear();
		double getFar();
		Vector3 getUp();
		Vector3 getAt();
		void setUp(double x, double y, double z);
		void setAt(double x, double y, double z);
		virtual void update(GLsizei w, GLsizei h) = 0;
		virtual void computeProjectionMatrix() = 0;
		virtual void computeVisualizationMatrix() = 0;
};

#endif
