#pragma once 
#include <iostream>
#include "Enemy.hpp"

class rahimBhai: public Enemy 
{
    

    public:
        rahimBhai();
        virtual void movement() override;
        virtual void attack() override;
        virtual void dialogue() override;
        ~rahimBhai();
};