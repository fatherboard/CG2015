#pragma once

#ifndef __TRACK__
#define __TRACK__

#include "StaticObject.h"
#include "GL/glut.h"

class Track : public StaticObject
{
	int wf;
public:
	Track();
	~Track();
	void draw();


private:
	void drawCheerio();
};

#endif
