/*
 * LightSource.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */
#include "stdlib.h"
#include "GL/glut.h"
#include "LightSource.h"

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
void LightSource::setPosition(Vector3* position){
	_position.set(position->getX(),position->getY(),position->getZ());
}
void LightSource::setDirection(Vector3 *direction){
	_direction.set(direction->getX(),direction->getY(),direction->getZ());
}
void LightSource::setCutOff(double cut_off){
	_cut_off = cut_off;
}
void LightSource::setExponent(double exponent){
	_exponent = exponent;
}
void LightSource::setAmbient(double ambient[4]){
	int i;
	for(i = 0; i < 4; i ++)
		_ambient[i] = ambient[i];

}
void LightSource::setDiffuse(double diffuse[4]){
	int i;
	for(i = 0; i < 4; i ++)
		_diffuse[i] = diffuse[i];
}
void LightSource::setSpecular(double specular[4]){
	int i;
	for(i = 0; i < 4; i ++)
		_specular[i] = specular[i];
}
void LightSource::draw(){
	// TODO
}

