#pragma once
#include "door.hpp"
#include "GameObject.hpp"

class IngameScreen: public GameObject
{
    private:
    SDL_Texture* bg;
    std::vector<GameObject*> obj_vector;
    bool isActive;
    bool enemy_cleared;
    std::string screen_name;


    
    public:
        IngameScreen(const char*, GameObject*);
        GameObject* button_arr[4];
        void show_menu();
        void render();
        void handleObjectevents();
        void set_lvl_cleared(bool);
        bool lvl_cleared();
        std::vector<GameObject*> get_obj_vector();
        void set_obj_vector(std::vector<GameObject *>);
        void insert_obj(GameObject*);
        void set_active(bool);
        ~IngameScreen();
        std::string get_scr_name();
        void set_scr_name(std::string);

        friend std::ostream& operator << (std::ostream &, const IngameScreen &);
    
};

std::ostream& operator << (std::ostream &, const IngameScreen &);
