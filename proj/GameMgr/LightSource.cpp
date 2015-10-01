/*
 * LightSource.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "LightSource.h"

LightSource::LightSource(GLenum number) {
	this->_num = number;
}

LightSource::~LightSource() {
	// TODO Auto-generated destructor stub
}

bool LightSource::getState(){
	return this->_state;
}
bool LightSource::setState(bool state){
	this->_state = state;
	return this->_state;
}
GLenum LightSource::getNum(){
	return this->_num;
}
void LightSource::setPosition(Vector3 position){
	this->_position = position;
}
void LightSource::setDirection(Vector3 direction){
	this->_direction = direction;
}
void LightSource::setCutOff(double cut_off){
	this->_cut_off = cut_off;
}
void LightSource::setExponent(double exponent){
	this->_exponent = exponent;
}
void LightSource::setAmbient(double ambient[4]){
	int i;
	for(i = 0; i < 4; i ++)
		this->_ambient[i] = ambient[i];

}
void LightSource::setDiffuse(double diffuse[4]){
	int i;
	for(i = 0; i < 4; i ++)
		this->_diffuse[i] = diffuse[i];
}
void LightSource::setSpecular(double specular[4]){
	int i;
	for(i = 0; i < 4; i ++)
		this->_specular[i] = specular[i];
}
void LightSource::draw(){
	// TODO
}

