#include "Track.h"

int i;

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
}

Track::~Track() {
	// TODO Auto-generated destructor stub
}

std::list<Cheerio *> Track::getCheerios(){
    return _cheerios;
}

void Track::drawCheerio(){
	if (wf)
		glutWireTorus(0.25, 0.9, 50, 50);
	else
		glutSolidTorus(0.25, 0.9, 50, 50);
}

void Track::draw(){
	//glColor3f(0.75f,0.75f, 0.75f);
	glColor3f(1,1,1);
	glutSolidCube(100);
}
