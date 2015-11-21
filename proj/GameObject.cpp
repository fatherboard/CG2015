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
	setObjRadius(0);
}

GameObject::GameObject(double obj_radius){
	setObjRadius(obj_radius);
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

void GameObject::setObjRadius(double radius){
    obj_radius = radius;
}

double GameObject::getObjRadius(){
    return obj_radius;
}

void GameObject::setSize(double x, double y, double z){
    _size = new Vector3(x, y, z);
}

Vector3* GameObject::getSize(){
    return _size;
}

void GameObject::defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
								GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
								GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
								GLfloat Ke_r, GLfloat Ke_g, GLfloat Ke_b, GLfloat Ke_w,
								GLfloat Se){
	GLfloat Ka[] = { Ka_r, Ka_g, Ka_b, Ka_w };
	GLfloat Kd[] = { Kd_r, Kd_g, Kd_b, Kd_w };
	GLfloat Ks[] = { Ks_r, Ks_g, Ks_b, Ks_w };
	GLfloat Ke[] = { Ke_r, Ke_g, Ke_b, Ke_w };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Ks);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Ke);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &Se);
}

void GameObject::defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
								GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
								GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
								GLfloat Ke_r, GLfloat Ke_g, GLfloat Ke_b, GLfloat Ke_w,
								GLfloat se, GLuint texture){
	defineMaterial(	Ka_r, Ka_g, Ka_b, Ka_w,
					Kd_r, Kd_g, Kd_b, Kd_w,
					Ks_r, Ks_g, Ks_b, Ks_w,
					Ke_r, Ke_g, Ke_b, Ke_w,
					se);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	

}
