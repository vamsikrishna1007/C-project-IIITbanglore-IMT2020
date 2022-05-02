#include "coin.h"
void coin::Render(SDL_Renderer *ren){
	
	SDL_RenderCopy(ren, this->get_texture(), NULL, &dest);
	
}
void coin::move_coin(){
	//if(jump_timer > 10000){
		//x -= 3;
	//}
	//else{
	x -= 1;
	//}
	//set_dest_values(0,0,50,82);
	static int i=0;
	if(i%2 != 0){
		set_dest_values(x,y,30,30);
		i++;
	}
	else{
		set_dest_values(x,y,30,30);
		i++;
	}
	
}
void coin::move(){
	if((jump_timer - last_jump) > 1000){
		last_jump = jump_timer;
	}
	else{
		move_coin();
	}
}
void coin::set_jump_timer(){
	jump_timer = SDL_GetTicks(); 
}

void coin::set_x_value(float x_val){
	x = x_val;
}
void coin::set_y_value(float y_val){
	y = y_val;
}
float coin::get_x_value(){
	return x;
}
