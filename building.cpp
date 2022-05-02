#include "building.h"
void building::Render(SDL_Renderer *ren){
	SDL_RenderCopy(ren,this->get_texture(),NULL,&dest);
}
void building::set_jump_timer(){
	jump_timer = SDL_GetTicks(); 
}
void building::move_pipe(){
	if(jump_timer > 10000){
		x -= 3;
	}
	else{
		x -= 1;
	}
	
	static int i=0;
	if(i%2 == 0){
		set_dest_values(x,SCREEN_HEIGHT/2,SCREEN_WIDTH/15,SCREEN_HEIGHT/2);
		i++;
	}
	else{
		
		set_dest_values(x,2*SCREEN_HEIGHT/5,SCREEN_WIDTH/15,3*SCREEN_HEIGHT/5);
		i++;
	}
	
}
void building::move(){
	if((jump_timer - last_jump) > 1000){
		last_jump = jump_timer;
	}
	else{
		move_pipe();
	}
}
void building::set_x_value(float x_val){
	x = x_val;
}
