#pragma once

#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"

class GameObject: public Entity {
	public:
		GameObject();
		virtual ~GameObject();
		virtual void draw()=0;
		void update(unsigned long delta_t);

	private:
		int wireframe;

	protected:
		void drawWireframe();
		void drawSolid();
};

#endif
