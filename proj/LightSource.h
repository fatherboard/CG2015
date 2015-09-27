#pragma once
#include <GL/glut.h>
#include "Vector3.h"
class LightSource
{
public:
	LightSource(GLenum number);
	~LightSource(void);
	bool getState();
	bool getState(bool state);
	GLenum getNum();
	void setPosition(Vector3 const position); // devia ser Vector4
	void setDirection(Vector3 const direction);
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(Vector3 const ambient); //Vector4
	void setDiffuse(Vector3 const diffuse); //Vector4
	void setSpecular(Vector3 const specular); //Vector4
	void draw();
};

