#pragma once
#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"

class Car: public DynamicObject {
public:
	
	Car();
	Car(float hoodHeight);
	~Car();
	void draw();

private:
	float _hoodHeight;
	float getFrontVertexY(float x, float hypotenuse);
};

#endif
