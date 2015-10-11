#pragma once
#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"
#include "GL/glut.h"

class Orange: public Obstacle {
public:
	
	Orange();
	~Orange();
	void draw();
	void draw(int wf);
};

#endif
