#pragma once
#include "dynamicobject.h"
class Car :
	public DynamicObject
{
public:
	Car(void);
	~Car(void);
	void draw();
};

