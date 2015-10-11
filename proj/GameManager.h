#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Header.h"
#include <list>

class GameManager {

	std::list<Camera*> _cameras;
	LightSource* _light_sources;
	//std::list<GameObject*> _gameObjects;

	public:
		GameManager();
		~GameManager();
		
		std::list<Camera*> getCameras(void);
		void setCameras(Camera *camera);
		
		LightSource* getLight_sources(void);
		void setLight_sources(LightSource*);
		
		//std::list<GameObject*> getGame_objects(void);
		//void setGame_objects(GameObject *obj);
		
		
		void display();
		void reshape(GLsizei w, GLsizei h);
		void keyPressed(unsigned char key);
		void onTimer();
		void idle();
		void update();
		void init();

	private:
		int _wireframe;
};

#endif
