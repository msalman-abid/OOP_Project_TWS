#pragma once 
#include <iostream>
#include "Enemy.hpp"

class EnemyFactory
{
    private:
    EnemyFactory();


    public:
        static GameObject* getEnemy(std::string, int, int);
        ~EnemyFactory();

};