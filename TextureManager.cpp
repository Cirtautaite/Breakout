#include "TextureManager.h"


SDL_Texture* TextureManager::loadTex(const char* photoName, SDL_Renderer* ren) {

	SDL_Surface* tempSur = SDL_LoadBMP(photoName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSur);
	SDL_FreeSurface(tempSur);
	return tex;
}
SDL_Texture* TextureManager::loadText(const char* text, SDL_Renderer* ren, int size)
{
	TTF_Font * font = TTF_OpenFont("arial.ttf", size);
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface * surface = TTF_RenderText_Solid(font,text, color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(ren, surface);
	return texture;
}