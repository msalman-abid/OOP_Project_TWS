#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.hpp"

class Game
{
private:
    bool isRunning;
    static SDL_Event event;
    SDL_Window *window;
    SDL_Rect dataRectangle;
    static Game* instance;
    Game();


public:
    SDL_Texture *texture;
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void Update();
    void render();
    void clean();
    SDL_Window* getWindow();
    bool running();
    ~Game();
    static int inst_count;
    
    static Game* get_instance();
    static SDL_bool check_intersection(SDL_Rect *, SDL_Rect *);

    
    static SDL_Renderer *renderer;
};