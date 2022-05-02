#pragma once

#include <string>
#include "player.h"
#include "background.h"
#include "building.h"
#include "coin.h"
#include "eagle.h"
#include "definations.h"
using namespace std;
class game{
	public:
		game();
		~game();
		
		void init(SDL_Renderer *rend, SDL_Window *wind);
		void update(SDL_Texture *texture_1,SDL_Rect r_1,SDL_Texture *texture_2,SDL_Rect r_2);
		void handleEvent();
		void render();
		bool running(){ return is_running;}
		static bool myComparison(const pair<string,int> &a,const pair<string,int> &b);
		bool Checkcollision(string s);
		int get_score();
		void quit();
	private:
		float score = 0;
		TTF_Font* gFont;
		SDL_Surface* surmenu[2];
		SDL_Color color = { 100,200,150,0 };
		SDL_Rect rec[2]{};
		SDL_Texture* texture0;
		SDL_Texture* texture1;
		const char* texts[2] = { "Coins : ", "0"};
		SDL_Window *window;
		SDL_Renderer *renderer;
		player p;
		background bg;
		building pi;
		coin co;
		eagle eag;
		vector<coin> coins;
		vector<eagle> eagles;
		vector<building> pipes;
		SDL_Texture *t;
		SDL_Event event;
		bool is_running;
		
};
