#include "Game.h"
#include "BallMovement.h"
#include "PlatformMovement.h"

using namespace std;

Game::Game(Brick *B, Brick *B1, Brick *B2, Brick *B3)
{
	//TTF_Init();
	//c = new Objects;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Window Initialised!" << endl;

		window = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
		if (window)
		{
			cout << "Window created!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 150, 200, 255);
			cout << "Renderer created!" << endl;
		}
		else throw RendererError("Renderer is not created");
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	//passing bmp files of the blocks
	block1 = TextureManager::loadTex("pirmas.bmp", renderer);

	//passing bmp file of the platform
	platform = TextureManager::loadTex("platform.bmp", renderer);

	//passing bmp file of the ball
	ball = TextureManager::loadTex("ball.bmp", renderer);

	//passing text
	Points = TextureManager::loadText("Points: ", renderer, 20);
	SDL_QueryTexture(Points, NULL, NULL, &texW, &texH);

	for (int i = 0, x = 50, y = 50; i < NORMAL; i++, x+=70)
	{
		B->Bx.push_back(x);
		B->By.push_back(y);
		destBrick[i].x = B->Bx[i];
		destBrick[i].y = B->By[i];
		destBrick[i].h = B->Bh[i];
		destBrick[i].w = B->Bw[i];
		B->alive.push_back(true);
	}
	for (int i = 0, x = 50, y = 130; i < BIG; i++, x += 140)
	{
		B1->Bx.push_back(x);
		B1->By.push_back(y);
		//B1->Bh[i] = 30;
		//B1->Bw[i] = 130;
		//B1->Bx[i] = x;
		//B1->By[i] = y;
		destBrick1[i].x = B1->Bx[i];
		destBrick1[i].y = B1->By[i];
		destBrick1[i].h = B1->Bh[i];
		destBrick1[i].w = B1->Bw[i];
		//B1->alive[i] = true;
		B1->alive.push_back(true);
	}
	for (int i = 0, x = 50, y = 90; i < NORMAL; i++, x += 70)
	{
		B2->Bx.push_back(x);
		B2->By.push_back(y);
		//B2->Bh[i] = 30;
		//B2->Bw[i] = 60;
		//B2->Bx[i] = x;
		//B2->By[i] = y;
		destBrick2[i].x = B2->Bx[i];
		destBrick2[i].y = B2->By[i];
		destBrick2[i].h = B2->Bh[i];
		destBrick2[i].w = B2->Bw[i];
		//B2->alive[i] = true;
		B2->alive.push_back(true);
	}
	for (int i = 0, x = 50, y = 170; i < SMALL; i++, x += 47)
	{
		B3->Bx.push_back(x);
		B3->By.push_back(y);
		destBrick3[i].x = B3->Bx[i];
		destBrick3[i].y = B3->By[i];
		destBrick3[i].h = B3->Bh[i];
		destBrick3[i].w = B3->Bw[i];
		B3->alive.push_back(true);
	}
	time3 = clock();
}

Game::~Game()
{
	WriteToFile();
	SDL_DestroyTexture(block1);
	SDL_DestroyTexture(platform);
	SDL_DestroyTexture(ball);
	SDL_DestroyTexture(Points);
	SDL_DestroyTexture(P);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" << endl;
}

void Game::update(Objects *a, Objects *b, Brick *B, Brick *B1, Brick *B2, Brick *B3)
{	
	a->movement();
	b->movement();
	a->destBall.y = a->getY();
	a->destBall.x = a->getX();
	if (a->checkCollision(b->pX, b->pY, b->pW, b->pH, a->getX(), a->getY(), 15, 15) == true)
	{
		a->vellY = -a->vellY;
		/*cout << b->pX << endl;
		cout << b->pY << endl;
		cout << b->pH << endl;
		cout << b->pW << endl;
		cout << a->getX() << endl;
		cout << a->getY() << endl;*/
	}	
	for (int i = 0; i < NORMAL; i++)
	{
		if (B->alive[i] == true)
		{
			if (a->checkCollision(destBrick[i].x, destBrick[i].y, destBrick[i].h, destBrick[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				//cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
				/*cout << destBrick[i].x << endl;
				cout << destBrick[i].y << endl;
				cout << destBrick[i].h << endl;
				cout << destBrick[i].w << endl;
				cout << a->getX() << endl;
				cout << a->getY() << endl;*/
				a->vellX = 0 - a->vellX;
				m[i]++;
				if (m[i] > 1)
				{
					B->alive[i] = false;
					n++;
					points += 200;
				}
			}
		}
		
	}
	for (int i = 0; i < NORMAL; i++)
	{
		if (B->alive[i] == true)
		{
			if (a->checkCollision(destBrick[i].x, destBrick[i].y, destBrick[i].h, destBrick[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				/*cout << destBrick[i].x << endl;
				cout << destBrick[i].y << endl;
				cout << destBrick[i].h << endl;
				cout << destBrick[i].w << endl;
				cout << a->getX() << endl;
				cout << a->getY() << endl;*/
				a->vellY = 0 - a->vellY;
				if (m[i] > 1)
				{
					B->alive[i] = false;
					n++;
					points += 200;
				}		
			}
		}	
	}
	for (int i = 0; i < BIG; i++)
	{
		if (B1->alive[i] == true)
		{
			if (a->checkCollision(destBrick1[i].x, destBrick1[i].y, destBrick1[i].h, destBrick1[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				//cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
				a->vellX = 0 - a->vellX;
				B1->alive[i] = false;
				n++;
				points += 150;
			}
		}
	}
	for (int i = 0; i < BIG; i++)
	{
		if (B1->alive[i] == true)
		{
			if (a->checkCollision(destBrick1[i].x, destBrick1[i].y, destBrick1[i].h, destBrick1[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				time1 = clock();
				a->vellY = 0 - a->vellY;
				B1->alive[i] = false;
				n++;
				points += 150;
			}
		}
	}
	for (int i = 0; i < NORMAL; i++)
	{
		if (B2->alive[i] == true)
		{
			if (a->checkCollision(destBrick2[i].x, destBrick2[i].y, destBrick2[i].h, destBrick2[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				//cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
				time1 = clock();
				a->vellX = 0 - a->vellX;
				B2->alive[i] = false;
				n++;
				points += 100;
			}
		}
	}
	for (int i = 0; i < NORMAL; i++)
	{
		if (B2->alive[i] == true)
		{
			if (a->checkCollision(destBrick2[i].x, destBrick2[i].y, destBrick2[i].h, destBrick2[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				time1 = clock();
				a->vellY = 0 - a->vellY;
				B2->alive[i] = false;
				n++;
				points += 100;
			}
		}
	}
	for (int i = 0; i < SMALL; i++)
	{
		if (B3->alive[i] == true)
		{
			if (a->checkCollision(destBrick3[i].x, destBrick3[i].y, destBrick3[i].h, destBrick3[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				//cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
				a->vellX = 0 - a->vellX;
				B3->alive[i] = false;
				n++;
				points += 50;
			}
		}
	}
	for (int i = 0; i < SMALL; i++)
	{
		if (B3->alive[i] == true)
		{
			if (a->checkCollision(destBrick3[i].x, destBrick3[i].y, destBrick3[i].h, destBrick3[i].w,
				a->getX(), a->getY(), 15, 15) == true)
			{
				a->vellY = 0 - a->vellY;
				B3->alive[i] = false;
				n++;
				points += 50;
			}
		}
	}
	if (time1 > 0)
	{
		time2 = clock();
		if ((float(time2 - time1) / CLOCKS_PER_SEC) < 5)
		{
			b->pH = 250;
		}
		else
		{
			b->pH = 200;
		}
		b->destP.w = b->pH;
		//cout << float(time2 - time1) / CLOCKS_PER_SEC << endl; 
	}
	if (a->getY() > 585)
	{
		cout << "You lost :(" << endl;
		system("Pause");
		isRunning = false;
	}
	time4 = clock();
	if ((float(time4 - time3) / CLOCKS_PER_SEC) >= 1)
	{
		points --;
		time3 = clock();
	}
	//cout << (float(time4 - time3) / CLOCKS_PER_SEC) << endl;
	cout << points << endl;
}

void Game::render(Objects *a, Objects *b, Brick *B, Brick *B1, Brick *B2, Brick *B3)
{
	SDL_RenderClear (renderer);
	for (int i = 0; i <NORMAL; i++)
	{
		if (B->alive[i] == true)
		{
			SDL_RenderCopy(renderer, block1, NULL, &destBrick[i]);
		}
	}
	for (int i = 0; i < BIG; i++)
	{
		if (B1->alive[i] == true)
		{
			SDL_RenderCopy(renderer, block1, NULL, &destBrick1[i]);
		}
	}
	for (int i = 0; i < NORMAL; i++)
	{
		if (B2->alive[i] == true)
		{
			SDL_RenderCopy(renderer, block1, NULL, &destBrick2[i]);
		}
	}
	for (int i = 0; i < SMALL; i++)
	{
		if (B3->alive[i] == true)
		{
			SDL_RenderCopy(renderer, block1, NULL, &destBrick3[i]);
		}
	}
	SDL_RenderCopy(renderer, platform, NULL, &b->destP);
	SDL_RenderCopy(renderer, ball, NULL, &a->destBall);
	if (n == BRICKS)
	{
		//int lvl = 2;
		cout << "LEVEL "<< lvl <<"!" << endl;
		n = 0;
		for (int i = 0; i < NORMAL; i++)
		{
			B->alive[i] = true;
			B2->alive[i] = true;
		}
		for (int i = 0; i < BIG; i++)
		{
			B1->alive[i] = true;
		}
		for (int i = 0; i < SMALL; i++)
		{
			B3->alive[i] = true;
		}
		SDL_Delay(1000);
		points += lvl * 1000;
		lvl++;
		a->setX(300);
		a->setY(400);
		a->vellX = -a->vellX;
		a->vellY = -a->vellY;
		//system("Pause");
	}
	SDL_Rect dstrect = { 0, 0, texW, texH };
	SDL_RenderCopy(renderer, Points, NULL, &dstrect);
	P = TextureManager::loadText((char *)&points, renderer, 20);
	SDL_Rect destp = { 65, 0, texW1, texH1 };
	SDL_QueryTexture(P, NULL, NULL, &texW1, &texH1);
	SDL_RenderCopy(renderer, P, NULL, &destp);
	SDL_RenderPresent(renderer);
	
}

void Game::WriteToFile()
{
	ofstream File;
	File.open("Points.bin", ios::out | ios::binary | ios::app);
	if (File.is_open())
	{
		File.write((const char *)&points, sizeof(int));
		File.close();
	}
}