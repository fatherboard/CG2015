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

Vector3::Vector3(Vector3* vec){
    _x = vec->getX();
    _y = vec->getY();
    _z = vec->getZ();
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

Vector3 Vector3::operator=(Vector3 *vec) {

	if (_x != vec->getX() && _y != vec->getY() && _z != vec->getZ()) {
		return *this;
	}
	return *vec;
}

Vector3 Vector3::operator*(double num) {
		_x *= num;
		_y *= num;
		_z *= num;
		return *this;
}

Vector3 Vector3::operator+(Vector3 *vec){
	_x += vec->getX();
	_y += vec->getY();
	_z += vec->getZ();
	return *this;
}

Vector3 Vector3::operator-(Vector3 *vec){
	_x -= vec->getX();
	_y -= vec->getY();
	_z -= vec->getZ();
	return *this;
}
