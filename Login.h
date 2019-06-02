#pragma once
#include <SDL.h>
#include <iostream>
#include "TextureManager.h"
#include <vector>
#include <string>
#include <assert.h>
#include <stdio.h>
#include "fstream"
#include <algorithm>


class Login
{
public:
	Login();
	~Login();
	bool running()
	{
		return isRunning;
	}
	void render();
	void update();
private:
	std::vector<std::string>Names;
	std::vector<std::string>Passwords;
	std::vector<std::string>Points;
	//std::vector<std::string>::iterator &N;
	std::string name;
	std::string Password;
	SDL_Event event;
	//textures
	SDL_Texture* textureName1;
	SDL_Texture* textureName2;
	SDL_Texture* textureName3;
	SDL_Texture* Choice;
	SDL_Texture* Button;
	SDL_Texture* tologin;
	SDL_Texture* toregister;
	SDL_Texture* username;
	SDL_Texture* password;
	SDL_Texture* goBack;
	SDL_Texture* BestPlayers;
	//surfaces
	SDL_Surface* surfaceName1;
	SDL_Surface* surfaceName2;
	SDL_Surface* surfaceName3;

	SDL_Window *window;
	SDL_Renderer *renderer;
	
	bool isRunning;
	TTF_Font * font = TTF_OpenFont("arial.ttf", 30);
	SDL_Color color = { 255, 255, 255 };
	int texW = 0, texH = 0, texW1 = 0, texH1 = 0, texW2 = 0, texH2 = 0, texH3 = 0, texW3 = 0, texH4 = 0, texW4 = 0, tH5 = 0, tW5 = 0, tW6 = 0, tH6 = 0;
	int W = 0, H = 0, W2 =0, H2 =0, W3=0, H3=0;
	int n = 0, i= 0, m=0;
	int x = 90, y = 100, w = 220, h = 70;
	SDL_Rect destL = { x, y, w, h };
	SDL_Rect destR = { x, y+x, w, h };
	SDL_Rect destBest = { x, 2 * y + x, w, h };
	SDL_Rect destU = { 15, 75, 370, 50 };
	SDL_Rect destP = { 15, 175, 370, 50 };
	SDL_Rect destgo = { 15, 235, 140, 50 };
	SDL_Rect destback = { 245, 235, 140, 50 };
	/*bool operator=(const Login &l)
	{
		if (name == l.name) return true;
		else return false;
	}*/
	void EnterUsername();
	void login();
	void Register();
	void ReadFromFile();
	void SaveToFile();
	template <typename T>
	bool compare(T a, T b)
	{
		return a < b;
	}
};