#pragma once
#include "object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class eagle : public object{
	public:
		void Render(SDL_Renderer *ren);
		void move();
		void move_eagle();
		void set_jump_timer();
		void set_x_value(float x_value);
		void set_y_value(float y_value);
		float get_x_value();
		
		void CreateTexture2(const char* address, SDL_Renderer* ren);
	private:
		float x;
		float y;
		int timer = 0;
		float jump_timer;
		float last_jump = 0;
};