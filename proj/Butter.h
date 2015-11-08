#pragma once
#ifndef __BUTTER__
#define __BUTTER__

#include "Obstacle.h"
#include <GL/glut.h>

class Butter: public Obstacle {
public:
	Butter(Vector3 position, float width, float length);
	~Butter();
	void draw();

	Vector3 getColor();
	void setColor(Vector3 color);

private:
	Vector3 color;
	float width;
	float length;
};

#endif
