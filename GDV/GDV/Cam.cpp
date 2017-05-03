#include "Cam.h"
#include <GL/freeglut_std.h>


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


void Cam::Move()
{
	//auto Speed = 0.1;

	//Camx += Speed * (this->key_struct.KEY_RIGHT * ((-1) * this->key_struct.KEY_LEFT));
	//Camy = 0;
	//gluLookAt(Camx, Camy, 2.5, 0., 0., 0., 0., 1., 0.);
	//
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
