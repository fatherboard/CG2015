#pragma once

#ifndef __LIGHTSOURCE__
#define __LIGHTSOURCE__

#include "Vector3.h"

class LightSource {

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
		void setPosition(Vector3 *position);
		void setDirection(Vector3 *direction);
		void setCutOff(double cut_off);
		void setExponent(double exponent);
		void setAmbient(double ambient[4]);
		void setDiffuse(double diffuse[4]);
		void setSpecular(double specular[4]);
		void draw();
};

#endif