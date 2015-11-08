/*
 * DynamicObject.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "DynamicObject.h"

DynamicObject::DynamicObject(){
	// TODO
}

DynamicObject::~DynamicObject() {
	// TODO Auto-generated destructor stub
}

void DynamicObject::update(unsigned long delta_t){

	setPosition(getPosition()->getX() + getSpeed()->getX()*delta_t, getPosition()->getY() + getSpeed()->getY()*delta_t, getPosition()->getZ());

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
Vector3* DynamicObject::getDirecao() {
	return &_direcao;
}

void DynamicObject::setDirecao(Vector3* direcao) {
	_direcao.set(direcao->getX(), direcao->getY(), direcao->getZ());
}
void DynamicObject::setDirecao(double x, double y, double z) {
	_direcao.set(cos(x), sin(y), z);
}

double DynamicObject::getRadian() {
	return _radian;
}

void DynamicObject::setRadian(double radian) {
	_radian = radian;
}

