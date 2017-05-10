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
	GLfloat rotorAngle;
};

