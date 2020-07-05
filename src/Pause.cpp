#include "Pause.hpp"

Pause::Pause() : GameObject()
{
    bg = TextureManager::LoadTexture("assets/paused.png", Game::renderer);

}
void Pause::setBlendMode(SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode(bg, blending );
}
		
void Pause::render()
{
    //Making the pause screen translucent
    Uint8 alpha = 120;
    SDL_SetTextureAlphaMod(bg, alpha);
    SDL_SetTextureBlendMode(bg, SDL_BLENDMODE_BLEND);
    
    SDL_RenderCopy(Game::renderer, bg, NULL, NULL);
}


Pause::~Pause() {}