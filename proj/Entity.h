#pragma once
#include "Vector3.h"
class Entity abstract
{
public:
	Entity(void);
	~Entity(void);
	Vector3 getPosition();
	Vector3 setPosition(double x, double y, double z);
	Vector3 setPosition(Vector3 const p);
};

