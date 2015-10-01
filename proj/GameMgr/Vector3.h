/*
 * Vector3.h
 *
 *  Created on: 30 Sep 2015
 *      Author: eu
 */
#pragma once

#ifndef PROJ_VECTOR3_H_
#define PROJ_VECTOR3_H_

class Vector3 {
protected:
	double _x;
	double _y;
	double _z;

public:
	Vector3();
	Vector3(double x, double y, double z);
	~Vector3();

	double getX();
	double getY();
	double getZ();
	void set(double x, double y, double z);
	/*bool equals(Vector3 vec);
	Vector3 dotProduct(double num);
	Vector3 add(Vector3 vec);
	Vector3 subtr(Vector3 vec);*/

	Vector3 operator=(Vector3 vec);
	Vector3 operator*(double num);
	Vector3 operator+(Vector3 vec);
	Vector3 operator-(Vector3 vec);

};

#endif /* PROJ_VECTOR3_H_ */
