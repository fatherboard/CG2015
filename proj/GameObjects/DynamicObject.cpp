/*
 * DynamicObject.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "DynamicObject.h"

DynamicObject::DynamicObject() {
	this->_speed = Vector3(0, 0, 0);
}

DynamicObject::~DynamicObject() {
	// TODO Auto-generated destructor stub
}

void DynamicObject::update(double delta_t){
	double new_x, new_y, new_z;

	new_x = this->_speed.getX() + this->_speed * delta_t;
	new_y = this->_speed.getY() + this->_speed * delta_t;
	new_z = this->_speed.getZ() + this->_speed * delta_t;

	this->_speed.set(new_x, new_y, new_z);
}

// nao esquecer que a nova posicao de um objecto em movimento
// e dada por: posicao_1 = posicao_0 + velocidade * delta_t
void DynamicObject::setSpeed(Vector3 speed){
	this->_speed.~Vector3();
	this->_speed = speed;
}
void DynamicObject::setSpeed(double x, double y, double z){
	this->_speed.~Vector3();
	this->_speed = Vector3::Vector3(x,y,z);
}
Vector3 DynamicObject::getSpeed(){
	return this->_speed;
}

