#pragma once
#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
#include <cmath>

#define _USE_MATH_DEFINES
#define ACCELERATION_FORWARD 0.0001
#define ACCELERATION_BACKWARD 0.00006
#define ROTATION_SPEED 0.001

class Car : public DynamicObject {
public:

	Car(Vector3 *position);
	~Car();
	void draw();
	void carAcelera(unsigned long delta_t);
	void carTrava(unsigned long delta_t);
	void Esquerda(unsigned long delta_t);
	void Direita(unsigned long delta_t);
	void carDesacelera(unsigned long delta_t, bool sentido);

private:
	// Nomes:
	//		T -> face de cima (top)
	//		B -> face de baixo (bottom)
	//		L -> vertice da esquerda (visto pelo condutor)
	//		R -> vertice da direita (visto pelo condutor)
	//		F -> vertice da frente
	Vector3 *_TL, *_TR, *_TF, *_BL, *_BR, *_BF;

	// TBL -> top behing left
	// TBR -> top behind right
	// BBL -> bottom behind left
	// BBR -> bottom behing right
	Vector3 *_TBL, *_TBR, *_BBL, *_BBR;

	int wf;
	double _l, _h;
	//void update(unsigned long delta_t);
	float computeSqrt();
	void computeVertices();
	float getFrontVertexY(float x, float hypotenuse);
	void drawCube(int wf);

};

#endif
