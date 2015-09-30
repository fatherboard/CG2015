/*
 * Orange.h
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#ifndef PROJ_ORANGE_H_
#define PROJ_ORANGE_H_

#include "Obstacle.h"

class Orange: public Obstacle {
public:
	Orange();
	~Orange();

	void draw();
};

#endif /* PROJ_ORANGE_H_ */
