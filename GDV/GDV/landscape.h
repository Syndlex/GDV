#pragma once
#include <GL/freeglut.h>
#include "PerlinNoise.h"


class Landscape
{
public:
	void setLandscapeColor(int y, int x);
	void render();
	void animate();
	Landscape();
	~Landscape();

private:
	GLdouble LIGHTRADIUS = 8;
	GLdouble SUNRADIUS = 10;
	int count = -2;
	//GLfloat x = 2;a
	//GLfloat y = 2;

	GLfloat scl = 0.35;
	int perli = 0;
	int animator = 20;
	static const int MAXY = 60;
	static const int MAXX = 60;
	GLfloat height[MAXX][MAXY];


	GLfloat light_position[4] = {.0,.0,.0,1.};
	GLfloat sun_position[3];
	float Omega = 90;
	float Phi = 30;

};
