#pragma once

#ifndef __LIGHTSOURCE__
#define __LIGHTSOURCE__

#include "Header.h"

class LightSource {

	Vector3 _direction;
	Vector4 _position;

	Vector4 _ambient;
	Vector4 _diffuse;
	Vector4 _specular;
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
		void setPosition(Vector4 *position);
		void setPosition(double x, double y, double z, double w);
		void setDirection(Vector3 *direction);
		void setDirection(double x, double y, double z);
		void setCutOff(double cut_off);
		void setExponent(double exponent);
		void setAmbient(Vector4 *ambient);
		void setAmbient(double x, double y, double z, double w);
		void setDiffuse(Vector4 *diffuse);
		void setDiffuse(double x, double y, double z, double w);
		void setSpecular(Vector4 *specular);
		void setSpecular(double x, double y, double z, double w);
		void draw();
};

#endif
