#include "GameManager.h"
#include "Candle.h"

extern GameManager* gameManager;
extern int _wireframe;

Candle::Candle(Vector3* pos){
	setPosition(pos->getX(), pos->getY(), pos->getZ());
	setSize(0.5, 0.5, 10);

	int dirX, dirY;

	LightSource *aux = new LightSource(gameManager->getLightSources().size());
    aux->setPosition(pos->getX(), pos->getY(), pos->getZ() + 10, 1);

    if(pos->getX() > 0){
        dirX = -1;
    }else if(pos->getX() < 0){
        dirX = 1;
    }else{
        dirX = 0;
    }

    if(pos->getY() > 0){
        dirY = -1;
    }else if(pos->getY() < 0){
        dirY = 1;
    }else{
        dirY = 0;
    }

    aux->setDirection(dirX, dirY, -2);
    aux->setSpecular(1, 1, 1, 1.0);
    aux->setDiffuse(1, 1, 1, 1.0);
    aux->setAmbient(0.2, 0.2, 0.2, 1.0);
    aux->setCutOff(60);
    aux->setExponent(3);
    aux->setState(gameManager->getLightsOn());
    gameManager->addLightSource(aux);
}

Candle::~Candle(){
    delete this;
}

void Candle::draw(){
	glPushMatrix();
    glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

    if (getPosition()->getX() < 0) glRotatef(180, 0, 0, 1);

    glPushMatrix();
    glColor3f(0.99, 0.83, 0.44);
    glTranslatef(0, 0, 2*getSize()->getZ()/2);
    glScalef(1,1,5);

    if(gameManager->getLightsOn()){
        defineMaterial(	0.99, 0.83, 0.44, 1.00,
                        0.90, 0.00, 0.00, 1.00,
                        1.00, 1.00, 1.00, 1.00,
                        0,0,0,1,
                        128);
    }else if(gameManager->getModoDia()){
    }else{
        defineMaterial(	0,0,0,1,
                        0,0,0,1,
                        0,0,0,1,
                        0,0,0,1,
                        0);
    }

    if(_wireframe)
        glutWireSphere(1, 8, 8);
    else
        glutSolidSphere(1, 8, 8);

    glPopMatrix();
	glPopMatrix();
}
