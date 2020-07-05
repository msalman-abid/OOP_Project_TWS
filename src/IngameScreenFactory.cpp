#include "IngameScreenFactory.hpp"

IngameScreen *IngameScreenFactory::get_screen(std::string scr_type, GameObject *player)
{
    IngameScreen *temp_screen = nullptr;
    GameObject *temp_object = nullptr;

    if (scr_type == "centralstreet")
    {
        GameObject *medical_mat = new GameObject("assets/medical_mat.png", "medical");
        //creating a door
        SDL_Rect r1 = {0, 0, 136, 299}; //setting door source and dest rects
        SDL_Rect r2 = {689, 224, 111, 300};
        temp_object = new door("assets/stairs.png", r1, r2, "firecourtyard");

        temp_screen = new IngameScreen("assets/centralstreet.png", player);
        temp_screen->insert_obj(temp_object);
        temp_screen->insert_obj(medical_mat);

        //setting enemy and player for this screen
        player->set_x(70);
        player->set_y(300);
        temp_screen->insert_obj(player);
        temp_screen->insert_obj(EnemyFactory::getEnemy("Enemy1", 400, 500));
        temp_screen->insert_obj(EnemyFactory::getEnemy("Enemy1", 600, 200));
    }

    else if (scr_type == "firecourtyard")
    {
        SDL_Rect r1 = {0, 0, 136, 299}; //setting door source and dest rects
        SDL_Rect r2 = {0, 191, 50, 141};
        temp_object = new door("assets/stairs.png", r1, r2, "centralstreet");

        temp_screen = new IngameScreen("assets/courtyard.png", player);
        temp_screen->insert_obj(temp_object);

        player->set_x(70);
        player->set_y(300);
        temp_screen->insert_obj(player);
        temp_screen->insert_obj(EnemyFactory::getEnemy("Enemy2", 400, 500));
        std::cout<<"enemy1"<<std::endl;
        temp_screen->insert_obj(EnemyFactory::getEnemy("Enemy2", 600, 200));
        std::cout<<"enemy1"<<std::endl;
        temp_screen->insert_obj(EnemyFactory::getEnemy("Enemy2", 500, 500));
        std::cout<<"enemy1"<<std::endl;

        temp_screen->insert_obj(EnemyFactory::getEnemy("Enemy2", 700, 200));
        std::cout<<"enemy1"<<std::endl;
    }

    else
    {
        std::cout << "Incorrect screen type for factory" << std::endl;
        return temp_screen;
    }

    temp_object = nullptr;
    temp_screen->set_scr_name(scr_type);

    return temp_screen;
}