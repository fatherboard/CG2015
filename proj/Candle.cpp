#include "GameManager.h"
#include "Candle.h"

extern GameManager* gameManager;
extern int _wireframe;

Candle::Candle(Vector3* pos, Vector3* pos_luz){
	setPosition(pos->getX(), pos->getY(), pos->getZ());
	setSize(0.5, 0.5, 10);
	GLdouble dirX, dirY;

	LightSource *aux = new LightSource(gameManager->getLightSources().size());
    aux->setPosition(pos_luz->getX(), pos_luz->getY(), pos_luz->getZ(), 1);

    if(pos->getX() > 0){
        dirX = -0.5;
    }else if(pos->getX() < 0){
        dirX = 0.5;
    }else{
        dirX = 0;
    }

    if(pos->getY() > 0){
        dirY = -0.5;
    }else if(pos->getY() < 0){
        dirY = 0.5;
   }

    aux->setDirection(dirX, dirY, -1);
    aux->setSpecular(1, 1, 1, 1.0);
    aux->setDiffuse(1, 1, 1, 1.0);
    aux->setAmbient(0.2, 0.2, 0.2, 1.0);
    aux->setCutOff(60);
    aux->setExponent(5);
    aux->setState(gameManager->getLightsOn());
    gameManager->addLightSource(aux);
}

Candle::~Candle(){
    delete this;
}

void Candle::draw(){
	glPushMatrix();
    glTranslatef(getPosition()->getX(), getPosition()->getY(), getPosition()->getZ());

    //if (getPosition()->getX() < 0) glRotatef(180, 0, 0, 1);

    glPushMatrix();
    glColor3f(0.99, 0.83, 0.44);
    //glTranslatef(0, 0, 2*getSize()->getZ()/2);
    glScalef(1,1,5);

    if(gameManager->getLightsOn() || gameManager->getCar()->getLightState()){
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
        glutWireSphere(0.5, 8, 8);
    else
        glutSolidSphere(0.5, 8, 8);

    glPopMatrix();
	glPopMatrix();
}
