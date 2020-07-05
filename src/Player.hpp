#pragma once
#include <iostream>
#include "Character.hpp"
#include <fstream>

class Player : public Character
{
private:
    int weight;
    int state;
    int frame;
    
    static int obj_count;
    int current_score = 0;
    int previous_score;
    std::fstream fio;

public:
    Player();
    virtual void movement() override;
    virtual void dialogue() override;
    virtual void attack() override;
    virtual void get_state();
    int& get_currentscore();
    int get_previous_score();
    virtual int show_highscore(std::string filename) override;
    virtual void update_highscore(std::string filename) override;
    ~Player();
};
