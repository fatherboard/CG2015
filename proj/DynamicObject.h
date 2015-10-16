#pragma once
#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__

#include "GameObject.h"
#include "Vector3.h"
#include <math.h>

class DynamicObject: public GameObject {

	Vector3 _speed;
	Vector3 _direcao;
	double _radian;
	
public:
	DynamicObject();
	~DynamicObject();

	void update(double delta_t);
	void setSpeed(Vector3* speed);
	void setSpeed(double x, double y, double z);
	Vector3* getSpeed();
	void setDirecao(Vector3* speed);
	void setDirecao(double x, double y, double z);
	Vector3* getDirecao();
	void setRadian(double radian);
	double getRadian();
	// nao esquecer que a nova posicao de um objecto em movimento
	// e dada por: posicao_1 = posicao_0 + velocidade * delta_t
};

#endif
