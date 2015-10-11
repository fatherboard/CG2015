/*
 * Car.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Car.h"
#include <GL/glut.h>
#include <math.h>

Car::Car(float x, float y, float z, float l, float h) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_l = l;
	this->_h = h;

	computeVertices(x, y, z);
}

Car::~Car() {
	free(_vertTL);
	free(_vertTR);
	free(_vertTF);
	free(_vertBL);
	free(_vertBR);
	free(_vertBF);
}

void Car::draw() {
	draw(0);
}

void Car::draw(int wf) {

	// corpo
	glPushMatrix();
	glColor3f(1, 1, 0);
	glScalef(1, 0.75f, 1 / _h); // ver a dimensao zz
	glTranslatef(_x, _y, _z);
	glTranslatef(_l / 2, -1 * _l / 2, 0);
	if (wf)
		glutWireCube(_l);
	else
		glutSolidCube(_l);
	glPopMatrix();

	// capo
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	// topo capo
	glVertex3f(_vertTL[0], _vertTL[1], _vertTL[2]);
	glVertex3f(_vertTF[0], _vertTF[1], _vertTF[2]);
	glVertex3f(_vertTR[0], _vertTR[1], _vertTR[2]);

	// fundo capo
	glVertex3f(_vertBL[0], _vertBL[1], _vertBL[2]);
	glVertex3f(_vertBF[0], _vertBF[1], _vertBF[2]);
	glVertex3f(_vertBR[0], _vertBR[1], _vertBR[2]);

	glEnd();

	// laterais capo
	if (wf)
		glBegin(GL_LINE);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_vertTL[0], _vertTL[1], _vertTL[2]);
	glVertex3f(_vertTF[0], _vertTF[1], _vertTF[2]);
	glVertex3f(_vertBF[0], _vertBF[1], _vertBF[2]);
	glVertex3f(_vertBL[0], _vertBL[1], _vertBL[2]);
	glEnd();

	if (wf)
		glBegin(GL_LINE);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_vertTR[0], _vertTR[1], _vertTR[2]);
	glVertex3f(_vertTF[0], _vertTF[1], _vertTF[2]);
	glVertex3f(_vertBF[0], _vertBF[1], _vertBF[2]);
	glVertex3f(_vertBR[0], _vertBR[1], _vertBR[2]);
	glEnd();

	if (wf)
		glBegin(GL_LINE);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_vertTL[0], _vertTL[1], _vertTL[2]);
	glVertex3f(_vertTR[0], _vertTR[1], _vertTR[2]);
	glVertex3f(_vertBR[0], _vertBR[1], _vertBR[2]);
	glVertex3f(_vertBL[0], _vertBL[1], _vertBL[2]);
	glEnd();

	// eixo dianteiro (ainda nao esta como queremos)
	/*glMatrixMode(GL_MODELVIEW);
	 glPushMatrix();
	 glColor3f(0, 1, 0);
	 glTranslatef(_x, _y, _z);
	 glTranslatef(_l /2, _l / 2, 0);
	 glScalef(_l, 1, 1);
	 glutSolidSphere(1, 50, 50);
	 glPopMatrix();*/

	glFlush();
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

float *writeTo3FloatArray(float x, float y, float z) {
	float *array = (float *) malloc(3 * sizeof(float));

	array[0] = x;
	array[1] = y;
	array[2] = z;

	return array;
}

void Car::computeVertices(float x, float y, float z) {
	_vertTL = writeTo3FloatArray(x, y, z);
	_vertTR = writeTo3FloatArray(x + _l, y, z);
	_vertTF = writeTo3FloatArray(x + _l / 2, computeSqrt(), z);

	_vertBL = writeTo3FloatArray(x, y, z - _h);
	_vertBR = writeTo3FloatArray(x + _l, y, z - _h);
	_vertBF = writeTo3FloatArray(x + _l / 2, computeSqrt(), z - _h);

}
