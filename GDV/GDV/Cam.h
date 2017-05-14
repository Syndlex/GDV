#pragma once
#ifndef M_PI
#define M_PI    3.14159265358979323846f
#endif
#include <GL/freeglut.h>


const static GLdouble RADIUS = 3;

struct KeyStruct
{
	bool KEY_DOWN = false;
	bool KEY_LEFT = false;
	bool KEY_UP = false;
	bool KEY_RIGHT = false;
};

class Cam
{
public:
	Cam();
	~Cam();
	void move();
	void SpecialKeyUpHandler(int key);
	void KeyUpHandler(unsigned char key);
	void SpecialKeyHandler(int key);
	void KeyHandler(unsigned char key);

	KeyStruct& get_key_struct();
	void animate();
private:
	KeyStruct key_struct;
	float y = 0;
	float x = 0;
	float z = 0;
	float Omega = 90;
	float Phi = 30;
};
