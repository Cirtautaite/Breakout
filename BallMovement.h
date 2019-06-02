#pragma once
#include "Objects.h"
#include "TextureManager.h"
#include <ctime>

class BallMovement: public Objects
{
private:
	clock_t time1, time2;
public:
	BallMovement();
	void movement() /*override*/;
};