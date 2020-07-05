#pragma once
#include "Game.hpp"
#include <SDL_ttf.h>

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *filepath, SDL_Renderer *rend);
   static SDL_Texture* LoadtextureFromText (const char* textToRender, SDL_Color textColor, int textSize, SDL_Renderer* ren);
};