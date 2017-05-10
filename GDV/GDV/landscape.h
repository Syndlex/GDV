#pragma once
#include <GL/freeglut.h>
#include "PerlinNoise.h"

class Landscape
{
public:
	void render();
	void animate();
	Landscape();
	~Landscape();
private:
	int count = -2;
	//GLfloat x = 2;
	//GLfloat y = 2;

	GLfloat scl = 0.1;
	static const int MAXY = 100;
	 static const int MAXX = 100;
	double height[MAXX][MAXY];
};
