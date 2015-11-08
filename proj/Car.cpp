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
	glBegin(GL_QUADS);
        glNormal3f(0,0,1);
        glVertex3f(_TL->getX(), _TL->getY(), _TL->getZ());
        glVertex3f(_TBL->getX(), _TBL->getY(), _TBL->getZ());
        glVertex3f(_TBR->getX(), _TBR->getY(), _TBR->getZ());
        glVertex3f(_TR->getX(), _TR->getY(), _TR->getZ());
	glEnd();

	// lateral esquerda da parte de tras do carro
	glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(_TL->getX(), _TL->getY(), _TL->getZ());
        glVertex3f(-2.8, _l/2, 52);
        glVertex3f(-2.8, -_l/2, 52);
        glVertex3f(_BL->getX(), _BL->getY(), _BL->getZ());
	glEnd();

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

    // triangulos
	glColor3f(1, 0, 0);
	defineMaterial(	1.00, 0.00, 0.00, 1.00,
                    0.90, 0.00, 0.00, 1.00,
                    1.00, 1.00, 1.00, 1.00,
                    0,0,0,1,
                    1);

	if (_wireframe)
		glBegin(GL_LINE);
	else
		glBegin(GL_TRIANGLES);

	// topo
	glVertex3f(_TL->getX(), _TL->getY(), _TL->getZ());
	glVertex3f(_TF->getX(), _TF->getY(), _TF->getZ());
	glVertex3f(_TR->getX(), _TR->getY(), _TF->getZ());


	// fundo
	glVertex3f(_BL->getX(), _BL->getY(), _BL->getZ());
	glVertex3f(_BR->getX(), _BR->getY(), _BR->getZ());
	glVertex3f(_BF->getX(), _BF->getY(), _BF->getZ());

	glEnd();

	// laterais
	if (_wireframe)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_TL->getX(), _TL->getY(), _TL->getZ());
	glVertex3f(_TF->getX(), _TF->getY(), _TF->getZ());
	glVertex3f(_BF->getX(), _BF->getY(), _BF->getZ());
	glVertex3f(_BL->getX(), _BL->getY(), _BL->getZ());
	glEnd();

	if (_wireframe)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_TR->getX(), _TR->getY(), _TR->getZ());
	glVertex3f(_TF->getX(), _TF->getY(), _TF->getZ());
	glVertex3f(_BF->getX(), _BF->getY(), _BF->getZ());
	glVertex3f(_BR->getX(), _BR->getY(), _BR->getZ());
	glEnd();

	if (_wireframe)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);
	glVertex3f(_TL->getX(), _TL->getY(), _TL->getZ());
	glVertex3f(_TR->getX(), _TR->getY(), _TR->getZ());
	glVertex3f(_BR->getX(), _BR->getY(), _BR->getZ());
	glVertex3f(_BL->getX(), _BL->getY(), _BL->getZ());
	glEnd();

	glPopMatrix();
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

void Car::computeVertices() {
	_TL = new Vector3(-1.3f, _l / 2, 52);
	_TR = new Vector3(-1.3f, -_l / 2, 52);
	_TF = new Vector3(1.3, 0, 52);

	_BL = new Vector3(-1.3f, _l / 2, 50);
	_BR = new Vector3(-1.3f, _l / 2, 50);
	_BF = new Vector3(1.3, 0,50);

	_TBL = new Vector3(-2.8, _l/2, 52);
	_TBR = new Vector3(-2.8, _l/2, 50);

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
