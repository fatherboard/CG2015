/*
* GameManager.cpp
*
*  Created on: 30/09/2015
*      Author: 5702pedro.bucho
*/

#include "stdafx.h"
#include "GameManager.h"

extern GameManager *gameManager;
int _wireframe;
bool backwards = false;
Track *track;

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

	track->draw();

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
		backwards = true;
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
		backwards = false;
		break; //bottom key
	}
}

void GameManager::keyPressed(unsigned char key) {
	switch (key) {
	case 'a':
		glClearColor(0, 0, 0, 1);
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

    GameObject* collided = checkCollisions();
	if(collided != NULL){
        Orange* v = dynamic_cast<Orange*>(collided);
        if (v != 0) {
            // e uma laranja
            car->setPosition(pos_init);
        }else{
            Vector3* obj_pos = collided->getPosition();
            Vector3* car_dir = car->getDirecao();
            if(!collided->pushed){
                if(backwards){
                    collided->setPosition(obj_pos->getX()-car_dir->getX(), obj_pos->getY()-car_dir->getY(), obj_pos->getZ());
                }else{
                    collided->setPosition(obj_pos->getX()+car_dir->getX(), obj_pos->getY()+car_dir->getY(), obj_pos->getZ());
                }
                collided->pushed = true;
            }
            car->setPosition(posAnterior);
        }
	}
	glutPostRedisplay();
}

void GameManager::init() {
	setCameras(camera_atual = new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	setCameras(new PerspectiveCamera(90, 1, 1, 400));


    track = new Track();
	//setStaticObject(track);
	std::list<Cheerio *> cheerios = track->getCheerios();

	for(Cheerio* cheerio : cheerios){
        setStaticObject(cheerio);
	}

	pos_init = new Vector3(-30, 35, 0);
	car = new Car(pos_init);
	//setDynamicObject(car = new Car(pos));
	setCameras(new PerspectiveCamera(90, 1, 1, 400,car));

	setStaticObject(new Butter(Vector3(-33, 20, 50), 2, 3));  //((posicao), largura, altura
	setStaticObject(new Butter(Vector3(29, 20, 50), 2, 3));
	setStaticObject(new Butter(Vector3(-13, -8, 50), 2, 3));
	setStaticObject(new Butter(Vector3(35, -23, 50), 2, 3));
	setStaticObject(new Butter(Vector3(-20, -32, 50), 2, 3));

	setDynamicObject(new Orange(new Vector3(-39, 34, 50), 3));
	setDynamicObject(new Orange(new Vector3(35, 34, 50), 3));
	setDynamicObject(new Orange(new Vector3(-39, -34, 50), 3));

}

GameObject* GameManager::checkCollisions(){

    double car_radius = car->getObjRadius();
    bool collision = false;

    for (unsigned int i = 0; i < _static_game_objects.size(); i++) {
		GameObject* obj = _static_game_objects.front();
		double obj_radius = obj->getObjRadius();
		double distance = sqrt(pow(obj->getPosition()->getX()-car->getPosition()->getX(),2)+
                               pow(obj->getPosition()->getY()-car->getPosition()->getY(),2));
        if(pow(distance,2) <= pow(car_radius,2) + pow(obj_radius,2)){
            collision = true;
        }
		_static_game_objects.push_back(_static_game_objects.front());
		_static_game_objects.pop_front();
		if(collision){
            return obj;
        }
	}

	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
        GameObject* obj = _dynamic_game_objects.front();
		double obj_radius = obj->getObjRadius();

		if(isOutOfTable(obj)){
			obj->setPosition(randomPosition());
		}

		double distance = sqrt(pow(obj->getPosition()->getX()-car->getPosition()->getX(),2)+
                               pow(obj->getPosition()->getY()-car->getPosition()->getY(),2));
        if(pow(distance,2) <= pow(car_radius,2) + pow(obj_radius,2)){
            collision = true;
        }
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
		if(collision){
            return obj;
        }
	}

	return NULL;
}

bool GameManager::isOutOfTable(GameObject* obj){

    Vector3* pos = obj->getPosition();

    if(abs(pos->getX()) > track->track_lim_coord || abs(pos->getY()) > track->track_lim_coord)
        return true;

    return false;

}

Vector3* GameManager::randomPosition() {

	int x = rand() % track->track_lim_coord;
	int y = rand() % track->track_lim_coord;
	int z = 50;

	int sigX = (rand() % 2) == 0 ? -1 : 1;
	int sigY = (rand() % 2) == 0 ? -1 : 1;

	return new Vector3(x*sigX, y*sigY, z);

}
