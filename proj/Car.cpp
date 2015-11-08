#include <vector>
#include "Car.h"

//Vector3 _position;
extern int _wireframe;

Car::Car(Vector3 *position) {
	setPosition(position);
	setSpeed(0, 0, 0);
	setDirecao(0, 0, 0);
	setRadian(0);
	_l = 3;

	setObjRadius(3);

	computeVertices();
}

Car::~Car() {
	_TL->~Vector3();
	_TR->~Vector3();
	_TF->~Vector3();
	_BL->~Vector3();
	_BR->~Vector3();
	_BF->~Vector3();
}

void Car::drawCube(int _wireframe) {
	if (_wireframe)
		glutWireCube(1);
	else
		glutSolidCube(1);
}

void carVertex(Vector3* vec){
    glVertex3f(vec->getX(), vec->getY(), vec->getZ());
}

void carTriangle(Vector3* a, Vector3* b, Vector3* c, Vector3* normal){
    glBegin(GL_TRIANGLES);
    glNormal3f(normal->getX(), normal->getY(), normal->getZ());
    carVertex(a);
    carVertex(b);
    carVertex(c);
    glEnd();
}

// enviar os vertices no sentido anti-horario
void carRectangle(Vector3* a, Vector3* b, Vector3* c, Vector3* d, Vector3* normal){
    glBegin(GL_QUADS);
    //glNormal3f(normal->getX(), normal->getY(), normal->getZ());
    carVertex(a);
    carVertex(b);
    carVertex(c);
    carVertex(d);
    glEnd();
}

void Car::draw() {

    glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glRotatef(getRadian()*180/M_PI, 0, 0, 1);

    glColor3f(0.6, 0.6, 0.6);

    defineMaterial(	0.60, 0.60, 0.60, 1.00,
                    0.90, 0.00, 0.00, 1.00,
                    1.00, 1.00, 1.00, 1.00,
                    0,0,0,1,
                    1);

	//eixo traseira esquerda
	glPushMatrix();
	glTranslated(-2, 1, 50);
	glScalef(1, 0.5, 1);
	drawCube(_wireframe);
	glPopMatrix();

	//eixo traseira direita
	glPushMatrix();
	glTranslated(-2, - 1.7, 50);
	glScalef(1, 0.5, 1);
	drawCube(_wireframe);
	glPopMatrix();

	//eixo frontal direita
	glPushMatrix();
	glTranslated(0.5, 1, 50);
	glScalef(0.6, 1.2, 1);
	if (_wireframe) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//eixo frontal esquerda
	glPushMatrix();
	glTranslated(0.5, - 1, 50);
	glScalef(0.6, 1.2, 1);
	if (_wireframe) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

    // rectangulos
    glColor3f(1, 0, 0);
    defineMaterial(	1.00, 0.00, 0.00, 1.00,
                    0.90, 0.00, 0.00, 1.00,
                    1.00, 1.00, 1.00, 1.00,
                    0,0,0,1,
                    1);

    // topo da parte de tras do carro
	carRectangle(_TL, _TR, _TBR, _TBL, new Vector3(0,0,1));
	// traseira da parte de tras do carro
	carRectangle(_TBR, _BBR, _BBL, _TBL, new Vector3(-1,0,0));
	// lateral esquerda da parte de tras do carro
	carRectangle(_TL, _TBL, _BBL, _BL, new Vector3(0,1,0));
	// lateral direita da parte de tras do carro
	carRectangle(_TR, _BR, _BBR, _TBR, new Vector3(0,-1,0));

    // topo do capo do carro
    carTriangle(_TL, _TF, _TR, new Vector3(0,0,1));
    // lateral esquerda do capo do carro
    carRectangle(_TL, _TF, _BF, _BL, new Vector3(1/sqrt(2), 1/sqrt(2), 0));
    // lateria direita do capo do carro
    carRectangle(_TR, _TF, _BF, _BR, new Vector3(1/sqrt(2), -1/sqrt(2), 0));






    // rodas
    glColor3f(0, 0, 0);
    defineMaterial(	0.00, 0.00, 0.00, 1.00,
                    0.90, 0.00, 0.00, 1.00,
                    1.00, 1.00, 1.00, 1.00,
                    0,0,0,1,
                    1);

	//roda traseira direita
	glPushMatrix();
	glTranslated(-2, 2.3f, 50);
	glRotatef(90, 1, 0, 0);
	if (_wireframe) {
		glutWireTorus(0.4, 0.5, 100, 100);
	}
	else {
		glutSolidTorus(0.4, 0.5, 100, 100);
	}
	glPopMatrix();

	//roda traseira esquerda
	glPushMatrix();
	glTranslated(- 2, -2.3f, 50);
	glRotatef(90, 1, 0, 0);
	if (_wireframe) {
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
	if (_wireframe) {
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
	if (_wireframe) {
		glutWireTorus(0.2, 0.5, 100, 100);
	}
	else {
		glutSolidTorus(0.2, 0.5, 100, 100);
	}
	glPopMatrix();

	//tubo de escape esquerdo
	glPushMatrix();
	glTranslated(-3, -0.7f, 50);
	glScalef(0.5, 0.5, 0.5);
	if (_wireframe) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	//tubo de escape direito
	glPushMatrix();
	glTranslated(-3, 0.5f, 50);
	glScalef(0.5, 0.5, 0.5);
	if (_wireframe) {
		glutWireCube(1);
	}
	else {
		glutSolidCube(1);
	}
	glPopMatrix();

	glPopMatrix();
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

void Car::computeVertices() {
	_TL = new Vector3(-1.3, _l/2, 52);
	_TR = new Vector3(-1.3, -_l/2, 52);
	_TF = new Vector3(1.3, 0, 52);

	_BL = new Vector3(-1.3, _l/2, 50);
	_BR = new Vector3(-1.3, -_l/2, 50);
	_BF = new Vector3(1.3, 0, 50);

	_TBL = new Vector3(-2.8, _l/2, 52);
	_TBR = new Vector3(-2.8, -_l/2, 52);

	_BBL = new Vector3(-2.8, _l/2, 50);
	_BBR = new Vector3(-2.8, -_l/2, 50);
}

void Car::carAcelera(unsigned long delta_t) {
	if (getSpeed()->getX() >= 0.005 || getSpeed()->getY() >= 0.005) {
		setSpeed(getSpeed()->getX(), getSpeed()->getY(), getSpeed()->getZ());
	}
	else
		setSpeed(getSpeed()->getX() + ACCELERATION_FORWARD * getDirecao()->getX() * delta_t, getSpeed()->getY() + ACCELERATION_FORWARD * getDirecao()->getY() * delta_t, getSpeed()->getZ());
}

void Car::carTrava(unsigned long delta_t) {
	setSpeed(getSpeed()->getX() - ACCELERATION_BACKWARD * getDirecao()->getX() * delta_t, getSpeed()->getY() - ACCELERATION_BACKWARD * getDirecao()->getY() * delta_t, getSpeed()->getZ());
}

void Car::Esquerda(unsigned long delta_t) {
	setRadian(getRadian() + ROTATION_SPEED * delta_t);
	if (getRadian() > M_PI) {
		setRadian(-M_PI);
	}
	else if (getRadian() < -M_PI) {
		setRadian(M_PI);
	}
	setDirecao(getRadian(), getRadian(), 0);
}

void Car::Direita(unsigned long delta_t) {
	setRadian(getRadian() - ROTATION_SPEED * delta_t);
	if (getRadian() > M_PI) {
		setRadian(-M_PI);
	}
	else if (getRadian() < -M_PI) {
		setRadian(M_PI);
	}
	setDirecao(getRadian(), getRadian(), 0);
}

void Car::carDesacelera(unsigned long delta_t, bool sentido) {
	if (getSpeed()->getX() < 0.000005 || getSpeed()->getY() < 0.000005) {
		setSpeed(0,0,0);
	}
	else if(sentido)
		setSpeed(getSpeed()->getX() + ACCELERATION_FORWARD * getDirecao()->getX() * 1/delta_t, getSpeed()->getY() + ACCELERATION_FORWARD * getDirecao()->getY() * 1/delta_t, getSpeed()->getZ());
	else if(sentido==false)
		setSpeed(getSpeed()->getX() - ACCELERATION_BACKWARD * getDirecao()->getX() * 1/delta_t, getSpeed()->getY() - ACCELERATION_BACKWARD * getDirecao()->getY() * 1/delta_t, getSpeed()->getZ());
}
