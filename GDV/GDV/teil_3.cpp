// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#pragma once

#include "Wuerfel.h"

#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include "Cam.h"
#include "Plane.h"
#include "Landscape.h"

float fRotation = 315.0;

Cam cam;
Plane plane1;
Plane plane2;
Plane plane3;
Plane plane4;
Plane plane5;
Plane plane6;
Landscape landscape;


void Init()
{

	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgef�hrt werden m�ssen
	

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearDepth(1.0);
}


void RenderScene() //Zeichenfunktion
{
	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity(); // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClearColor(0.35, 0.35, .7, 0.);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glPopMatrix();
	cam.move();

	landscape.render();

	glPushMatrix();
	plane1.Render();
	glTranslatef(1, 1, -2);
	plane2.Render();
	glTranslatef(2, 1, 2);
	plane3.Render();
	glTranslatef(2, 1, 2);
	plane4.Render();
	glPopMatrix();
	glTranslatef(-1, 1, 2);
	plane5.Render();
	glTranslatef(-2, 1, -2);
	plane6.Render();

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
	//TODO Fareplane kleiner machen um denn boden zum kreis erzeugen.
	gluPerspective(45., 1., 0.1, 13.0);
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
	cam.animate();
	landscape.animate();
	plane1.Animate();
	plane2.Animate();
	plane3.Animate();
	plane4.Animate();
	plane5.Animate();
	plane6.Animate();


	// RenderScene aufrufen
	glutPostRedisplay();
	// Timer wieder registrieren - animate wird so nach 10 msec mit value+=1 aufgerufen.
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
	landscape = Landscape();
	cam = Cam();
	plane1 = Plane();
	plane2 = Plane();
	plane3 = Plane();
	plane4 = Plane();
	plane5 = Plane();
	plane6 = Plane();
	

	glutInit(&argc, argv); // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800); // Fenster-Konfiguration

	glutCreateWindow("Lukas Assmann; Marcel Feix"); // Fenster-Erzeugung
	//glutPositionWindow(3000, 0);

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
