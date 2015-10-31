/*
 * LightSource.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */
#include "Header.h"

LightSource::LightSource(GLenum number) {
	_num = number;
}

LightSource::~LightSource() {
	// TODO Auto-generated destructor stub
}

bool LightSource::getState(){
	return _state;
}

bool LightSource::setState(bool state){
	_state = state;
	return _state;
}

GLenum LightSource::getNum(){
	return _num;
}

void LightSource::setPosition(Vector4* position){
	_position.set(position->getX(),position->getY(),position->getZ(), 0);
}

void LightSource::setPosition(double x, double y, double z, double w){
    _position.set(x, y, z, w);
}

void LightSource::setDirection(Vector3 *direction){
	_direction.set(direction->getX(),direction->getY(),direction->getZ());
}

void LightSource::setDirection(double x, double y, double z){
    _direction = new Vector3(x, y, z);
}

void LightSource::setCutOff(double cut_off){
	_cut_off = cut_off;
}

void LightSource::setExponent(double exponent){
	_exponent = exponent;
}

void LightSource::setAmbient(Vector4* ambient){
	_ambient.set(ambient->getX(), ambient->getY(), ambient->getZ(), ambient->getZ());
}

void LightSource::setAmbient(double x, double y, double z, double w){
    _ambient.set(x, y, z, w);
}

void LightSource::setDiffuse(Vector4* diffuse){
	_diffuse.set(diffuse->getX(), diffuse->getY(), diffuse->getZ(), diffuse->getZ());
}

void LightSource::setDiffuse(double x, double y, double z, double w){
    _diffuse.set(x, y, z, w);
}

void LightSource::setSpecular(Vector4* specular){
	_specular.set(specular->getX(), specular->getY(), specular->getZ(), specular->getZ());
}

void LightSource::setSpecular(double x, double y, double z, double w){
    _specular.set(x, y, z, w);
}

void LightSource::draw(){
    GLfloat light_position[] = { (GLfloat)_position.getX(), (GLfloat)_position.getY(), (GLfloat)_position.getZ(), (GLfloat)_position.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_POSITION, light_position);

	GLfloat ambient[] = { (GLfloat)_ambient.getX(), (GLfloat)_ambient.getY(), (GLfloat)_ambient.getZ(), (GLfloat)_ambient.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_AMBIENT, ambient);

	GLfloat diffuse[] = { (GLfloat)_diffuse.getX(), (GLfloat)_diffuse.getY(), (GLfloat)_diffuse.getZ(), (GLfloat)_diffuse.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_DIFFUSE, diffuse);

	GLfloat specular[] = { (GLfloat)_specular.getX(), (GLfloat)_specular.getY(), (GLfloat)_specular.getZ(),(GLfloat) _specular.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_SPECULAR, specular);

	glLightf(GL_LIGHT0 + _num, GL_SPOT_CUTOFF, _cut_off);

	GLfloat direction[] = { (GLfloat)_direction.getX(), (GLfloat)_direction.getY(), (GLfloat)_direction.getZ() };
	glLightfv(GL_LIGHT0 + _num, GL_SPOT_DIRECTION, direction);

	glLightf(GL_LIGHT0 + _num, GL_SPOT_EXPONENT, _exponent);
	return;
	/*GLfloat light_position[] = { (GLfloat)_position.getX(), (GLfloat)_position.getY(), (GLfloat)_position.getZ(), (GLfloat)_position.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_POSITION, light_position);

	GLfloat ambient[] = { (GLfloat)_ambient.getX(), (GLfloat)_ambient.getY(), (GLfloat)_ambient.getZ(), (GLfloat)_ambient.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_AMBIENT, ambient);

	GLfloat diffuse[] = { (GLfloat)_diffuse.getX(), (GLfloat)_diffuse.getY(), (GLfloat)_diffuse.getZ(), (GLfloat)_diffuse.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_DIFFUSE, diffuse);

	GLfloat specular[] = { (GLfloat)_specular.getX(), (GLfloat)_specular.getY(), (GLfloat)_specular.getZ(),(GLfloat) _specular.getW() };
	glLightfv(GL_LIGHT0 + _num, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0 + _num, GL_EXP, &_exponent);
	GLfloat direction[] = { (GLfloat)_direction.getX(),(GLfloat) _direction.getY(),(GLfloat) _direction.getZ() };
	glLightfv(GL_LIGHT0 + _num, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT0 + _num, GL_SPOT_CUTOFF, _cut_off);
	glLightfv(GL_LIGHT0 + _num, GL_CONSTANT_ATTENUATION, &_exponent);*/
		/*GLfloat a = 0.009, b = 0.0015, c = 0.001;

		glLightfv(GL_LIGHT0 + _num, GL_LINEAR_ATTENUATION, &b);
		glLightfv(GL_LIGHT0 + _num, GL_QUADRATIC_ATTENUATION, &c);*/
}
