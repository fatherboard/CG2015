#pragma once

#ifndef __TRACK__
#define __TRACK__

#include "StaticObject.h"
#include "GL/glut.h"

class Track :
	public StaticObject
{
public:
	Track(void);
	~Track(void);
	void draw();
	void draw(int wf);
};

#endif
