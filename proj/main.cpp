#include "Header.h"

GameManager *gamemanager;
void myDisplay(void){ 
	gamemanager->display();
}
void myReshape(int w, int h){ 
	gamemanager->reshape(w, h);
}

int main(int argc, char ** argv) {
	gamemanager = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (600,600);
	glutInitWindowPosition (-1, -1); 
	glutCreateWindow("Micromachines"); 
	gamemanager->init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
