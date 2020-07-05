#include "Game.hpp"
#include "EnemyFactory.hpp"
#include "IngameScreenFactory.hpp"
#include "Enemy.hpp"
#include "rahimBhai.hpp"
#include "GameObject.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "startScreen.hpp"
#include "IngameScreen.hpp"
#include "endMenu.hpp"
#include <sstream>
#include "Pause.hpp"
#include <vector>

Game* Game::instance = new Game();


bool main_screen = true;
bool ingame = false;
bool endgame = false;
bool switch_flag = false;
bool first_cleared = false;
bool second_cleared = false;
bool pause = false;
bool scoreCheck = false;
Uint32 time_;

std::string next_location = "";
std::ostringstream score_stream;
std::ostringstream time_stream;

Player *player;
GameObject *hp_bar;

startScreen *start_screen = nullptr;
IngameScreen *ingame_screen = nullptr;
endMenu *endgame_screen = nullptr;
endMenu *wingame_screen = nullptr;
Pause *pause_screen = nullptr;

std::vector<IngameScreen *> screens_vector;
std::vector<GameObject *> obj_vector;
std::vector<GameObject *> delete_vec;

std::vector<GameObject *>::iterator it1;
std::vector<IngameScreen *>::iterator screen_itr;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

int Game::inst_count = 0;


SDL_Color textColor;

Game::Game()
{
    inst_count += 1;
    // texture = nullptr;
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width,
                int height, bool fullscreen)

{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "renderer created" << std::endl;
            isRunning = true;
        }

        else
        {
            isRunning = false;
        }

        

        endgame_screen = new endMenu();
        wingame_screen = new endMenu("assets/w1.png");
        start_screen = new startScreen();
        player = new Player;
        hp_bar = new GameObject("assets/healthbar.png", "hpbar");
        pause_screen = new Pause();

        screens_vector.push_back(IngameScreenFactory::get_screen("centralstreet", player));
        screens_vector.push_back(IngameScreenFactory::get_screen("firecourtyard", player));
    }
}
void Game::handleEvents()
{

    SDL_PollEvent(&event);

    if (start_screen)
    {
        start_screen->handleObjectevents(event);
        if (start_screen->check_quit())
        {
            isRunning = false;
        }

        //Going ingame after pressing new game
        if (start_screen->get_next_screen())
        {
            ingame_screen = screens_vector.at(0);
            ingame_screen->set_active(true);
            obj_vector = ingame_screen->get_obj_vector();
            std::cout << ingame_screen;
            main_screen = false;
            ingame = true;
            delete start_screen;
            start_screen = nullptr;
        }
    }
   

    switch (event.type)
    {
    case SDL_QUIT:
        ingame = false;
        isRunning = false;
        break;
    case SDL_KEYDOWN:

        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            player->set_direction("up");
            break;
        case SDLK_RIGHT:
            player->set_direction("right");
            break;
        case SDLK_LEFT:
            player->set_direction("left");
            break;
        case SDLK_DOWN:
            player->set_direction("down");
            break;
        case SDLK_a:
            player->setAttacking(true);
            break;
        case SDLK_p:
            pause = !pause;
            break;
        default:
            player->set_direction("static");
            break;
        }

        break;
    case SDL_KEYUP:
        player->set_direction("static");
        break;
    default:
        break;
    }
}
void Game::Update()
{

    if (pause)
    {
        return;
    }

    if (!ingame)
    {
        return;
    }

    int count(0);
    GameObject *current_obj(nullptr);
    GameObject *deletable(nullptr);

    //check player attack state
    player->attack();

    if (!player->isAttacking())
    {
        //check player collision with environment
        player->check_collision(obj_vector);
        player->movement();
    }

    //check interaction with enemy objects
    if (obj_vector.size() > 0)
    {
        ingame_screen->set_lvl_cleared(true);

        if (ingame_screen->get_scr_name() == "centralstreet")
        {
            first_cleared = true; //if enemies in 1st screen killed
        }
        else if (ingame_screen->get_scr_name() == "firecourtyard")
        {
            second_cleared = true; //if enemies in 2nd screen killed
        }

        for (it1 = obj_vector.begin(); it1 < obj_vector.end();
             it1++, count++)
        {
            current_obj = *it1;
            if (current_obj->get_type() == "enemy")
            {
                ingame_screen->set_lvl_cleared(false);

                if (ingame_screen->get_scr_name() == "centralstreet")
                {
                    first_cleared = false; //reset if enemies present
                }
                else if (ingame_screen->get_scr_name() == "firecourtyard")
                {
                    second_cleared = false;
                }

                current_obj->movement();

                if (check_intersection(player->get_Rect(), current_obj->get_Rect()))
                {
                    //enemy interaction with player when colliding
                    current_obj->set_colliding(true);
                    player->take_damage(current_obj->get_damage());

                    hp_bar->set_hp_bar(player->get_hp(), 100);
                    if (player->isAttacking())
                    {
                        current_obj->take_damage(player->get_damage());
                    }
                }
                else
                {
                    current_obj->set_colliding(false);
                }

                if (!current_obj->isAlive())
                {
                    //sending killed enemies to garbage collection
                    std::cout << "erasing " + current_obj->get_type() << std::endl;

                    delete_vec.push_back(current_obj);
                    obj_vector.erase(obj_vector.begin() + count);
                    player->get_currentscore() += 1;
                    std::cout << "Your current score is: " << player->get_currentscore() << std::endl;
                }
            }

            if (current_obj->get_type() == "door" and
                check_intersection(player->get_Rect(), current_obj->get_Rect()))
            {

                next_location = current_obj->door_getnext();
                switch_flag = true;
            }

            if (current_obj->get_type() == "medical" and
                check_intersection(player->get_Rect(), current_obj->get_Rect()))
            {
                player->take_damage(-5);
                hp_bar->set_hp_bar(player->get_hp(), 100);
            }
        }
    }

    //switching screens upon colliding with door
    if (switch_flag)
    {
        IngameScreen *temp_screen(nullptr);
        count = 0;

        for (screen_itr = screens_vector.begin(); screen_itr < screens_vector.end();
             screen_itr++, count++)
        {
            temp_screen = *screen_itr;

            if (temp_screen->get_scr_name() == next_location)
            {
                temp_screen->set_active(true);
                ingame_screen->set_active(false);
                ingame_screen->set_obj_vector(obj_vector); //saving current obj container
                ingame_screen = temp_screen;               // to screen's container

                obj_vector = ingame_screen->get_obj_vector(); //loading next screen's obj container
                //std::cout << *ingame_screen;

                player->set_x(80);
                player->set_y(300);
                if (ingame_screen->get_scr_name() == "centralstreet")
                {
                    player->set_x(620);
                }

                break;
            }
        }
        switch_flag = false;
        next_location = "";
    }

    if (!player->isAlive())
    {
        endgame = true;
        ingame = false;
        endgame_screen->set_score(player->get_currentscore());
        if (player->get_previous_score() < player->get_currentscore())
        {
            scoreCheck = true;
            player->update_highscore("src/scorefile.txt");
        }
    }
    ingame_screen->set_obj_vector(obj_vector);
}
void Game::render()
{
    GameObject *current_obj;
    SDL_RenderClear(renderer);

    //this is where stuff will be added to render

    if (start_screen)
    {
        textColor = {255, 255, 255};
        start_screen->render();
        dataRectangle.x = 0;
        dataRectangle.y = 550;
        dataRectangle.h = 30;
        dataRectangle.w = 600;
        {
            std:: ostringstream oss;
            oss << "High Score you need to beat is " << player->show_highscore("scorefile.txt");
            texture = TextureManager::LoadtextureFromText(oss.str().c_str(), textColor, 12, renderer);

            SDL_RenderCopy(renderer, texture, NULL, &dataRectangle);
            SDL_DestroyTexture(texture);
        }
    }

    else if (endgame or (first_cleared and second_cleared))
    {
        if (player->get_previous_score() < player->get_currentscore())
        {
            wingame_screen->set_score(player->get_currentscore());
            wingame_screen->render();
        }
        else
        {
            endgame_screen->set_score(player->get_currentscore());
            endgame_screen->render();
        }
        textColor = {0, 0, 0};

        dataRectangle.x = 450;
        dataRectangle.y = 450
        ;
        dataRectangle.h = 30;
        dataRectangle.w = 30;
        {
            std::ostringstream oss;

        oss << player->get_currentscore();
        texture = TextureManager::LoadtextureFromText(oss.str().c_str(), textColor, 12, renderer);

        SDL_RenderCopy(renderer, texture, NULL, &dataRectangle);
        SDL_DestroyTexture(texture);

        }

        
        

      
    }
    else
    {

        ingame_screen->render();

        if (pause)
        {
            pause_screen->render();
        }

        hp_bar->render();

        for (it1 = obj_vector.begin(); it1 < obj_vector.end(); it1++)
        {
            current_obj = *it1;
            current_obj->render();
        }

    
    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{

    for (it1 = delete_vec.begin(); it1 < delete_vec.end(); it1++)
    {
        std::cout << "deleting enemy" << std::endl;
        delete *it1;
        *it1 = nullptr;
    }

    for (screen_itr = screens_vector.begin(); screen_itr < screens_vector.end(); screen_itr++)
    {
        std::cout << "deleting screen" << std::endl;
        delete *screen_itr;
        *screen_itr = nullptr;
    }

    delete player;
    player = nullptr;

    std::cout << "game cleaning" << std::endl;
}

SDL_Window *Game::getWindow()
{
    return this->window;
}
bool Game::running()
{
    return isRunning;
}

SDL_bool Game::check_intersection(SDL_Rect *r1, SDL_Rect *r2)
{
    return SDL_HasIntersection(r1, r2);
}

Game* Game::get_instance()
{
    return instance;
}

