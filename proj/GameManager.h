#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Camera.h"
#include "LightSource.h"
#include "GameObject.h"

class GameManager {

	std::list<Camera *> _cameras;
	LightSource* _light_sources;
	std::list<GameObject *> _game_objects;

	public:
		GameManager();
		~GameManager();
		
		std::list<Camera *> getCameras(void);
		std::list<Camera *> setCameras(Camera* camera);
		
		LightSource* getLight_sources(void);
		LightSource* setLight_sources(LightSource*);
		
		std::list<GameObject *> getGame_objects(void);
		void setGame_objects(GameObject* obj);
		
		
		void display();
		void reshape(GLsizei w, GLsizei h);
		void keyPressed();
		void onTimer();
		void idle();
		void update();
		void init();
};

#endif