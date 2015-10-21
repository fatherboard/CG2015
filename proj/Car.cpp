#include "Car.h"
#include <GL/glut.h>
#include <math.h>
#include "stdafx.h"
#include <iostream>

//Vector3 _position;

Car::Car(Vector3 *position) {
	setPosition(position);
	//_position.set(position->getX(), position->getY(), position->getZ());
	setSpeed(0, 0, 0);
	setDirecao(M_PI / 2, M_PI / 2, 0);
	_l = 3.0f;

	computeVertices();
}

Car::~Car() {
	_vertTL->~Vector3();
	_vertTR->~Vector3();
	_vertTF->~Vector3();
	_vertBL->~Vector3();
	_vertBR->~Vector3();
	_vertBF->~Vector3();
}

void Car::draw() {
	draw(0);
}

void Car::drawCube(int wf) {
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
}

void Car::draw(int wf) {

	//eixo traseira esquerda
	glColor3f(0.6f, 0.6f, 0.6f);
	glPushMatrix();
	glTranslated(-2.0f, 1.7f, 50);
	glScalef(1.0f, 0.5f, 1.0f);
	drawCube(wf);
	glPopMatrix();

	//eixo traseira direita
	glPushMatrix();
	glTranslated(-2.0f, - 1.7f, 50);
	glScalef(1.0, 0.5, 1.0);
	drawCube(wf);
	glPopMatrix();

	//eixo frontal direita
	glPushMatrix();
	glTranslated(0.5f, 1.0f, 50);
	glScalef(0.6, 1.2, 1.0);
	if (wf) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//eixo frontal esquerda
	glPushMatrix();
	glTranslated(0.5f, - 1.0f, 50);
	glScalef(0.6, 1.2, 1.0);
	if (wf) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//retangulo, parte de tras do carro
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(-2.1, 0.0f, 50);
	glScalef(0.5, 1.0, 1.0);
	if (wf) {
		glutWireCube(3);
	}
	else {
		glutSolidCube(3);
	}
	glPopMatrix();

	//roda traseira direita
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslated(-2.0f, 2.3f, 50);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.4, 0.5, 100, 100);
	}
	else {
		glutSolidTorus(0.4, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda traseira esquerda
	glPushMatrix();
	glTranslated(- 2.0f, -2.3f, 50);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.4, 0.5, 100, 100);
	}
	else {
		glutSolidTorus(0.4, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda frontal esquerda
	glPushMatrix();
	glTranslated(0.5f,- 1.6f, 50);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.2, 0.5, 100, 100);
	}
	else {
		glutSolidTorus(0.2, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda frontal direita
	glPushMatrix();
	glTranslated(0.5f, 1.6f, 50);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.2, 0.5, 100, 100);
	}
	else {
		glutSolidTorus(0.2, 0.5, 100, 100);
	}
	glPopMatrix();

	//tubo de escape esquerdo
	glPushMatrix();
	glTranslated(-3.0f, -0.7f, 50);
	glScalef(0.5, 0.5, 0.5);
	if (wf) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//tubo de escape direito
	glPushMatrix();
	glTranslated(-3.0f, 0.5f, 50);
	glScalef(0.5, 0.5, 0.5);
	if (wf) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	glColor3f(1.0f, 0.0f, 0.0f);
	if (wf)
		glBegin(GL_LINE);
	else
		glBegin(GL_TRIANGLES);

	// topo
	glVertex3f(_vertTL->getX(), _vertTL->getY(), _vertTL->getZ());
	glVertex3f(_vertTF->getX(), _vertTF->getY(), _vertTF->getZ());
	glVertex3f(_vertTR->getX(), _vertTR->getY(), _vertTF->getZ());

	// fundo
	glVertex3f(_vertBL->getX(), _vertBL->getY(), _vertBL->getZ());
	glVertex3f(_vertBR->getX(), _vertBR->getY(), _vertBR->getZ());
	glVertex3f(_vertBF->getX(), _vertBF->getY(), _vertBF->getZ());

	glEnd();

	// laterais
	if (wf)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_vertTL->getX(), _vertTL->getY(), _vertTL->getZ());
	glVertex3f(_vertTF->getX(), _vertTF->getY(), _vertTF->getZ());
	glVertex3f(_vertBF->getX(), _vertBF->getY(), _vertBF->getZ());
	glVertex3f(_vertBL->getX(), _vertBL->getY(), _vertBL->getZ());
	glEnd();

	if (wf)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_vertTR->getX(), _vertTR->getY(), _vertTR->getZ());
	glVertex3f(_vertTF->getX(), _vertTF->getY(), _vertTF->getZ());
	glVertex3f(_vertBF->getX(), _vertBF->getY(), _vertBF->getZ());
	glVertex3f(_vertBR->getX(), _vertBR->getY(), _vertBR->getZ());
	glEnd();

	if (wf)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_vertTL->getX(), _vertTL->getY(), _vertTL->getZ());
	glVertex3f(_vertTR->getX(), _vertTR->getY(), _vertTR->getZ());
	glVertex3f(_vertBR->getX(), _vertBR->getY(), _vertBR->getZ());
	glVertex3f(_vertBL->getX(), _vertBL->getY(), _vertBL->getZ());
	glEnd();
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

void Car::computeVertices() {
	_vertTL = new Vector3(-1.3f, _l / 2, 52);
	_vertTR = new Vector3(-1.3f, -_l / 2, 52);
	_vertTF = new Vector3(1.3, 0, 52);

	_vertBL = new Vector3(-1.3f,_l / 2, 50);
	_vertBR = new Vector3(-1.3f,_l / 2, 50);
	_vertBF = new Vector3(1.3, 0,50);

}
