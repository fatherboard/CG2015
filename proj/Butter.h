#pragma once
#ifndef __BUTTER__
#define __BUTTER__

#include "Obstacle.h"

class Butter: public Obstacle {
public:
	Butter();
	~Butter();

	void draw();
};

#endif