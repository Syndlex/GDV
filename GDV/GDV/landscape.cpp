#include "Landscape.h"
#include <ostream>
#include <iostream>


void Landscape::render()
{
	glPushMatrix();
	{
		glBegin(GL_LINES);
		{
			glColor4f(.0f, .0f, .0f, 1.0f); //Schwarz
			glVertex3f(0, 0, 0);
			glVertex3f(0, 5, 0);
		}
		glEnd();

		glTranslatef(0, -1.7, 0);

		glScalef(scl, 1, scl);
		for (int y = 0; y < MAXY; ++y)
		{
			glBegin(GL_LINE_STRIP);//Change to GL_TRIANGLE_STRIP
			{
				for (int x = 0; x < MAXX - 1; ++x)
				{
					glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
					glVertex3f(x - MAXX / 2, height[x][y], y - MAXY / 2);
					glVertex3f(x - MAXX / 2, height[x][y + 1], y + 1 - MAXY / 2);
				}
			}
			glEnd();
		}
	}
	glPopMatrix();
}


void Landscape::animate()
{
	auto perlin_noise = PerlinNoise();
	if (animator > 7)
	{
		for (int x = 0; x < MAXX; ++x)
		{
			for (int y = 0; y < MAXY; ++y)
			{
				height[x][y] = perlin_noise.noise(-x+perli, y-perli, 0.2);
				//std::cout << height[x][y] << std::endl;
			}
		}
		animator = 0;
		perli += 1;
	}
	else
	{
		animator++;
	}
}

Landscape::Landscape()
{
}


Landscape::~Landscape()
{
}
