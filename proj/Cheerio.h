/*
 * Cheerio.h
 *
 *  Created on: Oct 21, 2015
 *      Author: ist169537
 */
#pragma once
#ifndef PROJ_CHEERIO_H_
#define PROJ_CHEERIO_H_

#include "StaticObject.h"
#include "StaticObject.h"
#include <GL/glut.h>

class Cheerio : public StaticObject{
public:
	Cheerio(Vector3* position, double iR, double oR);
	Cheerio(Vector3* position, double iR, double oR, int s, int r);
	virtual ~Cheerio();
	void draw();

private:
	double _inner_radius;
	double _outer_radius;
	int _sides;
	int _rings;
};

#endif /* PROJ_CHEERIO_H_ */
