#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Objects.h"
#include "Brick.h"
#include <ctime>
#include "RendererError.h"
#include "fstream"
#include "Login.h"
const int BRICKS = 2 * NORMAL + BIG + SMALL;
#define POINT 1000

class Game
{
public:
	Game(Brick *B, Brick *B1, Brick *B2, Brick *B3);
	~Game();
	void update(Objects *a, Objects *b, Brick *B, Brick *B1, Brick *B2, Brick *B3);
	void render(Objects *a, Objects *b, Brick *B, Brick *B1, Brick *B2, Brick *B3);
	bool running()
	{
		return isRunning;
	}
	int points = POINT;
private:
	//TTF_Font * font = TTF_OpenFont("arial.ttf", 25);
	int m[10] = { 0 };
	clock_t time1, time2, time3, time4;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture* block1;
	SDL_Texture* platform;
	SDL_Texture* ball;
	SDL_Texture* Points;
	SDL_Texture* P;
	int texW = 0;
	int texH = 0, texH1 = 0, texW1 =0;
	SDL_Rect dstrect = { 0, 0, texW, texH };
	int n = 0;
	int lvl = 2;
	SDL_Rect destBrick[NORMAL], destBrick1[BIG], destBrick2[NORMAL], destBrick3[SMALL];
	void WriteToFile();
	//std::vector <SDL_Rect> destBrick, destBrick1, destBrick2, destBrick3;
};