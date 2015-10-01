/*
 * GameObject.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_GAMEOBJECT_H_
#define PROJ_GAMEOBJECT_H_

#include "../GameMgr/Entity.h"

class GameObject: public Entity {
public:
	GameObject();
	~GameObject();

	void draw();
	void update(double delta_t);
};

#endif /* PROJ_GAMEOBJECT_H_ */
