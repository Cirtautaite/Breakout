#pragma once
#include <SDL.h>
#include <SDL_image.h>
#define SIZE 15

using namespace std;

class coordinates
{
private:
	int x, y;
public:
	virtual void setX(int x1 = 0);
	int getX();
	virtual void setY(int y1 = 0);
	int getY();
	void operator()(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
class Objects
{
public:
	coordinates xy;
	Objects() 
	{
		xy(300, 400);
		destBall.x = getX();
		destBall.y = getY();
	};
	bool checkCollision(int pX, int pY, int pH, int pW, int bX, int bY, int bH, int bW);
	//int x = 300, y = 400, h = SIZE, w = SIZE;
	//int x, y;
	//int h = SIZE, w = SIZE;
	SDL_Rect destBall;
	int pX = 300, pY = 550 , pH = 200, pW = 30;
	SDL_Rect destP = { pX, pY, pH, pW };
	int Bx = 50, By = 50, Bh = 30, Bw = 60;
	int vellX = 1, vellY = 1;
	virtual void movement() = 0;
	virtual void setX(int x1);
	int getX();
	virtual void setY(int y1);
	int getY();
};