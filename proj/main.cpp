#include "Header.h"

GameManager *gameManager;
void myDisplay(void){ 
	gameManager->display();
}
void myReshape(int w, int h){ 
	gameManager->reshape(w, h);
}

void keyboardFunc(unsigned char key, int x, int y){
	gameManager->keyPressed(key);
}

int main(int argc, char ** argv) {
	gameManager = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (600,600);
	glutInitWindowPosition (-1, -1); 
	glutCreateWindow("Micromachines"); 
	gameManager->init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(keyboardFunc);
	glutMainLoop();
}
