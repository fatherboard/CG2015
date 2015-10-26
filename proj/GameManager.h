#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Header.h"
#include <list>


class GameManager {

	Car *car;
	std::vector<Camera *> _cameras;
	Camera *camera_atual;
	LightSource* _light_sources;
	std::list<GameObject *> _dynamic_game_objects;
	std::list<GameObject *> _static_game_objects;


	int _tempo_atual;
	int _tempo_anterior;
	int _w, _h;
	unsigned long _delta_t;
	bool keystates[4];
	int camera_atual_id = 1;

	Vector3* pos_init;
	double rad_init;

	public:
		GameManager();
		~GameManager();


		std::vector<Camera *> getCameras(void);
		std::vector<Camera *> setCameras(Camera*aux);

		LightSource* getLight_sources(void);
		void setLight_sources(LightSource*);

		std::list<GameObject *> getDynamicObjects();
		void setDynamicObject(GameObject * aux);

		std::list<GameObject *> getStaticObjects();
		void setStaticObject(GameObject* aux);


		void display();
		void reshape(GLsizei w, GLsizei h);
		void specialKeyPressed(unsigned char key);
		void specialKeyUP(unsigned char key);
		void keyPressed(unsigned char key);
		void onTimer();
		void idle();
		void update(unsigned long tempo);
		void init();

    private:
		GameObject* checkCollisions();
		bool isOutOfTable(GameObject* obj);
};

#endif
