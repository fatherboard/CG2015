/*
 * GameManager.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "GameManager.h"

extern GameManager *gameManager;

GameManager::GameManager() {
	_wireframe = 0;
}

GameManager::~GameManager() {
	// TODO Auto-generated destructor stub
}


std::list<Camera *> GameManager::getCameras(void){ 
	return _cameras; 
}

void GameManager::setCameras(Camera* camera){ 
	_cameras.push_back(camera); 
}

LightSource* GameManager::getLight_sources(void){
	return _light_sources;
}

void GameManager::setLight_sources(LightSource* light){
	_light_sources=light;
}

/*std::list<GameObject *> GameManager::getGame_objects(void) {
	return _gameObjects;
}*/
/*void GameManager::setGame_objects(GameObject* obj) {
	cout << "Entrou no setGame\n";
	_gameObjects.push_back(obj);
}*/

void GameManager::display(){
	_cameras.front()->computeVisualizationMatrix();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//draw Track
	Track *track = new Track();
	track->draw();

	//draw Butter
	Butter *b = new Butter();
	b->draw(_wireframe);

	//draw orange
	Orange *orange = new Orange();
	orange->draw(_wireframe);

	car->draw(_wireframe);
	
	glFlush();

}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	_cameras.front()->computeProjectionMatrix();
	_cameras.front()->update(w, h);
	
}

void GameManager::keyPressed(unsigned char key) {
	switch (key) {
		case GLUT_KEY_LEFT: 
			car->setSpeed(-2, car->getSpeed()->getY(),car->getSpeed()->getZ()); 
			break; //left key

		case GLUT_KEY_UP: 
			car->setSpeed(car->getSpeed()->getX(), 2, car->getSpeed()->getZ()); 
			break; //up key

		case GLUT_KEY_RIGHT: 
			car->setSpeed(2, car->getSpeed()->getY(), car->getSpeed()->getZ()); 
			break; //right key

		case GLUT_KEY_DOWN: 
			car->setSpeed(car->getSpeed()->getX(), -2, car->getSpeed()->getZ()); 
			break; //bottom key
	}
}
void GameManager::keyPressed_A(unsigned char key) {
	switch (key) {
	case 'a':
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glFlush();
		if (_wireframe)
			_wireframe = 0;
		else
			_wireframe = 1;
		break;
	}
}

void GameManager::onTimer(){
	gameManager->update(0);
}

void GameManager::idle(){

}

void GameManager::update(double tempo){
	car->update(tempo);
	glutPostRedisplay();
}

void GameManager::init(){
	setCameras(new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	car = new Car(-10, -0.8, 0);

}

