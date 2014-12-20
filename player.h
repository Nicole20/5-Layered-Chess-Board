#pragma once
#include "stdafx.h"
#include<iostream>
#include<glut.h>
#include<freeglut.h>
#include<ctime>

using namespace std;

class player
{
public:
	player();

	int posx, posy, posz;

	void knight();
	void bishop();
	void rook();
	void queen();

	~player();
};
