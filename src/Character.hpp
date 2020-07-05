#pragma once
#include "GameObject.hpp"
//#include "Location.hpp"
//#include "Weapon.hpp"
#include <iostream>
#include <vector>

class Character : public GameObject
{
protected:
    int health;
    int damage;
    float speed;
    //Weapon* m_weapon;
    //Location* m_location;
    bool isDead;
    int frame;
    std::string m_direction;
    int walking_frames;
    int att_frames;

    SDL_Rect init_rec;
    SDL_Rect *walking_down_arr;
    SDL_Rect *walking_up_arr;
    SDL_Rect *walking_left_arr;
    SDL_Rect *walking_right_arr;
    SDL_Rect *attack_arr;

    bool r_movable;
    bool l_movable;
    bool u_movable;
    bool d_movable;

public:
    Character(const char *);
    Character(const char *, std::string);
    virtual void movement() = 0;
    virtual void check_collision(std::vector<GameObject*>);
    virtual void set_direction(std::string);
    virtual void set_colliding(std::string) override;
    void update_location();

    virtual bool isAlive() override;
    virtual int get_hp() override;
    virtual void take_damage(int) override;
    virtual int get_damage() override;
    virtual void attack() = 0;
    virtual void dialogue() = 0;
    void die();
    virtual ~Character();
};