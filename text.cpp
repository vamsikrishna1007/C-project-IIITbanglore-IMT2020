#include "text.h"
#include "game.h"
#include "texturemanager.h"
#include "LTexture.h"

//All the font related things are done in this file.


void text::init(SDL_Renderer *rend,SDL_Window *wind)
{
    std::string inputText = " ";
    
    
    
    LTexture gInputTextTexture;
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) ;
    Mix_Music *bgmusic = Mix_LoadMUS("sound/penguinmusic-modern-chillout-12641.mp3") ;
    Mix_Music *bgmusic2 = Mix_LoadMUS("sound/just-relax-11157.mp3") ;
    Mix_Chunk *collection_sound = Mix_LoadWAV("sound/mixkit-unlock-game-notification-253.wav");

    SDL_Texture *bg_t = texturemanage::texture("img/background-night.png",rend);
    SDL_RenderClear(rend);
    TTF_Font* gFont1 = TTF_OpenFont("font/cha.ttf", 65);
    TTF_Font* f = TTF_OpenFont("font/cha.ttf", 35);
    gInputTextTexture.loadFromRenderedText( inputText.c_str(), color, rend, gFont1 );	
    	
    const char* label[7]={"PLAY","LEADERBOARD","ENTER NAME :","SCORE:","Exit","Please, Enter your name before you start playing"};
		
	
    SDL_Color color = { 255,255,255,0 };

    SDL_Surface *surfacemenu[7];
    surfacemenu[0] = TTF_RenderText_Solid(gFont1, label[0], color);
    surfacemenu[1] = TTF_RenderText_Solid(gFont1, label[1], color);
    surfacemenu[2] = TTF_RenderText_Solid(gFont1, label[2], color);
    surfacemenu[3] = TTF_RenderText_Solid(gFont1, label[3], {180,140,230,0});
    surfacemenu[4] = TTF_RenderText_Solid(gFont1, label[4], color);
    surfacemenu[5] = TTF_RenderText_Solid(f, label[5], color);
    
		
    SDL_Texture *t_0 = SDL_CreateTextureFromSurface(rend, surfacemenu[0]);
    SDL_Texture *t_1 = SDL_CreateTextureFromSurface(rend, surfacemenu[1]);
    SDL_Texture *t_2 = SDL_CreateTextureFromSurface(rend, surfacemenu[2]);
    SDL_Texture *t_3 = SDL_CreateTextureFromSurface(rend, surfacemenu[3]);
    SDL_Texture *t_4 = SDL_CreateTextureFromSurface(rend, surfacemenu[4]);
    SDL_Texture *t_5 = SDL_CreateTextureFromSurface(rend, surfacemenu[5]);
 
    SDL_Rect rect[7]{};
    rect[0]={SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2-200,surfacemenu[0]->w,surfacemenu[0]->h};
    rect[1]={SCREEN_WIDTH/2-230,SCREEN_HEIGHT/2-90,surfacemenu[1]->w,surfacemenu[1]->h};
    rect[2]={SCREEN_WIDTH/2-230,SCREEN_HEIGHT/2,surfacemenu[2]->w,surfacemenu[2]->h};
    rect[3]={SCREEN_WIDTH-210,0,surfacemenu[3]->w,surfacemenu[3]->h};
    rect[4]={SCREEN_WIDTH/2-230,SCREEN_HEIGHT/2+100,surfacemenu[4]->w,surfacemenu[4]->h};
    rect[5]={0,0,surfacemenu[5]->w,surfacemenu[5]->h};

    

    SDL_Event e;
    bool quit=false,flag;
    while(!quit)
    {
    	Mix_PlayMusic(bgmusic2, -1);
        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT){
        	quit = true;
        	break;
	}
			
	bool renderText = false;
        if((e.type == SDL_MOUSEBUTTONDOWN) && (e.motion.x > rect[0].x) && (e.motion.x < (rect[0].x + rect[0].w)) && (e.motion.y > rect[0].y) && (e.motion.y < (rect[0].y + rect[0].h)))
        {
        	
		double first;
		double last = 0;
		game *g = new game();
				
		Mix_PlayMusic(bgmusic, -1);
				
				//g->init("Runn...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_SHOWN);
                SDL_RenderClear(rend);
		g->init(rend, wind);
		SDL_RenderPresent(rend);
		while(g->running()){
			g->handleEvent();
			g->render();
			flag=g->Checkcollision(inputText);
                  	if(!flag){
                        	
                        	quit=true;
                        	SDL_Delay(1000);
                        	break;
                    	}
                    	string s(std::to_string(g->get_score()));
                    	const char* score = const_cast<char*>(s.c_str());
                    	SDL_Surface *sur=TTF_RenderText_Solid(gFont1,score,{0,0,255,0});
                    	SDL_Texture *tex=SDL_CreateTextureFromSurface(rend,sur);
                    	SDL_Rect r={SCREEN_WIDTH-70,0,sur->w,sur->h};
                    	g->update(t_3,rect[3],tex,r);
                    
			first = SDL_GetTicks();
			if(first - last < 18){
				SDL_Delay(18 - (first - last));
			}
			last = first;
		}
               
               SDL_Delay(4000);
			   g->quit();
               init(rend,wind);
               break;
                
	}
	if( e.type == SDL_KEYDOWN ){
                        //Handle backspace
                	SDL_Delay(200);
    		if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 ){
                            //lop off character
       		inputText.pop_back();
                        renderText = true;
                }
                        //Handle copy
                else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL ){
                	SDL_SetClipboardText( inputText.c_str() );
                }
                        //Handle paste
                else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL ){
                        inputText = SDL_GetClipboardText();
                        renderText = true;
                }
       }
       else if( e.type == SDL_TEXTINPUT ){
                        //Not copy or pasting
       	if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) ){
                            //Append character
                            		inputText += e.text.text;
                            		renderText = true;
                        	}
       }
       if( renderText ){
                    //Text is not empty
     		if( inputText != "" ){
                        //Render new text
                        gInputTextTexture.loadFromRenderedText( inputText.c_str(), color, rend, gFont1 );
                }
                    //Text is empty
                else{
                        //Render space texture
                       gInputTextTexture.loadFromRenderedText( " ", color, rend, gFont1 );
                }
   }
	if((e.type == SDL_MOUSEBUTTONDOWN) && (e.motion.x > rect[1].x) && (e.motion.x < (rect[1].x + rect[1].w)) && (e.motion.y > rect[1].y) && (e.motion.y < (rect[1].y + rect[1].h))){

		SDL_Event a;
		SDL_Texture* texture2;
		SDL_Texture* tx[5];//for names
		SDL_Texture* txt[5];//for scores
		char* top;
		char* names[5];//for names
		char* scores[5];//for scores
		SDL_Rect rect1[5]{};
		SDL_Rect rect2[5]{};
		SDL_Rect r{};
		SDL_Surface* t_s;
		SDL_Surface* sm[5];//for names
		SDL_Surface* sf[5];//for scores
		vector<pair<string, string>> v;
		pair<string,string> p;
		string s1;
		string s2;
		int i = 0;
		ifstream indata;
		indata.open("Score_Data.txt");
		while(!indata.eof()){
			indata >> s1 >> s2;
			p.first = s1;
			p.second = s2;
			v.insert(v.begin() + i,p);
			i++;
		}
		v.pop_back();
		indata.close();
		
		TTF_Font *gfont = TTF_OpenFont("font/cha.ttf", 45);
			
		top = (char*)"TOP SCORES : ";
		t_s = TTF_RenderText_Solid(gfont, top, color);
		texture2 = SDL_CreateTextureFromSurface(rend, t_s);
		r.x = 200;
		r.y = 50;
		r.w = t_s->w;
		r.h = t_s->h;
			
			
		for(int i=0;i<v.size();i++){
			names[i] = const_cast<char*>(v[i].first.c_str());
			
			scores[i] = const_cast<char*>(v[i].second.c_str());
			
			if(i>=4) break;
		}
		for(int i=0;i<v.size();i++){
			sm[i] = TTF_RenderText_Solid(gfont, names[i], color);
			sf[i] = TTF_RenderText_Solid(gfont, scores[i], color);
			if(i>=4) break;
		}
		for(int i=0;i<v.size();i++){
			tx[i] = SDL_CreateTextureFromSurface(rend, sm[i]);
			txt[i] = SDL_CreateTextureFromSurface(rend, sf[i]);
			if(i>=4) break;
		}
		for(int i=0;i<v.size();i++){
			SDL_FreeSurface(sm[i]);
			SDL_FreeSurface(sf[i]);
		}
		int j=0;
		int y=200;
		
		for(int i=0;i<v.size();i++){	
			rect1[i].x = 100;
			rect1[i].y = y;
			rect1[i].w = sm[i]->w;
			rect1[i].h = sm[i]->h;

			rect2[i].x = 600;
			rect2[i].y = y;
			rect2[i].w = sf[i]->w;
			rect2[i].h = sf[i]->h;
			j+=2;
			y+=70;
			if(i>=4) break;
		}
		
		while(true){
			SDL_PollEvent(&a);
			if(a.type == SDL_QUIT){
				
				break;
			}
			SDL_RenderClear(rend);
			SDL_SetRenderDrawColor(rend,30,240,255,0);
			SDL_RenderCopy(rend, texture2, NULL, &r);
			for(int i=0;i<v.size();i++){
					
				SDL_RenderCopy(rend, tx[i], NULL, &rect1[i]);
				SDL_RenderCopy(rend, txt[i], NULL, &rect2[i]);
					
					
				if(i>=4) break;
				
			}
			SDL_RenderPresent(rend);
		}
		
		init(rend,wind);
		break;
	}
        if((e.type == SDL_MOUSEBUTTONDOWN) && (e.motion.x > rect[4].x) && (e.motion.x < (rect[4].x + rect[4].w)) && (e.motion.y > rect[4].y) && (e.motion.y < (rect[4].y + rect[4].h)))
        {
				quit = true;
	}
        SDL_RenderCopy(rend,bg_t,NULL,NULL);
        SDL_RenderCopy(rend,t_0,NULL,&rect[0]);
        SDL_RenderCopy(rend,t_1,NULL,&rect[1]);
        SDL_RenderCopy(rend,t_2,NULL,&rect[2]); 
        SDL_RenderCopy(rend,t_4,NULL,&rect[4]);
        SDL_RenderCopy(rend,t_5,NULL,&rect[5]);
        gInputTextTexture.render(rend);
   
        

        SDL_RenderPresent(rend);
        
        
    }
    
    SDL_RenderPresent(rend);
}
