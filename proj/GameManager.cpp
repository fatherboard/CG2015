/*
 * GameManager.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */
#include <list>
#include "GameManager.h"

GameManager::GameManager() {
	// TODO Auto-generated constructor stub

}

GameManager::~GameManager() {
	// TODO Auto-generated destructor stub
}


std::list<Camera *> GameManager::getCameras(void){ 
	return _cameras; 
}

std::list<Camera *> GameManager::setCameras(Camera* camera){ 
	_cameras.push_back(camera); 
	return _cameras; 
}

LightSource* GameManager::getLight_sources(void){
	return _light_sources;
}

LightSource* GameManager::setLight_sources(LightSource* light){
	_light_sources=light;
	return _light_sources;
}

void GameManager::display(){

}
void GameManager::reshape(GLsizei w, GLsizei h){

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

}

