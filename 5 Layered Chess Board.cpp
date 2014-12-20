// 5 Layered Chess Board.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<glut.h>
#include<freeglut.h>
#include<ctime>
#include"ObjLoader.h"
#include"player.h"

using namespace std;

void initialize();
void draw();
void drawBoard();
void drawTiles(int x, int y, int z);
void rotate(int key, int x, int y);
void keyPressed(unsigned char key, int x, int y);
void drawPawn();
void placePawn();

int pawn;
ObjLoader obj_pawn;
player players;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("5 Layered Chess Board");

	initialize();

	glutDisplayFunc(draw);
	glutSpecialFunc(rotate);
	glutKeyboardFunc(keyPressed);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -20, 20);

	pawn = obj_pawn.load("pawn.obj");
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(-5, -5, 0);
	
	drawBoard();

	glPopMatrix();

	glPushMatrix();
	placePawn();
	glPopMatrix();

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void drawBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (k % 2 == 0 && j % 2 == 0 && i % 2 == 0)
				{
					drawTiles(i, j, 2 * k);
				}
				else if (k % 2 == 0 && j % 2 == 1 && i % 2 == 1)
				{
					drawTiles(i, j, 2 * k);
				}
				else if (k % 2 == 1 && j % 2 == 0 && i % 2 == 1)
				{
					drawTiles(i, j, 2 * k);
				}
				else if (k % 2 == 1 && j % 2 == 1 && i % 2 == 0)
				{
					drawTiles(i, j, 2 * k);
				}
			}
		}
	}
}

void drawTiles(int x, int y, int z)
{
	switch (z)
	{
	case(0):
		glColor3f(0.6, 0, 0);
		break;
	case(2) :
		glColor3f(0, 0.5, 0);
		break;
	case(4) :
		glColor3f(0, 0, 0.5);
		break;
	case(6) :
		glColor3f(0.6, 0.6, 0);
		break;
	case(8) :
		glColor3f(0.5, 0, 0.5);
		break;
	default:
		break;
	}
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x + 1, y, z);
	glVertex3f(x + 1, y + 1, z);
	glVertex3f(x, y + 1, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, z - 0.1);
	glVertex3f(x + 1, y, z - 0.1);
	glVertex3f(x + 1, y, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, z - 0.1);
	glVertex3f(x, y + 1, z - 0.1);
	glVertex3f(x, y + 1, z);

	glVertex3f(x + 1, y, z);
	glVertex3f(x + 1, y, z - 0.1);
	glVertex3f(x + 1, y + 1, z - 0.1);
	glVertex3f(x + 1, y + 1, z);

	glVertex3f(x, y + 1, z);
	glVertex3f(x, y + 1, z - 0.1);
	glVertex3f(x + 1, y + 1, z - 0.1);
	glVertex3f(x + 1, y + 1, z);

	glVertex3f(x, y, z - 0.1);
	glVertex3f(x + 1, y, z - 0.1);
	glVertex3f(x + 1, y + 1, z - 0.1);
	glVertex3f(x, y + 1, z - 0.1);
	glEnd();
}

void rotate(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		glRotatef(5, 1, 0, 0);
	}
	else if (key == GLUT_KEY_DOWN)
	{
		glRotatef(-5, 1, 0, 0);
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		glRotatef(5, 0, 1, 0);
	}
	else if (key == GLUT_KEY_LEFT)
	{
		glRotatef(-5, 0, 1, 0);
	}

	glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y)
{
	if (key == 'k')
	{
		players.knight();
	}
	else if (key == 'b')
	{
		players.bishop();
	}
	else if (key == 'r')
	{
		players.rook();
	}
	else if (key == 'q')
	{
		players.queen();
	}

	glutPostRedisplay();
}

void drawPawn()
{
	for (unsigned int i = 0; i < obj_pawn.faces.size(); i++)
	{
		if (obj_pawn.faces[i]->four)
		{
			glBegin(GL_QUADS);
			for (int ii = 0; ii < 4; ii++)
			{
				glVertex3f(obj_pawn.vertex[obj_pawn.faces[i]->faces[ii] - 1]->xx,
					obj_pawn.vertex[obj_pawn.faces[i]->faces[ii] - 1]->yy,
					obj_pawn.vertex[obj_pawn.faces[i]->faces[ii] - 1]->zz);
			}
			glEnd();
		}
		else
		{
			glBegin(GL_TRIANGLES);
			for (int ii = 0; ii < 3; ii++)
			{
				glVertex3f(obj_pawn.vertex[obj_pawn.faces[i]->faces[ii] - 1]->xx,
					obj_pawn.vertex[obj_pawn.faces[i]->faces[ii] - 1]->yy,
					obj_pawn.vertex[obj_pawn.faces[i]->faces[ii] - 1]->zz);
			}
			glEnd();
		}
	}
}

void placePawn()
{
	glColor3f(0, 0.5, 0.5);

	glTranslatef(-5.5, -5, 0.5);

	glTranslatef(players.posx, players.posy, players.posz);
	glRotatef(90, 1, 0, 0);
	glScalef(0.3, 0.3, 0.3);
	drawPawn();
}
