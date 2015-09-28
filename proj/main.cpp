#include <iostream>
//#include <GL/GL.h>
#include <GL/glut.h>

void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	//gluPerspective(90, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(0,0,0);
	glutSolidCube(1);
	glPopMatrix();

	glFlush();
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (-1, -1);
	glutCreateWindow("Micromachines");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
