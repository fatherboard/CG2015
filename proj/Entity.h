#pragma once

#ifndef __ENTITY__
#define __ENTITY__

#include "Vector3.h"

class Entity {
	protected:
		Vector3 _position;
		Vector3 _direcao;
		double _radian;

	public:
		Entity();
		~Entity();
		Vector3* getPosition();
		Vector3* setPosition(double x, double y, double z);
		Vector3* setPosition(Vector3*);
};

#endif
