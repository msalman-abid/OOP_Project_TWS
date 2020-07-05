#include "Character.hpp"

Character::Character(const char *filepath)
    : GameObject(filepath)
{
    isDead = false;
    frame = 0;
    r_movable = true;
    l_movable = true;
    u_movable = true;
    d_movable = true;
}

Character::Character(const char *filepath, std::string typ)
    : GameObject(filepath, typ)
{
    isDead = false;
    frame = 0;
    r_movable = true;
    l_movable = true;
    u_movable = true;
    d_movable = true;
}

void Character::set_direction(std::string dir)
{
    m_direction = dir;
}

void Character::check_collision(std::vector<GameObject *> game_vec)
{
    //checks collision against object being rendered and flags player accordingly
    GameObject *tempobj = nullptr;

    //create temporary SDL_Rects to check collisions in each direction
    SDL_Rect *temp_rect, *player_rect, *t1, *t2, *t3, *t4;
    SDL_Rect chk_left, chk_right, chk_up, chk_down;

    player_rect = &dest_rec;

    chk_left = dest_rec;
    chk_left.h *= 0.7;
    chk_left.w *= 0.7;
    chk_left.x--;
    t1 = &chk_left;

    chk_right = dest_rec;
    chk_right.h *= 0.7;
    chk_right.w *= 0.7;
    chk_right.x++;
    t2 = &chk_right;

    chk_up = dest_rec;
    chk_up.h *= 0.7;
    chk_up.w *= 0.7;
    chk_up.y--;
    t3 = &chk_up;

    chk_down = dest_rec;
    chk_down.h *= 0.7;
    chk_down.w *= 0.7;
    chk_down.y++;
    t4 = &chk_down;

    std::vector<GameObject *>::iterator itr;

    //iterate over collidable game objects
    for (itr = game_vec.begin(); itr < game_vec.end(); itr++)
    {
        tempobj = *itr;
        temp_rect = tempobj->get_Rect();

        //set initial colliding to false for player
        set_colliding("!left");
        set_colliding("!right");
        set_colliding("!up");
        set_colliding("!down");

        if (tempobj == this)
        {
            continue;
        }
        //set player collision flags for each direction
        else
        {
            //check if any side collides
            if (SDL_HasIntersection(t1, temp_rect))
            {
                set_colliding("left");
            }
            if (SDL_HasIntersection(t2, temp_rect))
            {
                this->set_colliding("right");
            }
            if (SDL_HasIntersection(t3, temp_rect))
            {
                this->set_colliding("up");
            }
            if (SDL_HasIntersection(t4, temp_rect))
            {
                this->set_colliding("down");
            }
        }
    }
}

void Character::update_location()
{
    //loop to determine which frame to be drawn
    //eg. frame 0 to be drawn until frame value increments till 8
    frame++;
    if (frame / walking_frames >= walking_frames)
    {
        frame = 0;
    }

    if (m_direction == "down")
    {
        src_rec = walking_down_arr[frame / walking_frames];
    }
    else if (m_direction == "up")
    {
        src_rec = walking_up_arr[frame / walking_frames];
    }
    else if (m_direction == "left")
    {
        src_rec = walking_left_arr[frame / walking_frames];
    }
    else if (m_direction == "right")
    {
        src_rec = walking_right_arr[frame / walking_frames];
    }
    else
    {
        src_rec = init_rec;
        frame = 0;
    }

    //checking if character exceeds boundaries of window
    if (x_pos < 0)
    {
        x_pos = 0;
    }
    else if (x_pos > 730)
    {
        x_pos = 730;
    }

    if (y_pos < 0)
    {
        y_pos = 0;
    }
    else if (y_pos > 540)
    {
        y_pos = 540;
    }

    dest_rec.x = x_pos;
    dest_rec.y = y_pos;
}

void Character::set_colliding(std::string dir)
{
    //sets flags to disallow movement in a direction
    if (dir == "left")
    {
        l_movable = false;
    }
    else if (dir == "right")
    {
        r_movable = false;
    }
    else if (dir == "up")
    {
        u_movable = false;
    }
    else if (dir == "down")
    {
        d_movable = false;
    }

    else
    {
        //removing player flags to allow movement
        if (dir == "!left")
        {
            l_movable = true;
        }
        if (dir == "!right")
        {
            r_movable = true;
        }
        if (dir == "!up")
        {
            u_movable = true;
        }
        if (dir == "!down")
        {
            d_movable = true;
        }
    }
}

void Character::die() {}

void Character::take_damage(int dmg)
{
    if (health > 0)
    {
        health -= dmg;
    }
    else
    {
        isDead = true;
    }

    if (health > 100)
    {
        health = 100;
    }
}

int Character::get_damage()
{
    return damage;
}

bool Character::isAlive()
{
    return !isDead;
}

int Character::get_hp()
{
    return health;
}

Character::~Character()
{
    delete walking_down_arr;
    delete walking_up_arr;
    delete walking_right_arr;
    delete walking_left_arr;
}
