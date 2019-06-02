#include "BallMovement.h"
#include "Game.h"
#define SIZE 15 //ball size
#define XMAX 785
#define YMAX 585

using namespace std;
BallMovement::BallMovement()
{
	time1 = clock();
}

void BallMovement::movement()
{
	destBall = { getX(), getY(), SIZE, SIZE };
	if (getX() < 0)
	{
		vellX = 0 - vellX;
	}
	else if (getX() > XMAX)
	{
		vellX = 0 - vellX;
	}
	if (getY() < 0)
	{
		vellY = 0 - vellY;
	}
	/*else if (getY() > YMAX)
	{
		//vellY = 0 - vellY;
		cout << "You lost :(" << endl;
		system("Pause");
	}*/
	int n = getX();
	int m = getY();
	n += vellX;
	m += vellY;
	setX(n);
	setY(m);
	destBall.x = getX();
	destBall.y = getY();
	//cout << "Ball coordinates are " << getX() << ":" << getY() << endl;
	time2 = clock();
	SDL_Delay(1000 /(200 + (float(time2 - time1) / CLOCKS_PER_SEC)));
	//cout << ((time2 - time1) / CLOCKS_PER_SEC) << endl;
}