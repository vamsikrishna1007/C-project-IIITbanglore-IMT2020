#pragma once
#include "object.h"
#include "definations.h"

class background : public object{
	public:
		void Render(SDL_Renderer *ren);
		void set_jump_timer();
		void Move_bg(SDL_Renderer *ren);
		void move(SDL_Renderer *ren);
		
	private:
		float x = 0;
		float timer = 0;
		float jump_timer;
		float last_jump = 0;
};

