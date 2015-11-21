#pragma once
#include <GL/glut.h>

class Texture{
public:
	Texture();
	~Texture();
	static GLuint load_textures(const char *imagepath);
};
