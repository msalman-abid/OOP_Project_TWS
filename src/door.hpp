#pragma once
#include <iostream>
#include "GameObject.hpp"
#include <string>

class door : public GameObject
{
private:
    bool open;
    std::string next_screen;

public:
    door(const char*, std::string);
    door(const char*, SDL_Rect, SDL_Rect, std::string);
    virtual bool isOpen() override;
    virtual std::string door_getnext();
    ~door();
};
