#include "Game.hpp"
#include <SDL.h>
#include <SDL_image.h>

Game *game = nullptr;
int main(int argc, const char *argv[])
{

    const int FPS = 60;
    const int framedelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = Game::get_instance();

    game->init("The Working Saturday", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running())
    {
        game->handleEvents();
        game->Update();
        game->render();

        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;

        if (framedelay > frameTime)
        {
            SDL_Delay(framedelay - frameTime);
        }
    }
    game->clean();


    SDL_DestroyWindow(game->getWindow());
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
    return 0;
}