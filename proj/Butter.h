#pragma once
#ifndef __BUTTER__
#define __BUTTER__

#include "Obstacle.h"
#include "GL/glut.h"

class Butter: public Obstacle {
public:
	Butter();
	~Butter();

	void draw();
	void draw(int wf);
};

#endif
