#include <SDL_ttf.h>
#include "Game.h"
#include "Objects.h"
#include "PlatformMovement.h"
#include "BallMovement.h"
#include "Brick.h"
#include "Login.h"
#include "RendererError.h"
#include <iostream>

using namespace std;


int main(int argc, char * argv[])
{
	TTF_Init();
	Login* login = NULL;
	Game *game = NULL;
	BallMovement Ball;
	PlatformMovement Platform;
	Objects *object1 = &Ball;
	Objects *object2 = &Platform;
	Brick B(10, 30, 60);
	Brick B1(5, 30, 130);
	Brick B3(15, 30, 35);
	Brick B2 = B;
	login = new Login();
	while (login->running())
	{
		login->update();
		login->render();
	}
	delete login;
	try
	{
		game = new Game(&B, &B1, &B2, &B3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	while (game->running())
	{
		game->render(object1, object2, &B, &B1, &B2, &B3);
		game->update(object1, object2, &B, &B1, &B2, &B3);
	}
	delete game;
	delete object1;
	delete object2;
	return 0;
}