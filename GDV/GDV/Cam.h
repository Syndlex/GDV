#pragma once
#include <GL/gl.h>

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
	void Move();
	void SpecialKeyUpHandler(int key);
	void KeyUpHandler(unsigned char key);
	void SpecialKeyHandler(int key);
	void KeyHandler(unsigned char key);
	
	KeyStruct& get_key_struct();
private:
	KeyStruct key_struct;

};
