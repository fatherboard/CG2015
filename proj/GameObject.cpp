/*
 * GameObject.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */
#include "stdafx.h"
#include "GameObject.h"
#include "DynamicObject.h"

GameObject::GameObject() {
	// TODO Auto-generated constructor stub
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

void GameObject::draw(){
	// TODO
}
void GameObject::update(unsigned long delta_t){
	DynamicObject* v = dynamic_cast<DynamicObject*>(this);
	if (v != 0) {
		// old was safely casted to NewType
		v->update(delta_t);
	}
}
