#pragma once
#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"
#include <GL/glut.h>

class Orange: public Obstacle {
public:

	Orange(Vector3 position, float radius);
	~Orange();
	void draw();
	void update(unsigned long delta_t);

	void setColor(Vector3 color);
	Vector3 getColor();

	void setAngle(double angle);
	double getAngle();

private:
	double _radius;
	double _angle;
	int dX, dY;
	int _tempoInicial;
	int _tempoAgora;

	Vector3 color;
};

#endif
