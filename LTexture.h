#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

class LTexture{
	public:
		LTexture();
		int getWidth();
		int getHeight();
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font* gFont );
		void render(SDL_Renderer *gRenderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};

