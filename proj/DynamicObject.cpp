/*
 * DynamicObject.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "DynamicObject.h"

DynamicObject::DynamicObject() {
	// TODO
}

DynamicObject::~DynamicObject() {
	// TODO Auto-generated destructor stub
}

void DynamicObject::update(double delta_t){

		// TODO

}

// nao esquecer que a nova posicao de um objecto em movimento
// e dada por: posicao_1 = posicao_0 + velocidade * delta_t
void DynamicObject::setSpeed(Vector3* speed){
	_speed.set(speed->getX(),speed->getY(),speed->getZ());
}
void DynamicObject::setSpeed(double x, double y, double z){
	_speed.set(x,y,z);
}
Vector3* DynamicObject::getSpeed(){
	return &_speed;
}

