/*
 * Butter.h
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#ifndef PROJ_BUTTER_H_
#define PROJ_BUTTER_H_

#include "Obstacle.h"

class Butter: public Obstacle {
public:
	Butter();
	~Butter();

	void draw();
};

#endif /* PROJ_BUTTER_H_ */
