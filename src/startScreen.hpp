#pragma once
#include "GameObject.hpp"
#include "IngameScreen.hpp"
#include "TextureManager.hpp"

class startScreen: public GameObject
{
    private:
    SDL_Texture* bg;
    bool ingame;
    bool quitgame;
    IngameScreen* inscreen;

    public:
        startScreen();
        GameObject* button_arr[2];
        void show_menu();
        void render() override;
        void handleObjectevents(SDL_Event);
        bool get_next_screen();
        void set_screen(bool t_f);
        bool check_quit();
        ~startScreen();

    
};
