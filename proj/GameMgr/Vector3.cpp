/*
 * Vector3.cpp
 *
 *  Created on: 30 Sep 2015
 *      Author: eu
 */

#include "Vector3.h"

Vector3::Vector3() {
	_x = 0;
	_y = 0;
	_z = 0;
}

Vector3::Vector3(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
}

Vector3::~Vector3() {
	// TODO Auto-generated destructor stub
}

double Vector3::getX(){
	return _x;
}

double Vector3::getY(){
	return _y;
}

double Vector3::getZ(){
	return _z;
}

void Vector3::set(double x, double y, double z){
	_x = x;
	_y = y;
	_z = z;
}

/*bool Vector3::equals(Vector3 vec){
	if(this->_x != vec._x)
		return false;
	if(this->_y != vec._y)
		return false;
	if(this->_z != vec._z)
		return false;
	return true;
}

Vector3 Vector3::dotProduct(double num){
	this->_x *= num;
	this->_y *= num;
	this->_z *= num;
	return this;
}

Vector3 Vector3::add(Vector3 vec){
	this->_x += vec._x;
	this->_y += vec._y;
	this->_z += vec._z;
	return this;
}

Vector3 Vector3::subtr(Vector3 vec){
	this->_x -= vec._x;
	this->_y -= vec._y;
	this->_z -= vec._z;
	return this;
}*/

Vector3 Vector3::operator=(Vector3 vec){
	// TODO
	return Vector3(0,0,0);
}

Vector3 Vector3::operator*(double num){
	this->_x *= num;
	this->_y *= num;
	this->_z *= num;
	return this;
}

Vector3 Vector3::operator+(Vector3 vec){
	this->_x += vec._x;
	this->_y += vec._y;
	this->_z += vec._z;
	return this;
}

Vector3 Vector3::operator-(Vector3 vec){
	this->_x -= vec._x;
	this->_y -= vec._y;
	this->_z -= vec._z;
	return this;
}
