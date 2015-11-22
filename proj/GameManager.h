#pragma once
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Camera.h"
#include "Vector3.h"
#include "LightSource.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Texture.h"
#include "Track.h"
#include "Car.h"
#include "Orange.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "Butter.h"
#include "Candle.h"
#include <vector>
#include <map>
#include <list>
#include <iostream>

class GameManager {

	Car *car = NULL;
	std::vector<Camera *> _cameras;
	Camera *camera_atual;
	std::list<GameObject *> _dynamic_game_objects;
	std::list<GameObject *> _static_game_objects;
	std::vector<LightSource *> _light_sources;


	int _tempo_atual;
	int _tempo_anterior;
	int _w, _h;
	unsigned long _delta_t;
	bool keystates[4];
	int camera_atual_id = 1;
	bool paused = false;

	GLuint TexturePause;
	GLuint TextureGameOver;

	Vector3* pos_init;

	public:
		GameManager();
		~GameManager();

        void setCandles(bool state);
		std::vector<Camera *> getCameras(void);
		std::vector<Camera *> setCameras(Camera*aux);

		std::vector<LightSource *> getLightSources(void);
		void setLightSources(std::vector<LightSource *> lights);
		LightSource* getLight(int i);
		void addLightSource(LightSource* light);

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
		Vector3* randomPosition();

		bool getModoDia();
		void setModoDia(bool modo);
		bool getLightsOn();
		void setLightsOn(bool modo);
		bool getLightsActive();
		void setLightsActive(bool modo);
		bool getPause(){return paused;};

		bool getSmooth();
		void setSmooth(bool smooth);
		void drawInfo();
		void drawLifes();
		GLuint getTexturePause(){ return TexturePause; }
		GLuint getTextureGameOver(){ return TextureGameOver; }
		Car* getCar();

		int getLifes();
		void setLifes(int lifes);
		void decreaseLifes();
		bool isDead();

    private:
		GameObject* checkCollisions();
		bool isOutOfTable(GameObject* obj);
		void initializeGame();

		bool _modo_dia = false;
		bool _lights_on = false;
		bool _lights_active = false;

		bool _smooth = false;

		int lifes = 5;

		void finalize();
};

#endif
