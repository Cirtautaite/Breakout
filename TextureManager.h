#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class TextureManager
{
public:
	static SDL_Texture* loadTex(const char* photoName, SDL_Renderer* ren);
	static SDL_Texture* loadText(const char* text, SDL_Renderer* ren, int size);
};
