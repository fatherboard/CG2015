#pragma once

#ifndef __TRACK__
#define __TRACK__

#include "StaticObject.h"
class Track :
	public StaticObject
{
public:
	Track(void);
	~Track(void);
	void draw();
};

#endif