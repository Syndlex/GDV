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
	//calc for Light
	// Sunset (Around Pi/2 with an offset of 0.5)
	if (Phi >= (M_PI/2-.5) && Phi < (M_PI / 2 + .5)) {
		float gradient = 1 - (Phi - (M_PI / 2 - .5));
		glClearColor(0.35*gradient, 0.35*gradient, .7*gradient, 0.);
		light_diffuse[0] = 1.;
		light_diffuse[1] = 1.*gradient;
		light_diffuse[2] = 1.*gradient;
		light_diffuse[3] = 1.*gradient;
	} else 
	// Dawn	(Around Pi * 3/2 with an offset of 0.5)
	if (Phi >= (M_PI * 1.5 - .5) && Phi < (M_PI * 1.5 + .5)) {
		float gradient = Phi - (M_PI * 1.5 - .5);
		glClearColor(0.35*gradient, 0.35*gradient, .7*gradient, 0.);
		light_diffuse[0] = 1.;
		light_diffuse[1] = 1.*gradient;
		light_diffuse[2] = 1.*gradient;
		light_diffuse[3] = 1.*gradient;
		glEnable(GL_LIGHT0);
	} else
	// Night
	if (Phi >= (M_PI/2+.5) && Phi <= M_PI*1.5-.5) {
		glClearColor(0., 0., 0., 0.);
		glDisable(GL_LIGHT0);
	} 
	// Day
	else {
		glClearColor(0.35, 0.35, .7, 0.);
		light_diffuse[0] = 1.;
		light_diffuse[1] = 1.;
		light_diffuse[2] = 1.;
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

	// Sun
	glPushMatrix();
	{
		//glTranslatef(10.f, 3.f, 0.f);
		glTranslatef(sun_position[0], sun_position[1], sun_position[2] );
		glRotatef(45., 1., 0., 0.);
		glColor3f(.7, .7, 0.);
		glutSolidSphere(.7, 10., 20.);
	}
	glPopMatrix();

	// Landscape
	glPushMatrix();
	{
		glTranslatef(0, -1.7, 0);
		glScalef(scl, 1, scl);
		
		for (int y = 0; y < MAXY; ++y)
		{
			glBegin(GL_TRIANGLE_STRIP);
			{
				for (int x = 0; x < MAXX - 1; ++x)
				{
					setLandscapeColor(y, x);
					glNormal3f(0., 1., 0.);
					glVertex3f(x - MAXX / 2, height[x][y], y - MAXY / 2);
					setLandscapeColor(y+1, x);
					// Esso es nessesito?
					glNormal3f(0., 1., 0.);
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
	Phi += 0.001f;
	if (Phi >= 2 * M_PI) Phi = 0;
	light_position[0] = LIGHTRADIUS * sin(Phi) * sin(Omega);
	light_position[1] = LIGHTRADIUS * cos(Phi);
	light_position[2] = LIGHTRADIUS * sin(Phi) * cos(Omega);

	sun_position[0] = SUNRADIUS * sin(Phi) * sin(Omega);
	sun_position[1] = SUNRADIUS * cos(Phi);
	sun_position[2] = SUNRADIUS * sin(Phi) * cos(Omega);

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
