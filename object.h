#pragma once
#include "definations.h"
#include "texturemanager.h"
class object{
	public:
		SDL_Rect src;
		SDL_Rect dest;
		SDL_Texture* tex = NULL;
	
		virtual void Render(SDL_Renderer *ren, SDL_Texture *tex, SDL_Rect src, SDL_Rect dest){}
		void set_src_values(int x, int y, int w, int h);
		void set_dest_values(int x, int y, int w, int h);
		void create_texture(const char *texture, SDL_Renderer *ren);
		SDL_Texture *get_texture();
		SDL_Rect get_src();
		SDL_Rect get_dest();
		void destroy();
};

