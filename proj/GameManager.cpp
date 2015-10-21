/*
 * GameManager.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "GameManager.h"
#include "stdafx.h"

extern GameManager *gameManager;

GameManager::GameManager() {
	car = 0;
	_wireframe = 0;
//	_tempo_anterior = glutGet(GLUT_ELAPSED_TIME);
//	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
}

GameManager::~GameManager() {
	// TODO Auto-generated destructor stub
}

std::list<Camera *> GameManager::getCameras(void) {
	return _cameras;
}

std::list<Camera *> GameManager::setCameras(Camera* aux) {
	_cameras.push_front(aux); 
	return _cameras; 
}

LightSource* GameManager::getLight_sources(void) {
	return _light_sources;
}

void GameManager::setLight_sources(LightSource* light) {
	_light_sources = light;
}

std::list<GameObject *> GameManager::getDynamicObjects(void) {
	return _dynamic_game_objects;
}

void GameManager::setDynamicObject(GameObject* aux) {
	_dynamic_game_objects.push_back(aux);
}
std::list<GameObject *> GameManager::getStaticObjects(void) {
	return _static_game_objects;
}
void GameManager::setStaticObject(GameObject* aux) {
	_static_game_objects.push_back(aux);
}

void GameManager::display() {

	//camera_atual->computeProjectionMatrix();
	//camera_atual->update(_w, _h);
	//camera_atual->computeVisualizationMatrix();
	GameObject *aux;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < _static_game_objects.size(); i++) {
		_static_game_objects.front()->draw();
		_static_game_objects.push_back(_static_game_objects.front());
		_static_game_objects.pop_front();
	}

	for (int i = 0; i < _dynamic_game_objects.size(); i++) {
		_dynamic_game_objects.front()->draw();
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	glFlush();
	////draw Track
	/*Track *track = new Track();
	track->draw();*/

	////draw Butters
	//Butter *butters[5];

	//butters[0] = new Butter(Vector3(10.0f, 36.0f, 0.0f), 2.0f, 3.0f);
	//butters[1] = new Butter(Vector3(-9.0f, 16.0f, 0.0f), 2.0f, 3.0f);
	//butters[2] = new Butter(Vector3(-15.0f, -8.0f, 0.0f), 2.0f, 3.0f);
	//butters[3] = new Butter(Vector3(20.0f, -17.0f, 0.0f), 2.0f, 3.0f);
	//butters[4] = new Butter(Vector3(-28.0f, -32.0f, 0.0f), 2.0f, 3.0f);

	//for (int i = 0; i < 5; i++) {
	//	butters[i]->draw(_wireframe);
	//}

	////draw oranges
	//Orange *oranges[3];

	//oranges[0] = new Orange(Vector3(-39, 34, 0), 1);
	//oranges[1] = new Orange(Vector3(39, 34, 0), 1);
	//oranges[2] = new Orange(Vector3(-39, -34, 0), 1);

	//for (int i = 0; i < 3; i++) {
	//	oranges[i]->draw(_wireframe);
	//}

	//car->draw(_wireframe);

	

}
void GameManager::reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	getCameras().front()->computeProjectionMatrix();
	getCameras().front()->computeVisualizationMatrix();
	getCameras().front()->update(w, h);
	_w = w;
	_h = h;
}

void GameManager::specialKeyPressed(unsigned char key) {

	double newSpeedX, newSpeedY, newSpeedZ;
	Vector3 *speed;

	switch (key) {
	case GLUT_KEY_LEFT:
		car->setRadian(car->getRadian() + ROTATION_SPEED * _delta_t);
		if (car->getRadian() > M_PI) {
			car->setRadian(-M_PI);
		} else if (car->getRadian() < -M_PI) {
			car->setRadian(M_PI);
		}
		car->setDirecao(car->getRadian(), car->getRadian(), 0);
		break; //left key

	case GLUT_KEY_UP:
		*speed = car->getSpeed();
		newSpeedX = speed->getX() + ACCELERATION_FORWARD * car->getDirecao()->getX() * _delta_t;
		newSpeedY = speed->getY() + ACCELERATION_FORWARD * car->getDirecao()->getY() * _delta_t;
		newSpeedZ = speed->getZ();

		car->setSpeed(newSpeedX, newSpeedY, newSpeedZ);
		break; //up key

	case GLUT_KEY_RIGHT:
		car->setRadian(car->getRadian() - ROTATION_SPEED * _delta_t);
		if (car->getRadian() > M_PI) {
			car->setRadian(-M_PI);
		} else if (car->getRadian() < -M_PI) {
			car->setRadian(M_PI);
		}
		car->setDirecao(car->getRadian(), car->getRadian(), 0);
		break; //right key

	case GLUT_KEY_DOWN:
		car->setSpeed(
				car->getSpeed()->getX()
						- ACCELERATION_BACKWARD * car->getDirecao()->getX()
								* _delta_t,
				car->getSpeed()->getY()
						- ACCELERATION_BACKWARD * car->getDirecao()->getY()
								* _delta_t, car->getSpeed()->getZ());
		break; //bottom key
	}
}

void GameManager::specialKeyUP(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:
		car->setRadian(car->getRadian());
		break; //left key

	case GLUT_KEY_UP:
		car->setSpeed(0,0,car->getSpeed()->getZ());
		break; //up key

	case GLUT_KEY_RIGHT:
		car->setRadian(car->getRadian());
		break; //right key

	case GLUT_KEY_DOWN:
		car->setSpeed(0, 0, 0);
		break; //bottom key
	}
	onTimer();
}

void GameManager::keyPressed(unsigned char key) {
	switch (key) {
	case 'a':
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (_wireframe)
			_wireframe = 0;
		else
			_wireframe = 1;
		break;
	//case '1':
	//	camera_atual = getCameras()[0];
	//	break;
	//case '2':
	//	camera_atual = getCameras()[1];
	//	break;
	//case '3':
	//	// definir camara 3rd person
	//	break;
	//case 'q':
	//	exit(0);
	//	break;
	}
	/*onTimer();*/
}

void GameManager::onTimer() {
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gameManager->update(_tempo_atual - _tempo_anterior);
	_tempo_anterior = _tempo_atual;
}

void GameManager::idle() {}

void GameManager::update(unsigned long delta_t) {
	_delta_t = delta_t;
	std::cout << "time= " << delta_t << "\n";
	for (int i = 0; i < _dynamic_game_objects.size(); i++) {
		_dynamic_game_objects.front()->update(delta_t);
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	glutPostRedisplay();
	//camera_atual->update(_w,_h);
}

void GameManager::init() {
	_cameras.push_front(new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	//setCameras(new PerspectiveCamera(90, 1, 1, 400));

	// falta por a camara 3rd person
	//camera_atual = getCameras()[0];

	setStaticObject(new Track());

	Vector3 *pos = new Vector3(-37.0f, -10.0f, 0.0f);
	setDynamicObject(car = new Car(pos)); 

	setStaticObject(new Butter(Vector3(10.0f, 36.0f, 0.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(-9.0f, 16.0f, 0.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(-15.0f, -8.0f, 0.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(20.0f, -17.0f, 0.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(-28.0f, -32.0f, 0.0f), 2.0f, 3.0f));

	setStaticObject(new Orange(Vector3(-39, 34, 0), 1));
	setStaticObject(new Orange(Vector3(39, 34, 0), 1));
	setStaticObject(new Orange(Vector3(-39, -34, 0), 1));

}

