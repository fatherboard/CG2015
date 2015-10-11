/*
 * Car.cpp
 *
 *  Created on: 30/09/2015
 *      Author: Pedro
 */

#include "Car.h"
#include <GL/glut.h>
#include <math.h>

Car::Car() {
	this->_hoodHeight = 0;
}

Car::Car(float hoodHeight) {

	this->_hoodHeight = hoodHeight;

}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

void Car::draw() {
	glColor3f(1, 0, 0);

	// falta algum refactoring para tornar o codigo mais flexivel e eficiente
	glBegin(GL_TRIANGLES);

	// topo
	glVertex3f(0, 0, 0);
	glVertex3f(2.5f, getFrontVertexY(2.5f, 5.0f), 0);
	glVertex3f(5.0f, 0, 0);

	// fundo
	glVertex3f(0, 0, -1 * _hoodHeight);
	glVertex3f(2.5f, getFrontVertexY(2.5f, 5.0f), -1 * _hoodHeight);
	glVertex3f(5.0f, 0, -1 * _hoodHeight);

	glEnd();

	// laterais
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 5, 0);
	glVertex3f(0, 5, -1 * _hoodHeight);
	glVertex3f(0, 0, -1 * _hoodHeight);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(2.5f, getFrontVertexY(2.5f, 5.0f), 0);
	glVertex3f(2.5f, getFrontVertexY(2.5f, 5.0f), -1 * _hoodHeight);
	glVertex3f(0, 0, -1 * _hoodHeight);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(2.5f, getFrontVertexY(2.5f, 5.0f), 0);
	glVertex3f(5, 0, 0);
	glVertex3f(5, 0, -1 * _hoodHeight);
	glVertex3f(2.5f, getFrontVertexY(2.5f, 5.0f), -1 * _hoodHeight);
	glEnd();

	glFlush();
}

float Car::getFrontVertexY(float x, float hypotenuse) {
	return sqrt(abs(pow(hypotenuse, 2) - pow(x, 2)));
}
