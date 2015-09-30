/*
 * Car.h
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#ifndef PROJ_CAR_H_
#define PROJ_CAR_H_

#include "DynamicObject.h"

class Car: public DynamicObject {
public:
	Car();
	~Car();

	void draw();
};

#endif /* PROJ_CAR_H_ */
