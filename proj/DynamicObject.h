/*
 * DynamicObject.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_DYNAMICOBJECT_H_
#define PROJ_DYNAMICOBJECT_H_

#include "GameObject.h"

class DynamicObject: public GameObject {
private:
	Vector3 _speed;
public:
	DynamicObject();
	virtual ~DynamicObject();

	void update(double delta_t);
	void setSpeed(Vector3 speed);
	void setSpeed(double x, double y, double z);
	// nao esquecer que a nova posicao de um objecto em movimento
	// e dada por: posicao_1 = posicao_0 + velocidade * delta_t
	Vector3 getSpeed();
};

#endif /* PROJ_DYNAMICOBJECT_H_ */
