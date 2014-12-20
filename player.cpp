#include "stdafx.h"
#include "player.h"

player::player()
{
	posx = 4;
	posy = 4;
	posz = 4;
}

void player::knight()
{
	srand(time(NULL));

	int a = rand() % 24;

	switch (a)
	{
	case(0) :
		posx = posx + 2;
		posy++;
		break;
	case(1) :
		posx = posx + 2;
		posy--;
		break;
	case(2) :
		posx = posx - 2;
		posy++;
		break;
	case(3) :
		posx = posx - 2;
		posy--;
		break;
	case(4) :
		posx++;
		posy = posy + 2;
		break;
	case(5) :
		posx++;
		posy = posy - 2;
		break;
	case(6) :
		posx--;
		posy = posy + 2;
		break;
	case(7) :
		posx--;
		posy = posy - 2;
		break;
	case(8) :
		posx = posx + 2;
		posz = posz + 2;
		break;
	case(9) :
		posx = posx + 2;
		posz = posz - 2;
		break;
	case(10) :
		posx = posx - 2;
		posz = posz + 2;
		break;
	case(11) :
		posx = posx - 2;
		posz = posz - 2;
		break;
	case(12) :
		posx++;
		posz = posz + 4;
		break;
	case(13) :
		posx++;
		posz = posz - 4;
		break;
	case(14) :
		posx--;
		posz = posz + 4;
		break;
	case(15) :
		posx--;
		posz = posz - 4;
		break;
	case(16) :
		posz = posz + 4;
		posy++;
		break;
	case(17) :
		posz = posz + 4;
		posy--;
		break;
	case(18) :
		posz = posz - 4;
		posy++;
		break;
	case(19) :
		posz = posz - 4;
		posy--;
		break;
	case(20) :
		posz = posz + 2;
		posy = posy + 2;
		break;
	case(21) :
		posz = posz + 2;
		posy = posy - 2;
		break;
	case(22) :
		posz = posz - 2;
		posy = posy + 2;
		break;
	case(23) :
		posz = posz - 2;
		posy = posy - 2;
		break;
	default:
		break;
	}
}

void player::bishop()
{
	srand(time(NULL));

	int a = rand() % 12;

	switch (a)
	{
	case(0) :
		posx++;
		posy++;
		break;
	case(1) :
		posx++;
		posy--;
		break;
	case(2) :
		posx--;
		posy++;
		break;
	case(3) :
		posx--;
		posy--;
		break;
	case(4) :
		posx++;
		posz = posz + 2;
		break;
	case(5) :
		posx--;
		posz = posz + 2;
		break;
	case(6) :
		posx++;
		posz = posz - 2;
		break;
	case(7) :
		posx--;
		posz = posz - 2;
		break;
	case(8) :
		posz = posz + 2;
		posy++;
		break;
	case(9) :
		posz = posz - 2;
		posy++;
		break;
	case(10) :
		posz = posz + 2;
		posy--;
		break;
	case(11) :
		posz = posz - 2;
		posy--;
		break;
	default:
		break;
	}
}

void player::rook()
{
	srand(time(NULL));

	int a = rand() % 6;

	switch (a)
	{
	case(0) :
		posx++;
		break;
	case(1) :
		posy++;
		break;
	case(2) :
		posz = posz + 2;
		break;
	case(3) :
		posx--;
		break;
	case(4) :
		posy--;
		break;
	case(5) :
		posz = posz - 2;
		break;
	default:
		break;
	}
}

void player::queen()
{
	srand(time(NULL));

	int a = rand() % 2;

	if (a == 0)
	{
		bishop();
	}
	else
	{
		rook();
	}
}

player::~player()
{
}
