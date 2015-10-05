#pragma once

#ifndef __ROADSIDE__
#define __ROADSIDE__

#include "StaticObject.h"
class Roadside :
	public StaticObject
{
public:
	Roadside(void);
	~Roadside(void);
	void draw();
};

#endif