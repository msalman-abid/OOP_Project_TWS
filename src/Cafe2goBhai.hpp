#pragma once 
#include <iostream>
#include "Enemy.hpp"

class Cafe2goBhai: public Enemy 
{
    

    public:
        Cafe2goBhai();
        virtual void movement() override;
        virtual void attack() override;
        virtual void dialogue() override;
        ~Cafe2goBhai();
};