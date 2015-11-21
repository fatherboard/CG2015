#include <vector>
#include "Car.h"
#include "GameManager.h"

//Vector3 _position;
extern int _wireframe;
extern GameManager* gameManager;

Car::Car(Vector3 *position) {
	setPosition(position);
	setSpeed(0, 0, 0);
	setDirecao(0, 0, 0);
	setRadian(0);
	_l = 3;
	light_on=false;
	setObjRadius(3);
	light = new LightSource(gameManager->getLightSources().size());
	light->setSpecular(1.0, 1.0, 1.0, 1.0);
	light->setDiffuse(1.0, 1.0, 1.0, 1.0);
	light->setAmbient(0.2, 0.2, 0.2, 1.0);
	light->setCutOff(90);
	light->setExponent(2);
	light->setState(light_on);
	computeVertices();
}

Car::~Car() {
	TL->~Vector3();
	TR->~Vector3();
	TF->~Vector3();
	BL->~Vector3();
	BR->~Vector3();
	BF->~Vector3();
}

void Car::drawCube(int _wireframe) {
	if (_wireframe)
		glutWireCube(1);
	else
		glutSolidCube(1);
}

void carVertex(Vector3* vec){
    glVertex3f(vec->getX(), vec->getY(), vec->getZ());
}

void carTriangle(Vector3* a, Vector3* b, Vector3* c, Vector3* normal){
    glBegin(GL_TRIANGLES);
    glNormal3f(normal->getX(), normal->getY(), normal->getZ());
    carVertex(a);
    carVertex(b);
    carVertex(c);
    glEnd();
}

void carRectangle(Vector3* a, Vector3* b, Vector3* c, Vector3* d, Vector3* normal){
    glBegin(GL_QUADS);
    glNormal3f(normal->getX(), normal->getY(), normal->getZ());
    carVertex(a);
    carVertex(b);
    carVertex(c);
    carVertex(d);
    glEnd();
}

void carRectangleOffset(Vector3* a, Vector3* b, Vector3* c, Vector3* d, Vector3* normal, Vector3* offset){
    glBegin(GL_QUADS);
    glNormal3f(normal->getX(), normal->getY(), normal->getZ());
    glVertex3f(a->getX()+offset->getX(), a->getY()+offset->getY(), a->getZ()+offset->getZ());
    glVertex3f(b->getX()+offset->getX(), b->getY()+offset->getY(), b->getZ()+offset->getZ());
    glVertex3f(c->getX()+offset->getX(), c->getY()+offset->getY(), c->getZ()+offset->getZ());
    glVertex3f(d->getX()+offset->getX(), d->getY()+offset->getY(), d->getZ()+offset->getZ());
    glEnd();
}

void Car::draw() {

    glPushMatrix();
	glTranslated(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());
	glRotatef(getRadian()*180/M_PI, 0, 0, 1);
	
	
	light->setPosition(getPosition()->getX()+2,
						getPosition()->getY(),
						getPosition()->getZ(), 1); 
	light->setDirection(getDirecao()->getX(), getDirecao()->getY(), -1); //Direcao do carro


    glColor3f(0.6, 0.6, 0.6);
    defineMaterial(	0.60, 0.60, 0.60, 1.00,
                    0.50, 0.50, 0.50, 1.00,
                    0,0,0, 1.00,
                    0,0,0,1,
                    128);

    // eixo frontal
    carRectangle(AF1, AF2, AF3, AF4, new Vector3(0,1,0));
    carRectangle(AF5, AF6, AF7, AF8, new Vector3(0,-1,0));
    carRectangle(AF1, AF2, AF6, AF5, new Vector3(0,0,1));
    carRectangle(AF1, AF4, AF5, AF8, new Vector3(-1,0,0));

    // eixo traseiro
    carRectangle(AB1, AB2, AB3, AB4, new Vector3(0,1,0));
    carRectangle(AB5, AB6, AB7, AB8, new Vector3(0,-1,0));
    carRectangle(AB1, AB2, AB6, AB5, new Vector3(0,0,1));
    carRectangle(AB1, AB4, AB5, AB8, new Vector3(-1,0,0));

    // rodas
    glColor3f(0, 0, 0);
    defineMaterial(	0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,128);

    carRectangle(FLW1, FLW2, FLW3, FLW4, new Vector3(0,-1,0));
    carRectangle(FRW1, FRW2, FRW3, FRW4, new Vector3(0,1,0));
    carRectangle(BLW1, BLW2, BLW3, BLW4, new Vector3(0,-1,0));
    carRectangle(BRW1, BRW2, BRW3, BRW4, new Vector3(0,1,0));

    carRectangleOffset(FLW1, FLW2, FLW3, FLW4, new Vector3(0,1,0), new Vector3(0,0.2,0));
    carRectangleOffset(FRW1, FRW2, FRW3, FRW4, new Vector3(0,-1,0), new Vector3(0,-0.2,0));
    carRectangleOffset(BLW1, BLW2, BLW3, BLW4, new Vector3(0,1,0), new Vector3(0,0.2,0));
    carRectangleOffset(BRW1, BRW2, BRW3, BRW4, new Vector3(0,-1,0), new Vector3(0,-0.2,0));

    carRectangle(FLW1, new Vector3(FLW1->getX(), FLW1->getY()+0.2, FLW1->getZ()),
                       new Vector3(FLW4->getX(), FLW4->getY()+0.2, FLW4->getZ()), FLW4, new Vector3(0,0,1));
    carRectangle(FRW1, new Vector3(FRW1->getX(), FRW1->getY()-0.2, FRW1->getZ()),
                       new Vector3(FRW4->getX(), FRW4->getY()-0.2, FRW4->getZ()), FRW4, new Vector3(0,0,1));
    carRectangle(BLW1, new Vector3(BLW1->getX(), BLW1->getY()+0.2, BLW1->getZ()),
                       new Vector3(BLW4->getX(), BLW4->getY()+0.2, BLW4->getZ()), BLW4, new Vector3(0,0,1));
    carRectangle(BRW1, new Vector3(BRW1->getX(), BRW1->getY()-0.2, BRW1->getZ()),
                       new Vector3(BRW4->getX(), BRW4->getY()-0.2, BRW4->getZ()), BRW4, new Vector3(0,0,1));

    carRectangle(FLW2, new Vector3(FLW2->getX(), FLW2->getY()+0.2, FLW2->getZ()),
                       new Vector3(FLW3->getX(), FLW3->getY()+0.2, FLW3->getZ()), FLW3, new Vector3(1,0,0));
    carRectangle(FRW2, new Vector3(FRW2->getX(), FRW2->getY()-0.2, FRW2->getZ()),
                       new Vector3(FRW3->getX(), FRW3->getY()-0.2, FRW3->getZ()), FRW3, new Vector3(1,0,0));
    carRectangle(BLW2, new Vector3(BLW2->getX(), BLW2->getY()+0.2, BLW2->getZ()),
                       new Vector3(BLW3->getX(), BLW3->getY()+0.2, BLW3->getZ()), BLW3, new Vector3(1,0,0));
    carRectangle(BRW2, new Vector3(BRW2->getX(), BRW2->getY()-0.2, BRW2->getZ()),
                       new Vector3(BRW3->getX(), BRW3->getY()-0.2, BRW3->getZ()), BRW3, new Vector3(1,0,0));

    // rectangulos
    glColor3f(1, 0, 0);
    defineMaterial(	1.00, 0.00, 0.00, 1.00,
                    0.90, 0.00, 0.00, 1.00,
                    1.00, 1.00, 1.00, 1.00,
                    0,0,0,1,
                    128);

    // topo da parte de tras do carro
	carRectangle(TL, TR, TBR, TBL, new Vector3(0,0,1));
	//carRectangle(BF,BR,BBR,BBL, new Vector3(0,0,-1));
	// traseira da parte de tras do carro
	carRectangle(TBR, BBR, BBL, TBL, new Vector3(-1,0,0));
	// lateral esquerda da parte de tras do carro
	//carRectangle(TL, TBL, BBL, BL, new Vector3(0,1,0));
	// lateral direita da parte de tras do carro
	//carRectangle(TR, BR, BBR, TBR, new Vector3(0,-1,0));

    // topo do capo do carro
    carTriangle(TL, TF, TR, new Vector3(0,0,1));
    //carTriangle(BL, BF, BR, new Vector3(0,0,-1));
    // lateral esquerda do capo do carro
    //carRectangle(TL, TF, BF, BL, new Vector3(1/sqrt(2), 1/sqrt(2), 0));
    // lateral direita do capo do carro
    //carRectangle(TR, TF, BF, BR, new Vector3(1/sqrt(2), -1/sqrt(2), 0));

    // tubos escape
    glColor3f(0, 0, 0);
    defineMaterial(	0,0,0,1,
                    0.5,0.5,0.5,1,
                    0,0,0,1,
                    0,0,0,1,
                    128);

    // tubo escape esquerdo
    carRectangle(EL1, EL2, EL3, EL4, new Vector3(0,0,1));
    carRectangle(EL1, EL2, EL6, EL5, new Vector3(0,1,0));
    carRectangle(EL4, EL3, EL7, EL8, new Vector3(0,0,1));
    carRectangle(EL2, EL3, EL7, EL6, new Vector3(-1,0,0));

    // tubo escape direito
    carRectangle(ER1, ER2, ER3, ER4, new Vector3(0,0,1));
    carRectangle(ER1, ER2, ER6, ER5, new Vector3(0,1,0));
    carRectangle(ER4, ER3, ER7, ER8, new Vector3(0,0,1));
    carRectangle(ER2, ER3, ER7, ER6, new Vector3(-1,0,0));

	glPopMatrix();
}

float Car::computeSqrt() {
	return sqrt(abs(pow(_l, 2) - pow(_l / 2, 2)));
}

void Car::computeVertices() {
	TL = new Vector3(-1.3, _l/2, 52);
	TR = new Vector3(-1.3, -_l/2, 52);
	TF = new Vector3(1.3, 0, 52);

	BL = new Vector3(-1.3, _l/2, 50);
	BR = new Vector3(-1.3, -_l/2, 50);
	BF = new Vector3(1.3, 0, 50);

	TBL = new Vector3(-2.8, _l/2, 52);
	TBR = new Vector3(-2.8, -_l/2, 52);

	BBL = new Vector3(-2.8, _l/2, 50);
	BBR = new Vector3(-2.8, -_l/2, 50);

    // coordenadas roda frente esquerda
	FLW1 = new Vector3(0.5, _l/2, 51);
	FLW2 = new Vector3(0.5, _l/2, 50);
	FLW3 = new Vector3(-0.5, _l/2, 50);
	FLW4 = new Vector3(-0.5, _l/2, 51);

    // coordenadas roda frente direita
	FRW1 = new Vector3(0.5, -_l/2, 51);
	FRW2 = new Vector3(0.5, -_l/2, 50);
	FRW3 = new Vector3(-0.5, -_l/2, 50);
	FRW4 = new Vector3(-0.5, -_l/2, 51);

    // coordenadas roda tras esquerda
	BLW1 = new Vector3(-1.3, _l*3/4, 51);
	BLW2 = new Vector3(-1.3, _l*3/4, 50);
	BLW3 = new Vector3(-2.3, _l*3/4, 50);
	BLW4 = new Vector3(-2.3, _l*3/4, 51);

    // coordenadas roda tras direita
	BRW1 = new Vector3(-1.3, -_l*3/4, 51);
	BRW2 = new Vector3(-1.3, -_l*3/4, 50);
	BRW3 = new Vector3(-2.3, -_l*3/4, 50);
	BRW4 = new Vector3(-2.3, -_l*3/4, 51);

    // coordenadas eixo frontal
	AF1 = new Vector3(0.25, _l/2, 50.75);
	AF2 = new Vector3(-0.25, _l/2, 50.75);
	AF3 = new Vector3(-0.25, _l/2, 50.25);
	AF4 = new Vector3(0.25, _l/2, 50.25);
	AF5 = new Vector3(0.25, -_l/2, 50.75);
	AF6 = new Vector3(-0.25, -_l/2, 50.75);
	AF7 = new Vector3(-0.25, -_l/2, 50.25);
	AF8 = new Vector3(0.25, -_l/2, 50.25);

    // coordenadas eixo traseiro
	AB1 = new Vector3(-1.55, _l*3/4, 50.75);
	AB2 = new Vector3(-2.05, _l*3/4, 50.75);
	AB3 = new Vector3(-2.05, _l*3/4, 50.25);
	AB4 = new Vector3(-1.55, _l*3/4, 50.25);
	AB5 = new Vector3(-1.55, -_l*3/4, 50.75);
	AB6 = new Vector3(-2.05, -_l*3/4, 50.75);
	AB7 = new Vector3(-2.05, -_l*3/4, 50.25);
	AB8 = new Vector3(-1.55, -_l*3/4, 50.25);

	// coordenadas tubo escape esquerda
	EL1 = new Vector3(-2.8, _l/10+0.5, 50.75);
	EL2 = new Vector3(-3.2, _l/10+0.5, 50.75);
	EL3 = new Vector3(-3.2, _l/5+0.5, 50.75);
	EL4 = new Vector3(-2.8, _l/5+0.5, 50.75);
	EL5 = new Vector3(-2.8, _l/10+0.5, 50.25);
	EL6 = new Vector3(-3.2, _l/10+0.5, 50.25);
	EL7 = new Vector3(-3.2, _l/5+0.5, 50.25);
	EL8 = new Vector3(-2.8, _l/5+0.5, 50.25);

	//coordenadas tubo escape direita
	ER1 = new Vector3(-2.8, -_l/10-0.5, 50.75);
	ER2 = new Vector3(-3.2, -_l/10-0.5, 50.75);
	ER3 = new Vector3(-3.2, -_l/5-0.5, 50.75);
	ER4 = new Vector3(-2.8, -_l/5-0.5, 50.75);
	ER5 = new Vector3(-2.8, -_l/10-0.5, 50.25);
	ER6 = new Vector3(-3.2, -_l/10-0.5, 50.25);
	ER7 = new Vector3(-3.2, -_l/5-0.5, 50.25);
	ER8 = new Vector3(-2.8, -_l/5-0.5, 50.25);
}

void Car::carAcelera(unsigned long delta_t) {
	if (getSpeed()->getX() >= 0.005 || getSpeed()->getY() >= 0.005) {
		setSpeed(getSpeed()->getX(), getSpeed()->getY(), getSpeed()->getZ());
	}
	else
		setSpeed(getSpeed()->getX() + ACCELERATION_FORWARD * getDirecao()->getX() * delta_t, getSpeed()->getY() + ACCELERATION_FORWARD * getDirecao()->getY() * delta_t, getSpeed()->getZ());
}

void Car::carTrava(unsigned long delta_t) {
	setSpeed(getSpeed()->getX() - ACCELERATION_BACKWARD * getDirecao()->getX() * delta_t, getSpeed()->getY() - ACCELERATION_BACKWARD * getDirecao()->getY() * delta_t, getSpeed()->getZ());
}

void Car::Esquerda(unsigned long delta_t) {
	setRadian(getRadian() + ROTATION_SPEED * delta_t);
	if (getRadian() > M_PI) {
		setRadian(-M_PI);
	}
	else if (getRadian() < -M_PI) {
		setRadian(M_PI);
	}
	setDirecao(getRadian(), getRadian(), 0);
}

void Car::Direita(unsigned long delta_t) {
	setRadian(getRadian() - ROTATION_SPEED * delta_t);
	if (getRadian() > M_PI) {
		setRadian(-M_PI);
	}
	else if (getRadian() < -M_PI) {
		setRadian(M_PI);
	}
	setDirecao(getRadian(), getRadian(), 0);
}

void Car::carDesacelera(unsigned long delta_t, bool sentido) {
	if (getSpeed()->getX() < 0.000005 || getSpeed()->getY() < 0.000005) {
		setSpeed(0,0,0);
	}
	else if(sentido)
		setSpeed(getSpeed()->getX() + ACCELERATION_FORWARD * getDirecao()->getX() * 1/delta_t, getSpeed()->getY() + ACCELERATION_FORWARD * getDirecao()->getY() * 1/delta_t, getSpeed()->getZ());
	else if(sentido==false)
		setSpeed(getSpeed()->getX() - ACCELERATION_BACKWARD * getDirecao()->getX() * 1/delta_t, getSpeed()->getY() - ACCELERATION_BACKWARD * getDirecao()->getY() * 1/delta_t, getSpeed()->getZ());
}
void Car::toggleLight(){
	light_on = !light_on;
	light->setState(light_on);
}
