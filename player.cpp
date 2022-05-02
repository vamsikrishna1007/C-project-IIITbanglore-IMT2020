#include "player.h"
void player::Render(SDL_Renderer *ren){
	timer++;
	if(timer <= 18){
		SDL_RenderCopy(ren,this->get_texture(),NULL,&dest);
	}
	else if(timer <= 36){
		SDL_RenderCopy(ren,tex1,NULL,&dest);
	}
	else if(timer <= 54){
		SDL_RenderCopy(ren,tex2,NULL,&dest);
	}
	if(timer > 54) timer = 0;
}
void player::update(){
	y += 1;
	set_src_values(0,0,SCREEN_WIDTH/25,SCREEN_HEIGHT/20);
	set_dest_values(0,y,SCREEN_WIDTH/25,SCREEN_HEIGHT/20);
	
	
}
void player::CreateTexture1(const char* address, SDL_Renderer* ren){
	tex1 = texturemanage::texture(address, ren);
}
void player::CreateTexture2(const char* address, SDL_Renderer* ren){
	tex2 = texturemanage::texture(address, ren);
}
void player::gravity_up(){
	if(jump){
		y = y + 1 + jump_step;
		set_dest_values(10,y,SCREEN_WIDTH/25,SCREEN_HEIGHT/20);
		if(jump_step > 0){
			jump = false;
			jump_step = -3;
		}
	}
	else{
		y += 1;
		set_dest_values(10,y,SCREEN_WIDTH/25,SCREEN_HEIGHT/20);
	}
}
int player::get_y_pos(){
	return y;
}
void player::gravity_down(){
	y = y + 3;
	set_dest_values(10,y,SCREEN_WIDTH/25,SCREEN_HEIGHT/20);
}
void player::set_jump_timer(){
	jump_timer = SDL_GetTicks();
}
void player::Jump(){
	if((jump_timer - last_jump) > 150){
		a1 = a2 = 0;
		jump = true;
		last_jump = jump_timer;
	}
	else{
		gravity_up();
	}
}
bool player::get_jump_state(){
	return jump;
}
bool player::IsCollision(SDL_Rect rect1,SDL_Rect rect2)
{
	if(SDL_HasIntersection(&rect2,&rect1))
		return true;
	return false;
}
