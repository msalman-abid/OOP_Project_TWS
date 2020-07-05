#include "door.hpp"

door::door(const char *filepath, std::string next) 
    : GameObject(filepath, "door")
{
    open = true;
    next_screen = next;
}

door::door(const char *filepath, SDL_Rect a1, SDL_Rect a2, std::string next)
    : GameObject(filepath, a1, a2, "door")
{
    open = true;
    next_screen = next;
}

bool door::isOpen()
{
    return open;
}

std::string door::door_getnext()
{
    return next_screen;
}


door::~door()
{
}

