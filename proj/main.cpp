#include "GameManager.h"
#include <cstdlib>
#include "GL/glut.h"
#include <ctime>

#define UPDATE_TIME 10

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
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize (800,600);
	glutInitWindowPosition (-1, -1);
	glutCreateWindow("Micromachines");
	//glEnable(GL_DEPTH_TEST);
	glHint(GL_NICEST,GL_POLYGON_SMOOTH_HINT);
	glEnable(GL_POLYGON_SMOOTH);
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
