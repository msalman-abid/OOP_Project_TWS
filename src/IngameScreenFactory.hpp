#pragma once 
#include <iostream>
#include "IngameScreen.hpp"
#include "EnemyFactory.hpp"

class IngameScreenFactory
{
    private:
    IngameScreenFactory();


    public:
        static IngameScreen* get_screen(std::string, GameObject*);
        ~IngameScreenFactory();

};