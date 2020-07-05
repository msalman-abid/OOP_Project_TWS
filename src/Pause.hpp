#pragma once
#include "GameObject.hpp"

class Pause: public GameObject
{
    private:
    SDL_Texture* bg;
    void setBlendMode( SDL_BlendMode blending );

    public:
        Pause();
        void render() override;
        ~Pause();

    
};
