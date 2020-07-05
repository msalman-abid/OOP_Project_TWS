#include "startScreen.hpp"

startScreen::startScreen() : GameObject("assets/button.png")
{
    inscreen = nullptr;
    quitgame = false;
    bg = TextureManager::LoadTexture("assets/startscreen.png", Game::renderer);

    SDL_Rect b1_src = {0, 0, 875, 335};
    SDL_Rect b3_src = {0, 1000, 875, 335};

    SDL_Rect b1_des = {570, 250, 140, 60};
    SDL_Rect b3_des = {570, 355, 140, 60};

    button_arr[0] = new GameObject("assets/button.png", b1_src, b1_des); //newgame button
    button_arr[1] = new GameObject("assets/button.png", b3_src, b3_des); //quit button
}

void startScreen::render()
{

    SDL_RenderCopy(Game::renderer, bg, NULL, NULL);
    for (int i = 0; i < 2; i++)
    {
        button_arr[i]->render();
    }
}
void startScreen::handleObjectevents(SDL_Event event)
{
    switch (event.type)
    {
    case SDL_MOUSEBUTTONUP:
        //If the left mouse button was pressed
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            //Get the mouse offsets
            int x = event.button.x;
            int y = event.button.y;

            //If the mouse is over the newgame button
            if ((x > button_arr[0]->get_Rect()->x) &&
                (x < button_arr[0]->get_Rect()->x + button_arr[0]->get_Rect()->w) &&
                (y > button_arr[0]->get_Rect()->y) &&
                (y < button_arr[0]->get_Rect()->y + button_arr[0]->get_Rect()->h))
            {
                std::cout << "Ingame open" << std::endl;
                ingame = true;
                
            }
            //If the mouse is over the quit button
            else if ((x > button_arr[1]->get_Rect()->x) &&
                     (x < button_arr[1]->get_Rect()->x + button_arr[1]->get_Rect()->w) &&
                     (y > button_arr[1]->get_Rect()->y) &&
                     (y < button_arr[1]->get_Rect()->y + button_arr[1]->get_Rect()->h))
            {
                std::cout << "quit game" << std::endl;
                quitgame = true;
            }
        }
    default:
        break;
    }
}

bool startScreen::get_next_screen()
{
    return ingame;
}

bool startScreen::check_quit()
{
    return quitgame;
}
void startScreen:: set_screen(bool t_f)
{
    ingame = t_f;
}

startScreen::~startScreen() {}