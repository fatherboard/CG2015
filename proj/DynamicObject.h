#pragma once
#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__

#include "GameObject.h"
#include "Vector3.h"
#include <math.h>

class DynamicObject: public GameObject {

	Vector3 _speed;

public:
	DynamicObject();
	~DynamicObject();

	void update(unsigned long delta_t);
	void setSpeed(Vector3* speed);
	void setSpeed(double x, double y, double z);
	Vector3* getSpeed();
	void setDirecao(Vector3* speed);
	void setDirecao(double x, double y, double z);
	Vector3* getDirecao();
	void setRadian(double radian);
	double getRadian();
};

#endif
