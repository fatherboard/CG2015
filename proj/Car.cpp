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

void Car::draw(int wf){

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(-10, -0.8, 0);

	//eixo tras direita
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(-26.75, -0.8, 0);
	glScalef(0.5, 1.0, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	//eixo tras esquerda
	glPushMatrix();
	glTranslated(-30.3, -0.8, 0);
	glScalef(0.5, 1.0, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	//eixo frente direita
	glPushMatrix();
	glTranslated(-27.9, 1.5, 0);
	glScalef(1.2, 0.6, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	//eixo frente esquerda
	glPushMatrix();
	glTranslated(-29.5, 1.5, 0);
	glScalef(1.2, 0.6, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	//tubo de escape esquerdo
	glPushMatrix();
	glColor3f(0.0, 0.0,0.0);
	glTranslated(-29.1, -1.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	//tubo de escape direito
	glPushMatrix();
	glTranslated(-28, -1.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	//roda direita traseira
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-26.2, -0.8, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90,1,0,0);
	glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();

	//roda esquerda traseira
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-31, -0.8, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.4, 0.5, 100, 100);
	glPopMatrix();

	//roda esquerda frente
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-30, 1.5, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.2, 0.5, 100, 100);
	glPopMatrix();

	//roda direita frente
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-27.05, 1.5, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.2, 0.5, 100, 100);
	glPopMatrix();

	//retangulo, parte de tras do carro
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslated(-28.5,-0.7,0);
	glScalef(1.0,0.5,1.0);
	glutSolidCube(3);
	glPopMatrix();

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
	if(wf)
		glBegin(GL_LINE);
	else
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