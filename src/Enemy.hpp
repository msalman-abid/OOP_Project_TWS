#pragma once
#include <iostream>
#include "Character.hpp"

class Enemy : public Character
{
protected:
bool colliding;

public:
    Enemy(const char *);
    virtual void movement() = 0;
    virtual void attack() = 0;
    virtual void dialogue() = 0;
    virtual ~Enemy();
    virtual void set_colliding(bool);
    void render();


};