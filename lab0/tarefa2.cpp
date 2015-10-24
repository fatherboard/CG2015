#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// cor do fundo
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0f, 1.0f, 0.0f); 	// RGB: 0, 255, 0 (verde)
	glBegin(GL_POLYGON);			// comeca a definicao do poligono
	glVertex3f (-1.0f, -1.0f, 0.0f);// define os vertices do poligono
	glVertex3f (0.0f, -1.0f, 0.0f);
	glVertex3f (0.0f, 1.0f, 0.0f);
	glVertex3f (-1.0f, 1.0f, 0.0f);
	glEnd();						// termina a definicao do poligono
	
	glColor3f(1.0f, 0.0f, 0.0f); 	// RGB: 255, 0, 0 (vermelho)
	glBegin(GL_POLYGON);			// comeca a definicao do poligono
	glVertex3f (0.0f, -1.0f, 0.0f);	// define os vertices do poligono
	glVertex3f (1.0f, -1.0f, 0.0f);
	glVertex3f (1.0f, 1.0f, 0.0f);
	glVertex3f (0.0f, 1.0f, 0.0f);
	glEnd();						// termina a definicao do poligono

	glFlush();						// forca o desenho do poligono
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (-1, -1); 
	glutCreateWindow("Teste"); 
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
