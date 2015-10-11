/*
 * GameManager.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "GameManager.h"
#include "Butter.h"
extern GameManager *gamemanager;


GameManager::GameManager() {
	// TODO Auto-generated constructor stub

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

std::list<GameObject *> GameManager::getGame_objects(void) {
	return _gameObjects;
}
void GameManager::setGame_objects(GameObject* obj) {
	_gameObjects.push_back(obj);
}

void GameManager::display(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//draw Track
	Track *track = new Track();
	track->draw();
	Car *car = new Car(0, 0, 0, 5, 1);
	car->draw();

	Car *car2 = new Car(6, 0, 0, 2, 1);
	car2->draw();
	//_gameObjects.front()->draw();
	

	
	glFlush();

}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	_cameras.front()->computeProjectionMatrix();
	_cameras.front()->computeVisualizationMatrix();
	_cameras.front()->update(w, h);
}
void GameManager::keyPressed(){

}
void GameManager::onTimer(){

}
void GameManager::idle(){

}
void GameManager::update(){

}
void GameManager::init(){
	setCameras(new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	//setGame_objects(new Track());
}

