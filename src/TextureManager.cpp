#include "TextureManager.hpp"


SDL_Texture *TextureManager::LoadTexture(const char *texture, SDL_Renderer *rend)
{
    SDL_Surface *tempsurf = IMG_Load(texture);
    SDL_Texture *new_tex = SDL_CreateTextureFromSurface(rend, tempsurf);
    SDL_FreeSurface(tempsurf);

    tempsurf = nullptr;

    return new_tex;
}
SDL_Texture* TextureManager::LoadtextureFromText(const char* textToRender, SDL_Color textColor, int textSize, SDL_Renderer* ren){
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    }

    TTF_Font *font = TTF_OpenFont( "assets/new.ttf", textSize );
    SDL_Surface *tempTextSurface = TTF_RenderText_Solid( font, textToRender, textColor );
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren,tempTextSurface);
    SDL_FreeSurface(tempTextSurface);
    //TTF_CloseFont(font);
    //TTF_Quit();
    return tex;
}