#include "Track.h"
#include "GameManager.h"
#include "Cheerio.h"
#include "Texture.h"

int i;
extern GameManager* gameManager;

Track::Track(){
	wf = 0;
	for (i = 0; i < 80; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-45, i - 40, 50), 0.25, 0.9));
	}
	for (i = 0; i < 85; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-45 + i, 40, 50), 0.25, 0.9));
	}
	for (i = 0; i < 30; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(39, 40 - i, 50), 0.25, 0.9));
    }
	for (i = 0; i < 50; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-9 + i, 10, 50), 0.25, 0.9));
	}
	for (i = 0; i < 20; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-10, i - 9, 50), 0.25, 0.9));
    }
	for (i = 0; i < 50; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-9 + i, -10, 50), 0.25, 0.9));
    }
	for (i = 0; i < 30; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(39, -10 - i, 50), 0.25, 0.9));
	}
	for (i = 0; i < 85; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-45 + i, -40, 50), 0.25, 0.9));
    }
	for (i = 0; i < 56; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-30, i - 28, 50), 0.25, 0.9));
    }
	for (i = 0; i < 55; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-30 + i, 28, 50), 0.25, 0.9));
	}
	for (i = 0; i < 8; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(26, 28 - i, 50), 0.25, 0.9));
    }
	for (i = 0; i < 50; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-22 + i, 20, 50), 0.25, 0.9));
    }
	for (i = 0; i < 42; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-24, i - 20, 50), 0.25, 0.9));
    }
	for (i = 0; i < 50; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-22 + i, -20, 50), 0.25, 0.9));
	}
	for (i = 0; i < 8; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(26, -28 + i, 50), 0.25, 0.9));
	}
	for (i = 0; i < 55; i=i+4) {
		_cheerios.push_back(new Cheerio(new Vector3(-30 + i, -28, 50), 0.25, 0.9));
	}

        setTexture(Texture::load_textures("mesa23.bmp"));

}

Track::~Track() {

}

std::list<Cheerio *> Track::getCheerios(){
    return _cheerios;
}

void Track::draw(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, getTexture());

    if(gameManager->getLightsOn() || gameManager->getModoDia() || gameManager->getCar()->getLightState()){
        defineMaterial(	0.56, 0.76, 0.83, 1.00,
                        0.00, 0.30, 0.36, 1.00,
                        0.56, 0.76, 0.83, 1.00,
                        0,0,0,1,
                        90);


    }else{
        defineMaterial(	0,0,0,0,
                        0,0,0,0,
                        0,0,0,0,
                        0,0,0,0,
                        0);
    }
    int quad = 2;
	glColor3f(0.56, 0.76, 0.83);
	for(float y = -50; y<50; y+=quad){
		for(float x = -50; x<50; x+=quad){

			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);

			glTexCoord2f(0,0);
			glVertex3f(x, y, 50);

			glTexCoord2f(1,0);
			glVertex3f(x+quad, y, 50);

			glTexCoord2f(1,1);
			glVertex3f(x+quad, y+quad, 50);

			glTexCoord2f(0,1);
			glVertex3f(x, y+quad, 50);
			glEnd();

		}
	}
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
