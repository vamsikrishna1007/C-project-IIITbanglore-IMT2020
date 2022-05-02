
#include "object.h"


void object::create_texture(const char* address, SDL_Renderer *ren){
	tex = texturemanage::texture(address, ren);
}
void object :: set_src_values(int x, int y, int w, int h){
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}
void object :: set_dest_values(int x, int y, int w, int h){
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}
SDL_Texture *object::get_texture(){
	return tex;
}
SDL_Rect object :: get_src(){
	return src;
}
SDL_Rect object :: get_dest(){
	return dest;
}
void object::destroy()
{
	SDL_DestroyTexture(tex);
}	
