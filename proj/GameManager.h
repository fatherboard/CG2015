#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Header.h"
#include <list>
#define ACCELERATION_FORWARD 0.0005
#define ACCELERATION_BACKWARD 0.0002
#define ROTATION_SPEED 0.001

class GameManager {

	Car *car;
	std::list<Camera*> _cameras;
	LightSource* _light_sources;
	std::list<GameObject*> _gameObjects;
	int _wireframe;
	int _tempo_atual;
	int _tempo_anterior;
	double _delta_t;

	public:
		GameManager();
		~GameManager();
		
		std::list<Camera*> getCameras(void);
		void setCameras(Camera *camera);
		
		LightSource* getLight_sources(void);
		void setLight_sources(LightSource*);
		
		std::list<GameObject*> getGame_objects(void);
		void setGame_objects(GameObject *obj);
		
		
		void display();
		void reshape(GLsizei w, GLsizei h);
		void specialKeyPressed(unsigned char key);
		void specialKeyUP(unsigned char key);
		void keyPressed(unsigned char key);
		void onTimer();
		void idle();
		void update(double tempo);
		void init();
};

#endif
