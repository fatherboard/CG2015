#include "Track.h"

int i;

Track::Track() {
}

Track::~Track() {
	// TODO Auto-generated destructor stub
}

void Track::drawCheerio(){
	if (wf)
		glutWireTorus(0.1, 0.3, 50, 50);
	else
		glutSolidTorus(0.1, 0.3, 50, 50);
}

void Track::draw(){
	//glColor3f(0.75f,0.75f, 0.75f);
	glColor3f(1,1,1);
	glutSolidCube(100);
	glColor3f(1.0f, 0.3f, 0.0f);
	for (i = 0; i < 80; i++) {
		//1

		glPushMatrix();
		glTranslatef(-45, i - 40, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 85; i++) {
		//2

		glPushMatrix();
		glTranslatef(-45 + i, 40, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 30; i++) {
		//3

		glPushMatrix();
		glTranslatef(39, 40 - i, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 50; i++) {
		//4

		glPushMatrix();
		glTranslatef(-9 + i, 10, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 20; i++) {
		//5

		glPushMatrix();
		glTranslatef(-10, i - 9, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 50; i++) {
		//6

		glPushMatrix();
		glTranslatef(-9 + i, -10, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 30; i++) {
		//7

		glPushMatrix();
		glTranslatef(39, -10 - i, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 85; i++) {
		//8

		glPushMatrix();
		glTranslatef(-45 + i, -40, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}

	for (i = 0; i < 56; i++) {
		//in:1

		glPushMatrix();
		glTranslatef(-30, i - 28, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 55; i++) {
		//in:2

		glPushMatrix();
		glTranslatef(-30 + i, 28, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 8; i++) {
		//in:3

		glPushMatrix();
		glTranslatef(26, 28 - i, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 50; i++) {
		//in:4

		glPushMatrix();
		glTranslatef(-22 + i, 20, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 42; i++) {
		//in:5

		glPushMatrix();
		glTranslatef(-24, i - 20, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 50; i++) {
		//in:6

		glPushMatrix();
		glTranslatef(-22 + i, -20, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 8; i++) {
		//in:7

		glPushMatrix();
		glTranslatef(26, -28 + i, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
	for (i = 0; i < 55; i++) {
		//in:2

		glPushMatrix();
		glTranslatef(-30 + i, -28, 0);
		drawCheerio();
		glPopMatrix();
		i++;

	}
}
