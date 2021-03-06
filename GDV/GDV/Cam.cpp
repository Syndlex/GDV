﻿#include "Cam.h"
#include <cmath>


Cam::Cam()
{
}


Cam::~Cam()
{
}

KeyStruct& Cam::get_key_struct()
{
	return key_struct;
}


void Cam::animate()
{
	auto SpeedLR = 0.065;
	auto SpeedUD = 0.045;
	if (key_struct.KEY_UP || key_struct.KEY_DOWN)
	{
		auto speedx = SpeedUD * (this->key_struct.KEY_UP + ((-1) * this->key_struct.KEY_DOWN));

		Phi = Phi + speedx;
		if(Phi > 30.5)
		{
			Phi = 30.5;
		}
		if(Phi < 29.5){
			Phi = 29.5;
		}


	}
	if (key_struct.KEY_LEFT || key_struct.KEY_RIGHT)
	{
		auto speedy = SpeedLR * (this->key_struct.KEY_RIGHT + ((-1) * this->key_struct.KEY_LEFT));
		
		Omega = Omega + speedy;
	}


	x = RADIUS * sin(Phi) * sin(Omega);
	y = RADIUS * cos(Phi);
	z = RADIUS * sin(Phi) * cos(Omega);
}

void Cam::move()
{
	gluLookAt(x, y, z, 0., 0., 0., 0., 1., 0.);
}


void Cam::SpecialKeyUpHandler(int key)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		key_struct.KEY_DOWN = false;
		break;
	case GLUT_KEY_UP:
		key_struct.KEY_UP = false;
		break;
	case GLUT_KEY_RIGHT:
		key_struct.KEY_RIGHT = false;
		break;
	case GLUT_KEY_LEFT:
		key_struct.KEY_LEFT = false;
		break;
	default: break;
	}
}

void Cam::KeyUpHandler(unsigned char key)
{
	switch (key)
	{
	case 's':
		key_struct.KEY_DOWN = false;
		break;
	case 'w':
		key_struct.KEY_UP = false;
		break;
	case 'd':
		key_struct.KEY_RIGHT = false;
		break;
	case 'a':
		key_struct.KEY_LEFT = false;
		break;
	default: break;
	}
}

void Cam::SpecialKeyHandler(int key)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		key_struct.KEY_DOWN = true;
		break;
	case GLUT_KEY_UP:
		key_struct.KEY_UP = true;
		break;
	case GLUT_KEY_RIGHT:
		key_struct.KEY_RIGHT = true;
		break;
	case GLUT_KEY_LEFT:
		key_struct.KEY_LEFT = true;
		break;
	default: break;
	}
}

void Cam::KeyHandler(unsigned char key)
{
	switch (key)
	{
	case 's':
		key_struct.KEY_DOWN = true;
		break;
	case 'w':
		key_struct.KEY_UP = true;
		break;
	case 'd':
		key_struct.KEY_RIGHT = true;
		break;
	case 'a':
		key_struct.KEY_LEFT = true;
		break;
	default: break;
	}
}
