#pragma once
#include "Wuerfel.h"

class Plane
{
public:
	void wings();
	void connectionRots();
	void mainTorso();
	void rotor();
	void Animate();
	void Render();
	Plane();
	~Plane();
private:
	GLfloat rotorAngle = 0;
	GLfloat tilt = 0;
	bool tiltUp = true;

	GLfloat planeHight = 0;
	bool hightUp = true;

	GLfloat planex = 0;
	bool forward = true;
};

