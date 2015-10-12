#include "Header.h"
#include "GameManager.h"

GameManager *gameManager;

void myDisplay(void){ 
	gameManager->display();
}
void myReshape(int w, int h){ 
	gameManager->reshape(w, h);
}

void tecla_primida(int key, int x, int y) {
	gameManager->keyPressed(key); 
}
void tecla_levantada(int key, int x, int y) {
	gameManager->keyUP(key);
}
void tecla_primida_A(unsigned char key, int x, int y) {
	gameManager->keyPressed_A(key);
}

void update_game(int i) { 
	gameManager->onTimer(); 
	glutTimerFunc(UPDATE_TIME, update_game, UPDATE_TIME);
}

int main(int argc, char ** argv) {
	gameManager = new GameManager();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (600,600);
	glutInitWindowPosition (-1, -1); 
	glutCreateWindow("Micromachines");
	glutTimerFunc(UPDATE_TIME, update_game, 0);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutSpecialFunc(tecla_primida);
	glutSpecialUpFunc((tecla_levantada));
	glutKeyboardFunc(tecla_primida_A);
	gameManager->init();
	glutMainLoop();
}
