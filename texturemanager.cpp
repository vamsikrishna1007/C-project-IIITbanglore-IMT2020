#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "texturemanager.h"
SDL_Texture* texturemanage::texture(const char *fileloc, SDL_Renderer *render){
	SDL_Surface *surface = IMG_Load(fileloc);
	SDL_Texture *text = SDL_CreateTextureFromSurface(render,surface);
	return text;
}
