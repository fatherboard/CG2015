/*
 * StaticObject.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_STATICOBJECT_H_
#define PROJ_STATICOBJECT_H_

#include "GameObject.h"

class StaticObject: public GameObject {
protected:
	double _near;
	double _far;

public:
	StaticObject();
	virtual ~StaticObject();
};

#endif /* PROJ_STATICOBJECT_H_ */
