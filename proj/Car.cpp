#include "Car.h"
#include <GL/glut.h>
#include <math.h>


Car::Car(double x, double y, double z) {
	setPosition(x,y,z);
	setSpeed(0,0,0);
	this->_l = 3;
	this->_h = 1;

	computeVertices(-30, 0, 0);
}

Car::~Car() {
	free(_vertTL);
	free(_vertTR);
	free(_vertTF);
	free(_vertBL);
	free(_vertBR);
	free(_vertBF);
}


void Car::draw(int wf) {
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(),getPosition()->getZ());

	//eixo tras direita
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(-26.75, -0.8, 0);
	glScalef(0.5, 1.0, 1.0);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();

	//eixo tras esquerda
	glPushMatrix();
	glTranslated(-30.3, -0.8, 0);
	glScalef(0.5, 1.0, 1.0);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();

	//eixo frente direita
	glPushMatrix();
	glTranslated(-27.9, 1.5, 0);
	glScalef(1.2, 0.6, 1.0);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();

	//eixo frente esquerda
	glPushMatrix();
	glTranslated(-29.5, 1.5, 0);
	glScalef(1.2, 0.6, 1.0);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();

	//tubo de escape esquerdo
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(-29.1, -1.6, 0);
	glScalef(0.5, 0.5, 0.5);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();

	//tubo de escape direito
	glPushMatrix();
	glTranslated(-28, -1.6, 0);
	glScalef(0.5, 0.5, 0.5);
	if (wf)
		glutWireCube(1);
	else
		glutSolidCube(1);
	glPopMatrix();

	//roda direita traseira
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-26.2, -0.8, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf)
		glutWireTorus(0.4, 0.5, 100, 100);
	else
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();

	//roda esquerda traseira
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-31, -0.8, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf)
		glutWireTorus(0.4, 0.5, 100, 100);
	else
		glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();

	//roda esquerda frente
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-30, 1.5, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf)
		glutWireTorus(0.2, 0.5, 100, 100);
	else
		glutSolidTorus(0.2, 0.5, 100, 100);
	glPopMatrix();

	//roda direita frente
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-27.05, 1.5, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (wf)
		glutWireTorus(0.2, 0.5, 100, 100);
	else
		glutSolidTorus(0.2, 0.5, 100, 100);
	glPopMatrix();

	//retangulo, parte de tras do carro
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(-28.5, -0.7, 0);
	glScalef(1.0, 0.5, 1.0);
	if (wf)
		glutSolidCube(3);
	else
		glutSolidCube(3);
	glPopMatrix();
	

	// falta algum refactoring para tornar o codigo mais flexivel e eficiente
	glBegin(GL_TRIANGLES);

	// topo
	glVertex3f(_vertTL[0], _vertTL[1], _vertTL[2]);
	glVertex3f(_vertTF[0], _vertTF[1], _vertTF[2]);
	glVertex3f(_vertTR[0], _vertTR[1], _vertTR[2]);

	// fundo
	glVertex3f(_vertBL[0], _vertBL[1], _vertBL[2]);
	glVertex3f(_vertBF[0], _vertBF[1], _vertBF[2]);
	glVertex3f(_vertBR[0], _vertBR[1], _vertBR[2]);

	glEnd();

	// laterais
	glBegin(GL_POLYGON);
	glVertex3f(_vertTL[0], _vertTL[1], _vertTL[2]);
	glVertex3f(_vertTF[0], _vertTF[1], _vertTF[2]);
	glVertex3f(_vertBF[0], _vertBF[1], _vertBF[2]);
	glVertex3f(_vertBL[0], _vertBL[1], _vertBL[2]);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(_vertTR[0], _vertTR[1], _vertTR[2]);
	glVertex3f(_vertTF[0], _vertTF[1], _vertTF[2]);
	glVertex3f(_vertBF[0], _vertBF[1], _vertBF[2]);
	glVertex3f(_vertBR[0], _vertBR[1], _vertBR[2]);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(_vertTL[0], _vertTL[1], _vertTL[2]);
	glVertex3f(_vertTR[0], _vertTR[1], _vertTR[2]);
	glVertex3f(_vertBR[0], _vertBR[1], _vertBR[2]);
	glVertex3f(_vertBL[0], _vertBL[1], _vertBL[2]);
	glEnd();
	glPopMatrix();
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

float *writeTo3FloatArray(float x, float y, float z) {
	float *array = (float *)malloc(3 * sizeof(float));

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
