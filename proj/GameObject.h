#pragma once

#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
#include <GL/glut.h>

class GameObject: public Entity {
	public:

		GameObject();
		GameObject(double obj_radius);
		virtual ~GameObject();
		virtual void draw()=0;
		void update(unsigned long delta_t);
		double obj_radius;
		void setObjRadius(double radius);
		double getObjRadius();
		void setSize(double x, double y, double z);
		Vector3* getSize();
		void defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
                            GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
                            GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
                            GLfloat se);

	private:
        Vector3* _size;

		void drawWireframe();
		void drawSolid();
};

#endif
