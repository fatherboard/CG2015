#pragma once
#include "gameobject.h"
class DynamicObject abstract :
	public GameObject
{
public:
	DynamicObject(void);
	~DynamicObject(void);
	void update(double const delta);
	void setSpeed(Vector3 const speed);
	void setSpeed(double x, double y, double z);
	Vector3 getSpeed();
};

