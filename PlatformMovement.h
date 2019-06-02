#pragma once
#include "Game.h"
#include <ctime>

class PlatformMovement: public Objects
{
private:
	clock_t time1, time2;
public:
	PlatformMovement() {}
	~PlatformMovement() {}
	void movement() /*override*/;
};