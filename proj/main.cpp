#define UPDATE_TIME 10

#include <GL/glut.h>
#include "GameManager.h"

GameManager *gameManager;

void myDisplay(void){
	gameManager->display();
}
void myReshape(int w, int h){
	gameManager->reshape(w, h);
}

void tecla_premida(int key, int x, int y) {
	gameManager->specialKeyPressed(key);
}
void tecla_levantada(int key, int x, int y) {
	gameManager->specialKeyUP(key);
}
void tecla_primida_A(unsigned char key, int x, int y) {
	gameManager->keyPressed(key);
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
	glutTimerFunc(UPDATE_TIME, update_game, UPDATE_TIME);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutSpecialUpFunc(tecla_levantada);
	glutSpecialFunc(tecla_premida);
	glutKeyboardFunc(tecla_primida_A);
	gameManager->init();
	glutMainLoop();
	return 0;
}
