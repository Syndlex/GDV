#include "Plane.h"


void Plane::wings()
{
	glPushMatrix();
	{
		glScalef(1., 0.25, 4.);
		Wuerfel(0.2);
		glTranslatef(0., 0.85, 0.);
		Wuerfel(0.2);
	}
	glPopMatrix();
}

void Plane::connectionRots()
{
	glPushMatrix();
	{
		glTranslatef(0., 0.1, 0);
		glScalef(.2, 1 - 0.85 * 0.05/* 0.9570*/, .2);
		glPushMatrix();
		{
			glPushMatrix();
			{
				glTranslatef(.4, 0., 1.9);
				Wuerfel(0.2);
				glTranslatef(0., 0., -2 * 1.9);
				Wuerfel(0.2);
			}
			glPopMatrix();
			glTranslatef(-.4, 0., 1.9);
			Wuerfel(0.2);
			glTranslatef(0., 0., -2 * 1.9);
			Wuerfel(0.2);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Plane::mainTorso()
{
	glPushMatrix();
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glRotatef(90., 0., 1., 0.);
		glTranslatef(0, -.01, -0.15);
		glutSolidCylinder(.1, .2 * 4., 20, 20);
	}
	glPopMatrix();
}

void Plane::rotor()
{
	glPushMatrix();
	{
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(0, -.01, 0.15);
		glutSolidCone(0.1, 0.07, 20, 20);
	}
	glPopMatrix();
	glPushMatrix();
	//Rotor
	{
		glRotatef(rotorAngle,1,0,0);
		glTranslatef(-.2, -.01, 0);
		glPushMatrix();
		{
			glScalef(.15, 0.7, .15);
			glTranslatef(.0, .1, 0);
			Wuerfel(.2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glRotatef(120, 1, 0, 0);
			glScalef(.15, 0.7, .15);
			glTranslatef(.0, .1, 0);
			Wuerfel(.2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glRotatef(-120, 1, 0, 0);
			glScalef(.15, 0.7, .15);
			glTranslatef(.0, .1, 0);
			Wuerfel(.2);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Plane::Animate()
{
	rotorAngle 
}

Plane::Plane()
{
	//WINGS
	wings();

	//CONNECTION ROTS
	connectionRots();

	//MAIN TORSO
	mainTorso();

	//TIP
	rotor();
}

Plane::~Plane()
{
}
