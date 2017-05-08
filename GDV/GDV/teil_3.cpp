// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#pragma once

#include "Wuerfel.h"

#include <freeglut.h>         //l�dt alles f�r OpenGL
#include "Cam.h"

float fRotation = 315.0;

Cam cam;


void Init()
{
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgef�hrt werden m�ssen
}


void RenderScene() //Zeichenfunktion
{
	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss

	glLoadIdentity(); // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClearColor(0.7, 0.25, 0.1, 0.);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//glPopMatrix();
	cam.Move();
	glPushMatrix();
	{
		glScalef(1., 0.25, 4.);
		Wuerfel(0.2);
		glTranslatef(0., 0.85, 0.);
		Wuerfel(0.2);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0., 0.1, 0);
		glScalef(.2, 1 - 0.85 * 0.05/*0.9570*/, .2);
		glPushMatrix();
		{
			glTranslatef(.4125, 0., 0);
			Wuerfel(0.2);
		}
		glPopMatrix();
	}
	glPopMatrix();
	/*glPushMatrix();
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glRotatef(90., 0., 1., 0.);
		glTranslatef(0, -.025, -0.1);
		glutSolidCylinder(.1, .2 * 4., 20, 20);
	}
	glPopMatrix();*/

	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// Matrix f�r Transformation: Frustum->viewport
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);
	// Frustum definieren
	//glOrtho(-1., 1., -1., 1., 1., 2.0);
	gluPerspective(45., 1., 0.1, 5.0);
	// Matrix f�r Modellierung/Viewing
	glMatrixMode(GL_MODELVIEW);

	// Hier finden die Reaktionen auf eine Ver�nderung der Gr��e des 
	// Graphikfensters statt
}

void Animate(int value)
{
	// Hier werden Berechnungen durchgef�hrt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess l�uft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	//std::cout << "value=" << value << std::endl;


	// RenderScene aufrufen
	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}


void KeyHandler(unsigned char key, int x, int y)
{
	cam.KeyHandler(key);
}

void KeyUpHandler(unsigned char key, int x, int y)
{
	cam.KeyUpHandler(key);
}

void SpecialKeyHandler(int key, int x, int y)
{
	cam.SpecialKeyHandler(key);
}

void SpecialKeyUpHandler(int key, int x, int y)
{
	cam.SpecialKeyUpHandler(key);
}


int main(int argc, char** argv)
{
	cam = Cam();

	glutInit(&argc, argv); // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800); // Fenster-Konfiguration
	glutCreateWindow("Lukas Assmann; Marcel Feix"); // Fenster-Erzeugung


	glutDisplayFunc(RenderScene); // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);

	//Register Key Funktion Handler
	glutKeyboardFunc(KeyHandler);
	glutKeyboardUpFunc(KeyUpHandler);
	glutSpecialFunc(SpecialKeyHandler);
	glutSpecialUpFunc(SpecialKeyUpHandler);

	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);
	Init();
	glutMainLoop();
	return 0;
}

//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
//glutWireCube(0.2);
//glTranslatef(.1, .1, .0);
//glRotatef(fRotation, 0., 0., 1.);

//glPushMatrix();
//{
//	glScalef(1.4, .8, 1.);
//	glTranslatef(.2, .0, .0);
//	Wuerfel(0.4);
//}
//glPopMatrix();
////glPushMatrix();
//{
//	glTranslatef(1.4 * 0.4, 0., 0.);
//	glScalef(1., 0.3, 1.);
//	glTranslatef(.2, 0., 0.);
//	Wuerfel(0.4);
//}
