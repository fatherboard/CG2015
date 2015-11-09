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
	Vector3 *TL, *TR, *TF, *BL, *BR, *BF;

	// TBL -> top behing left
	// TBR -> top behind right
	// BBL -> bottom behind left
	// BBR -> bottom behing right
	Vector3 *TBL, *TBR, *BBL, *BBR;

	Vector3 *FLW1, *FLW2, *FLW3, *FLW4;
	Vector3 *FRW1, *FRW2, *FRW3, *FRW4;
	Vector3 *BLW1, *BLW2, *BLW3, *BLW4;
	Vector3 *BRW1, *BRW2, *BRW3, *BRW4;

	Vector3 *AF1, *AF2, *AF3, *AF4, *AF5, *AF6, *AF7, *AF8;
	Vector3 *AB1, *AB2, *AB3, *AB4, *AB5, *AB6, *AB7, *AB8;

	Vector3 *EL1, *EL2, *EL3, *EL4, *EL5, *EL6, *EL7, *EL8;
	Vector3 *ER1, *ER2, *ER3, *ER4, *ER5, *ER6, *ER7, *ER8;

	int wf;
	double _l, _h;
	//void update(unsigned long delta_t);
	float computeSqrt();
	void computeVertices();
	float getFrontVertexY(float x, float hypotenuse);
	void drawCube(int wf);

};

#endif
