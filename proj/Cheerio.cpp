/*
 * Cheerio.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: ist169537
 */

#include "Cheerio.h"

Cheerio::Cheerio(Vector3* position, double iR, double oR){
	setPosition(position);
	_inner_radius = iR;
	_outer_radius = oR;
}

Cheerio::Cheerio(Vector3* position, double iR, double oR, int s, int r) : Cheerio(position, iR, oR) {
	_sides = s;
	_rings = r;
}

Cheerio::~Cheerio() {
	// TODO Auto-generated destructor stub
}

void Cheerio::draw() {
	draw(0);
}

void Cheerio::draw(int wf) {
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	if (wf)
		glutWireTorus(0.25, 0.9, 50, 50);
	else
		glutSolidTorus(0.25, 0.9, 50, 50);
	glPopMatrix();
}
