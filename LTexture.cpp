#include "LTexture.h"
#include "definations.h"
bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font* gFont )
{
	
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	
	
	return mTexture != NULL;
}
void LTexture::render(SDL_Renderer *gRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	
	SDL_Rect renderQuad = { SCREEN_WIDTH/2+50,SCREEN_HEIGHT/2, mWidth, mHeight };

	
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}
LTexture::LTexture()
{
	
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}
int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
