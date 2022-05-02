#pragma once
#include "object.h"
#include "definations.h"

class building : public object{
	public:
		void Render(SDL_Renderer *ren);
		void move();
		void move_pipe();
		void set_jump_timer();
		void set_x_value(float x_val);
		
	private:
		float x;
		float timer = 0;
		float jump_timer;
		float last_jump = 0;
};

