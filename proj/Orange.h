#pragma once
#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"
#include "GL/glut.h"

class Orange: public Obstacle {
public:

	Orange(Vector3 position, float radius);
	~Orange();
	void draw();
	void draw(int wf);

	void setColor(Vector3 color);
	Vector3 getColor();

private:
	//Vector3 position;
	double radius;

	Vector3 color;
};

#endif
