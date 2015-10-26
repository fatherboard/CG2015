#pragma once

#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"

class GameObject: public Entity {
	public:
        bool pushed;

		GameObject();
		GameObject(double obj_radius);
		virtual ~GameObject();
		virtual void draw()=0;
		void update(unsigned long delta_t);
		double obj_radius;
		void setObjRadius(double radius);
		double getObjRadius();

	private:

		void drawWireframe();
		void drawSolid();
};

#endif
