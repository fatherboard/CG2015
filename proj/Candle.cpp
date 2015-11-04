#include "Header.h"

extern GameManager* gameManager;
extern int _wireframe;

Candle::Candle(Vector3* pos){
	setPosition(pos->getX(), pos->getY(), pos->getZ());
	setSize(0.5, 0.5, 10);

	LightSource *aux = new LightSource(gameManager->getLightSources().size());
    aux->setPosition(pos->getX(), pos->getY(), pos->getZ(), 1);
    aux->setDirection(1, 1, -1);
    aux->setSpecular(1.0, 1.0, 1.0, 1.0);
    aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
    aux->setAmbient(0.2, 0.2, 0.2, 1.0);
    aux->setCutOff(60);
    aux->setExponent(3);
    aux->setState(false);
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
    defineMaterial(	0.66, 0.66, 0.66, 1.00,	//Ambient
                    0.66, 0.66, 0.66, 1.00,	//Diffuse
                    1.00, 1.00, 1.00, 1.00,	//Specular
                    77);					//SHININESS
    glTranslatef(0, 0, 2*getSize()->getZ()/2);
    //glScalef(2*getSize()->getX(), 2*getSize()->getY(),2* getSize()->getZ());
    glScalef(1,1,5);
    //glutSolidCube(1);
    if(_wireframe)
        glutWireSphere(1, 8, 8);
    else
        glutSolidSphere(1, 8, 8);
    glPopMatrix();

    glPushMatrix(),
    /*glTranslatef(-2, 0, 2*getSize()->getZ()+0.5);
    glScalef(5, 1, 1);
    glutSolidCube(1);*/
    glPopMatrix();

    glPushMatrix();
    /*glTranslatef(-4,0,2*getSize()->getZ());
    glColor3f(1.0, 1.0,0.0);
    if (gameManager->getLightsOn()){
        defineMaterial(	1.00, 1.00, 0.00, 1.00,	//Ambient
                        1.00, 1.00, 0.00, 1.00,	//Diffuse
                        1.00, 1.00, 1.00, 1.00,	//Specular
                        1.00, 1.00, 0.00, 1.00,	//Emission
                        77);					//SHININESS
    }else{
        defineMaterial(	1.00, 1.00, 0.00, 1.00,	//Ambient
                        1.00, 1.00, 0.00, 1.00,	//Diffuse
                        1.00, 1.00, 1.00, 1.00,	//Specular
                        0.00, 0.00, 0.00, 1.00,	//Emission
                        77);					//SHININESS
    }
    //glutSolidSphere(0.5, 8, 8);*/
    glPopMatrix();
	glPopMatrix();
}
