#include "Landscape.h"
#include <ostream>
#include <iostream>


void Landscape::setLandscapeColor(int y, int x)
{
	float Red;
	float Green;
	float Blue;

	if (height[x][y] > .5f)
	{
		
		Red = .7f;
		Green = .7f;
		Blue = .7f;

	}
	else
	{
		Red = .62f;
		Green = .3f;
		Blue = .08f;
		Red = .55f;
		Green = .8f;
		Blue = .33f;
	}

	glColor3f(Red * height[x][y], Green * height[x][y], Blue * height[x][y]);
}

void Landscape::render()
{
	glPushMatrix();
	{
		glTranslatef(0, -1.7, 0);
		glScalef(scl, 1, scl);
		
		for (int y = 0; y < MAXY; ++y)
		{
			glBegin(GL_TRIANGLE_STRIP);//Change to GL_TRIANGLE_STRIP
			{
				for (int x = 0; x < MAXX - 1; ++x)
				{
					setLandscapeColor(y, x);
					glVertex3f(x - MAXX / 2, height[x][y], y - MAXY / 2);
					setLandscapeColor(y+1, x);
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
				height[x][y] = perlin_noise.noise(-x - perli, y + perli, 0.18);
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
