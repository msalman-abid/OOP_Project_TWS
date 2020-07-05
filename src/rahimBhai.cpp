#include "rahimBhai.hpp"

rahimBhai::rahimBhai() : Enemy("assets/enemy1.png")
{
    health = 1000;
    x_pos = 500;
    y_pos = 500;
    walking_frames = 9;
    speed = 5;
    m_direction = "down";

    //creating animation arrays
    walking_down_arr = new SDL_Rect[walking_frames];
    walking_up_arr = new SDL_Rect[walking_frames];
    walking_left_arr = new SDL_Rect[walking_frames];
    walking_right_arr = new SDL_Rect[walking_frames];

    //set player frames
    for (int i = 0; i < walking_frames; i++)
    {
        //initializing arrays to hold animation frames
        walking_down_arr[i].x = 0 + i * 64;
        walking_down_arr[i].y = 650;
        walking_down_arr[i].w = 63;
        walking_down_arr[i].h = 60;

        walking_up_arr[i].x = 0 + i * 64;
        walking_up_arr[i].y = 520;
        walking_up_arr[i].w = 63;
        walking_up_arr[i].h = 60;

        walking_left_arr[i].x = 0 + i * 64;
        walking_left_arr[i].y = 580;
        walking_left_arr[i].w = 63;
        walking_left_arr[i].h = 60;

        walking_right_arr[i].x = 0 + i * 64;
        walking_right_arr[i].y = 710;
        walking_right_arr[i].w = 63;
        walking_right_arr[i].h = 60;
    }

    //default static animation
    init_rec = {0, 650, 64, 60};
    src_rec = init_rec;
    dest_rec.w = src_rec.w;
    dest_rec.h = src_rec.h;
    dest_rec.x = x_pos;
    dest_rec.y = y_pos;

    // this->src_rec = player_src;
    // this->dest_rec = player_dest;
    speed = 3.5;
}

void rahimBhai::movement()
{
    if (isDead)
    {
        return;
    }

    // if (colliding)
    // {
    //     speed = 0.5;
    // }
    // else
    // {
    //     speed = 5;
    // }

    if (m_direction == "up")
    {
        y_pos -= speed;
        Character::update_location();
    }
    else if (m_direction == "down")
    {
        y_pos += speed;
        Character::update_location();
    }

    if (y_pos <= 0)
    {
        m_direction = "down";
    }
    else if (y_pos >= 540)
    {
        m_direction = "up";
    }
}

void rahimBhai::attack() {}

void rahimBhai::dialogue() {}

rahimBhai::~rahimBhai() {}