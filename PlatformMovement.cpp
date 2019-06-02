#include "PlatformMovement.h"
#include <iostream>

using namespace std;

void PlatformMovement::movement()
{
	SDL_Event event;
	SDL_PollEvent (&event);
	switch (event.type)
	{
		/*case SDL_QUIT:
			isRunning = false;
			break;*/
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			if (pX < (800-pH))
			{
				pX = pX + 10;
				break;
			}
			else
			{
				break;
			}
		case SDLK_LEFT:
			if (pX > 0)
			{
				pX = pX - 10;
				break;
			}
			else
			{
				break;
			}
		}
	default:
		break;
	}
	destP.x = pX;
	//cout << "Platform coordinates are " << pX << ":" << pY << endl;
}