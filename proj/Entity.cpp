/*
 * Entity.cpp
 *
 *  Created on: 30 Sep 2015
 *      Author: eu
 */

#include "Entity.h"

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

Vector3* Entity::getPosition(){
	return &_position;
}

Vector3* Entity::setPosition(double x, double y, double z){
	_position.set(x,y,z);
	return &_position;

}

Vector3* Entity::setPosition(Vector3* vec){
	_position.set(vec->getX(),vec->getY(),vec->getZ());
	return &_position;
}

