#include "Track.h"

int i;

Track::Track() {}

Track::~Track() {
	// TODO Auto-generated destructor stub
}

void Track::draw(){
	glColor3f(0.0f, 0.85f, 1.0f);
	glutSolidCube(100);
	glColor3f(1.0f, 0.3f, 0.0f);
	for (i = 0; i < 80; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-45, i - 40, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 85; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-45 + i, 40, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 30; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(39, 40 - i, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 50; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-9 + i, 10, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 20; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-10, i - 9, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 50; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-9 + i, -10, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 30; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(39, -10 - i, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 85; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-45 + i, -40, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 60; i++) {
		//lado esquerdo da pista

		glPushMatrix();
		glTranslatef(-35, i - 30, 0);
		glutSolidTorus(0.1, 0.3, 50, 50);
		glPopMatrix();
		i++;

	}
}
