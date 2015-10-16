#include "Car.h"
#include <GL/glut.h>
#include <math.h>
#include "stdafx.h"
#include <iostream>

Car::Car(Vector3 *position) {
	setPosition(position);
	setSpeed(0, 0, 0);
	setDirecao(M_PI / 2, M_PI / 2, 0);
	_l = 3;
	_h = 1;

	computeVertices(Vector3(-1.5, -1.2, 0));
}

Car::~Car() {
//	free(_vertTL);
//	free(_vertTR);
//	free(_vertTF);
//	free(_vertBL);
//	free(_vertBR);
//	free(_vertBF);

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

	//glPushMatrix();
	//glTranslated(getPosition()->getX()- 37, getPosition()->getY()-0.7, getPosition()->getZ());
	//glRotatef(getRadian() * 180 / M_PI, 0, 0, 1);
	//glTranslated(getPosition()->getX()+28.5, getPosition()->getY()-0.7, getPosition()->getZ()); //28.5 -1
	//std::cout << "position X=" << getPosition()->getX() << "position Y=" << getPosition()->getY() << "\n";

	//eixo traseira direita
	glColor3f(0.6f, 0.6f, 0.6f);
	glPushMatrix();
	glTranslated(position.getX() + 1.6f, position.getY() - 2.0f,
			position.getZ());
	glScalef(0.5f, 1.0f, 1.0f);
	drawCube(wf);
	glPopMatrix();

	//eixo traseira esquerda
	glPushMatrix();
	glTranslated(position.getX() - 1.9f, position.getY() - 2.0f,
			position.getZ());
	glScalef(0.5, 1.0, 1.0);
	if (wf) {
		glutWireCube(1);
	} else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//eixo frontal direita
	glPushMatrix();
	glTranslated(position.getX() + 1.0f, position.getY() + 0.5f,
			position.getZ());
	glScalef(1.2, 0.6, 1.0);
	if (wf) {
		glutWireCube(1);
	} else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//eixo frontal esquerda
	glPushMatrix();
	glTranslated(position.getX() - 1.0f, position.getY() + 0.5f,
			position.getZ());
	glScalef(1.2, 0.6, 1.0);
	if (wf) {
		glutWireCube(1);
	} else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//retangulo, parte de tras do carro
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(position.getX(), position.getY() - 2.0f, position.getZ());
	glScalef(1.0, 0.5, 1.0);
	if (wf) {
		glutWireCube(3);
	} else {
		glutSolidCube(3);
	}
	glPopMatrix();

	//roda traseira direita
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslated(position.getX() + 2.3f, position.getY() - 2.0f,
			position.getZ());
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.4, 0.5, 100, 100);
	} else {
		glutSolidTorus(0.4, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda traseira esquerda
	glPushMatrix();
	glTranslated(position.getX() - 2.3f, position.getY() - 2.0f,
			position.getZ());
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.4, 0.5, 100, 100);
	} else {
		glutSolidTorus(0.4, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda frontal esquerda
	glPushMatrix();
	glTranslated(position.getX() - 1.6f, position.getY() + 0.5f,
			position.getZ());
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.2, 0.5, 100, 100);
	} else {
		glutSolidTorus(0.2, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda frontal direita
	glPushMatrix();
	glTranslated(position.getX() + 1.6f, position.getY() + 0.5f,
			position.getZ());
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf) {
		glutWireTorus(0.2, 0.5, 100, 100);
	} else {
		glutSolidTorus(0.2, 0.5, 100, 100);
	}
	glPopMatrix();

	//tubo de escape esquerdo
	glPushMatrix();
	glTranslated(position.getX() - 0.7f, position.getY() - 3.0f,
			position.getZ());
	glScalef(0.5, 0.5, 0.5);
	if (wf) {
		glutWireCube(1);
	} else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//tubo de escape direito
	glPushMatrix();
	glTranslated(position.getX() + 0.5f, position.getY() - 3.0f,
			position.getZ());
	glScalef(0.5, 0.5, 0.5);
	if (wf) {
		glutWireCube(1);
	} else {
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

	// CUBO ORIGEM - APAGAR
//	glColor3f(1, 1, 1);
//	glutSolidCube(1);
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

void Car::computeVertices(Vector3 origin) {
	_vertTL = new Vector3(origin); //new Vector3(origin.getX(), origin.getY(), origin.getZ());
	_vertTR = new Vector3(origin.getX() + _l, origin.getY(), origin.getZ());
	_vertTF = new Vector3(origin.getX() + _l / 2, computeSqrt(), origin.getZ());

	_vertBL = new Vector3(origin.getX(), origin.getY(), origin.getZ() - _h);
	_vertBR = new Vector3(origin.getX() + _l, origin.getY(),
			origin.getZ() - _h);
	_vertBF = new Vector3(origin.getX() + _l / 2, computeSqrt(),
			origin.getZ() - _h);

}
