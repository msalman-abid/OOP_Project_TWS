#pragma once
#include "Game.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <fstream>

class GameObject
{
protected:
    float x_pos;
    float y_pos;
    bool attacking;
    std::string obj_type;

    SDL_Texture *obj_tex;
    SDL_Rect src_rec, dest_rec;

public:
    GameObject();
    GameObject(const char *);
    GameObject(const char *, std::string);
    GameObject(const char *, SDL_Rect, SDL_Rect);
    GameObject(const char *, SDL_Rect, SDL_Rect, std::string);

    //methods for character (player and enemy both)
    virtual void set_colliding(bool);
    virtual void set_colliding(std::string);
    virtual void movement();
    virtual void set_direction(std::string);
    virtual void check_collision(std::vector<GameObject *>) {}

    virtual void attack(){};
    virtual void setAttacking(bool);
    virtual bool isAlive() { return false; }
    virtual void take_damage(int) {}
    virtual int get_damage() { return 0; }

    virtual ~GameObject();

    virtual bool isAttacking();
    virtual std::string get_type();
    
    //score updation methods
    //virtual int& get_currentscore();
    //virtual int get_previous_score();
    virtual int show_highscore(std::string filename);
    virtual void update_highscore(std::string filename);

    //methods common to every GameObject in the game
    virtual void update();
    virtual void render();
    SDL_Rect *get_Rect();
    void set_x(int);
    void set_y(int);

    //methods for doors/stairs
    virtual bool isOpen() { return false; }
    virtual std::string door_getnext() { return ""; }

    void set_hp_bar(int, int);
    virtual int get_hp() { return 0; }
};