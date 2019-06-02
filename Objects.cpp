#include "Objects.h"

using namespace std;

bool Objects::checkCollision(int pX, int pY, int pH, int pW, int bX, int bY, int bH, int bW)
{
	if ((pY + pH) < bY) return false;
	else if (pY > bY + bH) return false;
	else if (pX + pW < bX) return false;
	else if (pX > bX + bW) return false;
	else return true;
}

void coordinates::setX(int x1)
{
	x = x1;
}

int coordinates::getX()
{
	return x;
}

void coordinates::setY(int y1)
{
	y = y1;
}

int coordinates::getY()
{
	return y;
}

void Objects::setX(int x1)
{
	xy.setX(x1);
}

int Objects::getX()
{
	return xy.getX();
}

void Objects::setY(int y1)
{
	xy.setY(y1);
}

int Objects::getY()
{
	return xy.getY();
}