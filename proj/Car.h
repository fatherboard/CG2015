#pragma once
#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
#include "stdlib.h"
#include <cmath>

class Car : public DynamicObject {
public:

	Car(float x, float y, float z, float l, float h);
	~Car();
	void draw();

private:
	float _h;
	float _l;

	// Nomes:
	//		T -> face de cima (top)
	//		B -> face de baixo (bottom)
	//		L -> vertice da esquerda (visto pelo condutor)
	//		R -> vertice da direita (visto pelo condutor)
	//		F -> vertice da frente
	float *_vertTL, *_vertTR, *_vertTF, *_vertBL, *_vertBR, *_vertBF;

	float computeSqrt();
	void computeVertices(float x, float y, float z);
	float getFrontVertexY(float x, float hypotenuse);
};

#endif