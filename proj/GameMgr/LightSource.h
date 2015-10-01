/*
 * LightSource.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_LIGHTSOURCE_H_
#define PROJ_LIGHTSOURCE_H_

#include "Vector3.h"
#include <GL/glu.h>
#include <GL/glut.h>

class LightSource {
private:
	Vector3 _direction;
	Vector3 _position;

	double _ambient[4];
	double _diffuse[4];
	double _specular[4];
	double _cut_off;
	double _exponent;
	GLenum _num;
	bool _state;

public:
	LightSource(GLenum number);
	~LightSource();

	bool getState();
	bool setState(bool state);
	GLenum getNum();
	void setPosition(Vector3 position);
	void setDirection(Vector3 direction);
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(double ambient[4]);
	void setDiffuse(double diffuse[4]);
	void setSpecular(double specular[4]);
	void draw();
};

#endif /* PROJ_LIGHTSOURCE_H_ */
