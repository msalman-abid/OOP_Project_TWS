#pragma once
#include <iostream>
#include "List.hpp"

class startMenu
{
    private:
        List* leaderboard;
        bool Continue;

    public:
        startMenu();
        List showLeaderboard();
        void Quit();
        void newGame();
        void continue_game();
        ~startMenu();

    
};
