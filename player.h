#pragma once
#include "object.h"
#include "definations.h"

class player : public object{
	private:
		int y = 0;
		int timer = 0;
		bool jump = false;
		SDL_Texture *tex1;
		SDL_Texture *tex2;
		double jump_step = -3;
		double last_jump = 0;
		double jump_timer;
		double a1 = 0;
		double a2 = 0;
	public:
		void update();
		bool get_jump_state();
		void gravity_up();
		void gravity_down();
		void Jump();
		int get_y_pos();
		void set_jump_timer();
		void CreateTexture1(const char* address, SDL_Renderer* ren);
		void CreateTexture2(const char* address, SDL_Renderer* ren);
		void Render(SDL_Renderer *ren);  
		bool IsCollision(SDL_Rect rect1,SDL_Rect rect2);
		
};

