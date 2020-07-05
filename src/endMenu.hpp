#pragma once 
#include <iostream>
#include <time.h>
#include "GameObject.hpp"

class endMenu: public GameObject
{
    private:
        int m_score;
        time_t  m_time;
        bool restart;
        bool new_score;

    public:
        endMenu();
        endMenu(const char*);
        GameObject* button;
        void render();
       
        void set_score(int);
        bool startAgain();
        void show_highscoreScreen();
        void Quit();
        void displayScore();
        ~endMenu();


};