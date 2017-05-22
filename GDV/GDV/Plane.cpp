#include "Plane.h"


void Plane::wings()
{
	glColor3f(.56f, .38f, .08f);
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
	glColor3f(.9f, .3f, .07f);
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
	glColor3f(.78f,.64f,.12f);
	glPushMatrix();
	{
		glRotatef(90., 0., 1., 0.);
		glTranslatef(0, -.01, -0.15);
		glutSolidCylinder(.1, .2 * 4., 20, 20);
	}
	glPopMatrix();
	//Backwing
	glColor3f(.9f, .3f, .07f);
	glPushMatrix();
	{
		glTranslatef(0.5999, 0., 0.);
		glScalef(.5, 0.25, 2.);
		Wuerfel(0.2);
	}
	glPopMatrix();
	//Fin
	glPushMatrix();
	{
		glTranslatef(0.1 * 6, .16, 0);
		glBegin(GL_TRIANGLE_STRIP);
		{
			GLfloat length = .05f;
			GLfloat height = .08f;
			GLfloat width = .03f;
			//(In plane view direction)
			// Rightside
			glVertex3f(length, -height, width);
			glVertex3f(-length, -height, .0f);
			glNormal3f(2.0*height*width, -2.0 * length * width, 0.);
			glVertex3f(length, height, .0f);
			
			//leftside
			glNormal3f(-2.0*height*width, -2.0 * length * width, 0.);
			glVertex3f(length, -height, -width);
			//back
			glNormal3f(1., 0., 0.);
			glVertex3f(length, -height, width);
		}
		glEnd();
	}
	glPopMatrix();	
}

void Plane::rotor()
{
	glColor3f(.9f, .3f, .07f);
	glPushMatrix();
	{
		glRotatef(-90., 0., 1., 0.);
		glTranslatef(0, -.01, 0.15);
		glutSolidCone(0.1, 0.07, 20, 20);
	}
	glPopMatrix();
	glPushMatrix();
	//Rotor
	glColor3f(.3f, .3f, .3f);
	{
		glRotatef(rotorAngle, 1, 0, 0);
		glTranslatef(-.2, -.01, 0);
		glPushMatrix();
		{
			glScalef(.15, 0.7, .2);
			glTranslatef(.0, .1, 0);
			Wuerfel(.2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glRotatef(120, 1, 0, 0);
			glScalef(.15, 0.7, .2);
			glTranslatef(.0, .1, 0);
			Wuerfel(.2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glRotatef(-120, 1, 0, 0);
			glScalef(.15, 0.7, .2);
			glTranslatef(.0, .1, 0);
			Wuerfel(.2);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Plane::Animate()
{
	//Animate Rotor
	rotorAngle = rotorAngle + 5.0; // Rotationswinkel aendern
	if (rotorAngle <= 0.0)
	{
		rotorAngle = rotorAngle + 360.0;
	}

	//Animate Tilt Body
	if (tilt < -.8)tiltUp = true;
	if (tilt > .8)tiltUp = false;
	//TODO MaybePut a Break here
	if (tiltUp && !hightUp && tilt <= 4)
	{
		tilt = tilt + 0.01;
	}
	else if (hightUp && tilt >= -4)
	{
		tilt = tilt - 0.01;
	}

	//Animate Hight
	if (planeHight < -0.1)hightUp = true;
	if (planeHight > 0.1)hightUp = false;
	//TODO MaybePut a Break here
	if (hightUp && tiltUp)
	{
		planeHight = planeHight + 0.0005;
	}
	else if (!tiltUp)
	{
		planeHight = planeHight - 0.0005;
	}

	//Animate forward movement
	if (planex < -0.1)forward = true;
	if (planex > 0.1)forward = false;
	//TODO MaybePut a Break here
	if (forward)
	{
		planex = planex + 0.00009;
	}
	else
	{
		planex = planex - 0.00009;
	}
}


void Plane::Render()
{

	glPushMatrix();
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

	glScalef( .7, .7,.7);
	glRotatef(tilt, 0, 0, 1);
	glRotatef(180-45, 0, 1, 0);
	glTranslatef(planex, planeHight, 0);
	glTranslatef(0, .25, 0);

	//WINGS
	wings();

	//CONNECTION ROTS
	connectionRots();

	//MAIN TORSO
	mainTorso();

	//TIP
	rotor();
	glPopMatrix();
}

Plane::Plane()
{

}

Plane::~Plane()
{
}
