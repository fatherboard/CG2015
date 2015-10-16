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
	_tempo_anterior = glutGet(GLUT_ELAPSED_TIME);
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//draw Track
	Track *track = new Track();
	track->draw();

	//draw Butters
	Butter *butters[5];

	butters[0] = new Butter(Vector3(10.0f, 36.0f, 0.0f), 2.0f, 3.0f);
	butters[1] = new Butter(Vector3(-9.0f, 16.0f, 0.0f), 2.0f, 3.0f);
	butters[2] = new Butter(Vector3(-15.0f, -8.0f, 0.0f), 2.0f, 3.0f);
	butters[3] = new Butter(Vector3(20.0f, -17.0f, 0.0f), 2.0f, 3.0f);
	butters[4] = new Butter(Vector3(-28.0f, -32.0f, 0.0f), 2.0f, 3.0f);

	for(int i = 0; i < 5; i++){
		butters[i]->draw(_wireframe);
	}

	//draw oranges
	Orange *oranges[3];

	oranges[0] = new Orange(Vector3(-39, 34, 0), 1);
	oranges[1] = new Orange(Vector3(39, 34, 0), 1);
	oranges[2] = new Orange(Vector3(-39, -34, 0), 1);

	for(int i = 0; i < 3; i++)
		oranges[i]->draw(_wireframe);

	car->draw(_wireframe);
	
	glFlush();

}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	_cameras.front()->computeProjectionMatrix();
	_cameras.front()->computeVisualizationMatrix();
	_cameras.front()->update(w, h);
	
}

void GameManager::keyPressed(unsigned char key) {
	switch (key) {
		case GLUT_KEY_LEFT:
			car->setRadian(car->getRadian() + ROTATION_SPEED*_delta_t);
			if (car->getRadian() > M_PI) {
				car->setRadian(-M_PI);
			}
			else if (car->getRadian() < -M_PI) {
				car->setRadian(M_PI);
			}
			car->setDirecao(car->getRadian(),car->getRadian(),0);
			break; //left key

		case GLUT_KEY_UP: 
			car->setSpeed(car->getSpeed()->getX()+ ACCELERATION_FORWARD*car->getDirecao()->getX()*_delta_t, car->getSpeed()->getY() + ACCELERATION_FORWARD*car->getDirecao()->getY()*_delta_t, car->getSpeed()->getZ());
			break; //up key

		case GLUT_KEY_RIGHT: 
			car->setRadian(car->getRadian()-ROTATION_SPEED*_delta_t);
			if (car->getRadian() > M_PI) {
				car->setRadian(-M_PI);
			}
			else if (car->getRadian() < -M_PI) {
				car->setRadian(M_PI);
			}
			car->setDirecao(car->getRadian(), car->getRadian(), 0);
			break; //right key

		case GLUT_KEY_DOWN: 
			car->setSpeed(car->getSpeed()->getX() - ACCELERATION_BACKWARD*car->getDirecao()->getX()*_delta_t, car->getSpeed()->getY() - ACCELERATION_BACKWARD*car->getDirecao()->getY()*_delta_t, car->getSpeed()->getZ());
			break; //bottom key
	}
}

void GameManager::keyUP(unsigned char key) {
	switch (key) {
		case GLUT_KEY_LEFT:
			car->setRadian(car->getRadian());
			break; //left key

		case GLUT_KEY_UP:
			car->setSpeed(car->getSpeed()->getX()*exp(-_delta_t), car->getSpeed()->getY()*exp(-_delta_t), car->getSpeed()->getZ());
			break; //up key

		case GLUT_KEY_RIGHT:
			car->setRadian(car->getRadian());
			break; //right key

		case GLUT_KEY_DOWN:
			car->setSpeed(car->getSpeed()->getX()*exp(-_delta_t), car->getSpeed()->getY()*exp(-_delta_t), car->getSpeed()->getZ());
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
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gameManager->update(_tempo_atual - _tempo_anterior);
	_tempo_anterior = _tempo_atual;
}

void GameManager::idle(){

}

void GameManager::update(double delta_t){
	_delta_t = delta_t;
	car->update(delta_t);
	glutPostRedisplay();
}

void GameManager::init(){
	setCameras(new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	car = new Car(0, 0, 0); //-10 -0.8 0

}

