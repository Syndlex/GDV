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

	GLfloat scl = 0.25;
	int perli = 0;
	int animator = 20;
	static const int MAXY = 60;
	 static const int MAXX = 60;
	GLfloat height[MAXX][MAXY];
};
