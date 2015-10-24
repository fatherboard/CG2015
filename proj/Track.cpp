#include "Track.h"

int i;

Track::Track(){
	wf = 0;
}

Track::~Track() {
	// TODO Auto-generated destructor stub
}

void Track::drawCheerio(){
	if (wf)
		glutWireTorus(0.25, 0.9, 50, 50);
	else
		glutSolidTorus(0.25, 0.9, 50, 50);
}

void Track::draw(){
	//glColor3f(0.75f,0.75f, 0.75f);
	glColor3f(1,1,1);
	glutSolidCube(100);
	glColor3f(1.0f, 0.3f, 0.0f);
	for (i = 0; i < 80; i=i+4) {
		//1

		glPushMatrix();
		glTranslatef(-45, i - 40, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 85; i=i+4) {
		//2

		glPushMatrix();
		glTranslatef(-45 + i, 40, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 30; i=i+4) {
		//3

		glPushMatrix();
		glTranslatef(39, 40 - i, 50);
		drawCheerio();
		glPopMatrix();

	}

	for (i = 0; i < 50; i=i+4) {
		//4

		glPushMatrix();
		glTranslatef(-9 + i, 10, 50);
		drawCheerio();
		glPopMatrix();

	}

	for (i = 0; i < 20; i=i+4) {
		//5

		glPushMatrix();
		glTranslatef(-10, i - 9, 50);
		drawCheerio();
		glPopMatrix();

	}

	for (i = 0; i < 50; i=i+4) {
		//6

		glPushMatrix();
		glTranslatef(-9 + i, -10, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 30; i=i+4) {
		//7

		glPushMatrix();
		glTranslatef(39, -10 - i, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 85; i=i+4) {
		//8

		glPushMatrix();
		glTranslatef(-45 + i, -40, 50);
		drawCheerio();
		glPopMatrix();

	}

	for (i = 0; i < 56; i=i+4) {
		//in:1

		glPushMatrix();
		glTranslatef(-30, i - 28, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 55; i=i+4) {
		//in:2

		glPushMatrix();
		glTranslatef(-30 + i, 28, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 8; i=i+4) {
		//in:3

		glPushMatrix();
		glTranslatef(26, 28 - i, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 50; i=i+4) {
		//in:4

		glPushMatrix();
		glTranslatef(-22 + i, 20, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 42; i=i+4) {
		//in:5

		glPushMatrix();
		glTranslatef(-24, i - 20, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 50; i=i+4) {
		//in:6

		glPushMatrix();
		glTranslatef(-22 + i, -20, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 8; i=i+4) {
		//in:7

		glPushMatrix();
		glTranslatef(26, -28 + i, 50);
		drawCheerio();
		glPopMatrix();

	}
	for (i = 0; i < 55; i=i+4) {
		//in:2

		glPushMatrix();
		glTranslatef(-30 + i, -28, 50);
		drawCheerio();
		glPopMatrix();

	}
}
