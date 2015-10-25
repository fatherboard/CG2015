/*
* GameManager.cpp
*
*  Created on: 30/09/2015
*      Author: 5702pedro.bucho
*/

#include "GameManager.h"
#include "stdafx.h"

extern GameManager *gameManager;
int _wireframe;

GameManager::GameManager() {
	car = 0;
	_wireframe = 0;
	_tempo_anterior = glutGet(GLUT_ELAPSED_TIME);
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
}

GameManager::~GameManager() {
	for (GameObject *aux : getDynamicObjects()) delete(aux);
	for (GameObject *aux : getStaticObjects()) delete(aux);
	for (Camera *aux : getCameras()) delete(aux);
}

std::vector<Camera *> GameManager::getCameras(void) {
	return _cameras;
}

std::vector<Camera *> GameManager::setCameras(Camera* aux) {
	_cameras.push_back(aux);
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


	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	camera_atual->computeProjectionMatrix();
	camera_atual->update(_w, _h);
	camera_atual->computeVisualizationMatrix();

	for (unsigned int i = 0; i < _static_game_objects.size(); i++) {
		_static_game_objects.front()->draw();
		_static_game_objects.push_back(_static_game_objects.front());
		_static_game_objects.pop_front();
	}

	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
		_dynamic_game_objects.front()->draw();
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	car->draw();
	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	_w = w;
	_h = h;
}

void GameManager::specialKeyPressed(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:
		car->Esquerda(_delta_t);
		break; //left key

	case GLUT_KEY_UP:
		car->carAcelera(_delta_t);
		break; //up key

	case GLUT_KEY_RIGHT:
		car->Direita(_delta_t);
		break; //right key

	case GLUT_KEY_DOWN:
		car->carTrava(_delta_t);
		break; //bottom key
	}
}

void GameManager::specialKeyUP(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:
		car->setRadian(car->getRadian());
		break; //left key

	case GLUT_KEY_UP:
		car->setSpeed(0, 0, car->getSpeed()->getZ());
		break; //up key

	case GLUT_KEY_RIGHT:
		car->setRadian(car->getRadian());
		break; //right key

	case GLUT_KEY_DOWN:
		car->setSpeed(0, 0, 0);
		break; //bottom key
	}
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
		case '1':
			//orthogonal
			camera_atual_id = 0;
			camera_atual = getCameras()[0];
			break;
		case '2':
			//perspective
			camera_atual_id = 1;
			camera_atual = getCameras()[1];
			break;
		case '3':
			//3rd person
			camera_atual_id = 2;
			camera_atual = getCameras()[2];
			break;
		case 'q':
			exit(0);
			break;
	}
}

void GameManager::onTimer() {
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gameManager->update(_tempo_atual - _tempo_anterior);
	_tempo_anterior = _tempo_atual;
}

void GameManager::idle() {}

void GameManager::update(unsigned long delta_t) {
	_delta_t = delta_t;
	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
		_dynamic_game_objects.front()->update(delta_t);
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	if (camera_atual_id == 2) {
		camera_atual->setAt(car->getPosition()->getX(), car->getPosition()->getY(), car->getPosition()->getZ());
		camera_atual->setUp(0, 0, 1);
	}
	Vector3 *posAnterior = new Vector3(car->getPosition());
	car->update(delta_t);

	if(checkCollisions()){
        car->setPosition(posAnterior);
	}
	glutPostRedisplay();
}

void GameManager::init() {
	setCameras(camera_atual = new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	setCameras(new PerspectiveCamera(90, 1, 1, 400));


    Track *track = new Track();
    track->draw();
	//setStaticObject(track);
	std::list<Cheerio *> cheerios = track->getCheerios();

	for(Cheerio* cheerio : cheerios){
        setStaticObject(cheerio);
	}

	Vector3 *pos = new Vector3(-30.0f, 35.0f, 0.0f);
	car = new Car(pos);
	//setDynamicObject(car = new Car(pos));
	setCameras(new PerspectiveCamera(90, 1, 1, 400,car));

	setStaticObject(new Butter(Vector3(10.0f, 36.0f, 51.0f), 2.0f, 3.0f));  //((posicao), largura, altura
	setStaticObject(new Butter(Vector3(-9.0f, 16.0f, 51.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(-15.0f, -8.0f, 51.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(20.0f, -17.0f, 51.0f), 2.0f, 3.0f));
	setStaticObject(new Butter(Vector3(-28.0f, -32.0f, 51.0f), 2.0f, 3.0f));

	setStaticObject(new Orange(Vector3(-39, 34, 53), 1));
	setStaticObject(new Orange(Vector3(39, 34,53), 1));
	setStaticObject(new Orange(Vector3(-39, -34, 53), 1));

}

bool GameManager::checkCollisions(){

    double car_radius = car->getObjRadius();
    bool collision = false;

    for (unsigned int i = 0; i < _static_game_objects.size(); i++) {
		GameObject* obj = _static_game_objects.front();
		double obj_radius = obj->getObjRadius();
		double distance = sqrt(pow(obj->getPosition()->getX()-car->getPosition()->getX(),2)+
                               pow(obj->getPosition()->getY()-car->getPosition()->getY(),2));
        if(pow(distance,2) <= pow(car->getObjRadius(),2) + pow(obj->getObjRadius(),2)){
            std::cout << "Collision static";
            collision = true;
        }
		_static_game_objects.push_back(_static_game_objects.front());
		_static_game_objects.pop_front();
		if(collision)
            return true;
	}

	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
        GameObject* obj = _static_game_objects.front();

        double obj_radius = obj->getObjRadius();
		double distance = sqrt(pow(obj->getPosition()->getX()-car->getPosition()->getX(),2)+
                               pow(obj->getPosition()->getY()-car->getPosition()->getY(),2));
        if(pow(distance,2) <= pow(car->getObjRadius(),2) + pow(obj->getObjRadius(),2)){
            std::cout << "Collision dynamic";
            collision = true;
        }
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
		if(collision)
            return true;
	}

	return false;
}

