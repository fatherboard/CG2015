/*
 * GameManager.cpp
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#include "GameManager.h"

using  namespace std;
extern GameManager *gamemanager;

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
	b->draw();
	//draw orange
	Orange *orange = new Orange();
	orange->draw();

	Car *car = new Car(0, 0, 0, 5, 1);
	car->draw(_wireframe);

	Car *car2 = new Car(6, 0, 0, 2, 1);
	car2->draw(_wireframe);
	//_gameObjects.front()->draw();

	glFlush();

}
void GameManager::reshape(GLsizei w, GLsizei h){
	glViewport(0, 0, w, h);
	_cameras.front()->computeProjectionMatrix();
	_cameras.front()->update(w, h);
	
}

void GameManager::keyPressed(unsigned char key){
	switch(key){
		case 'A':
		case 'a':
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glFlush();
			if(_wireframe)
				_wireframe = 0;
			else
				_wireframe = 1;
			display();
			break;
	}
}

void GameManager::onTimer(){

}

void GameManager::idle(){

}

void GameManager::update(){

}

void GameManager::init(){
	setCameras(new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
}

