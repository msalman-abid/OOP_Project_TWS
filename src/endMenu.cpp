#include "endMenu.hpp"

endMenu::endMenu() : GameObject("assets/end.png","screen")
{

};

endMenu::endMenu(const char* path) : GameObject(path, "screen")
{
   
};

void endMenu::render()
{
    GameObject::render();
    

}
void endMenu:: show_highscoreScreen()
{
    new_score = true;


}


bool endMenu::startAgain(){std::cout<<restart;return this->restart;}

void endMenu::set_score(int curr_score)
{
    m_score = curr_score;
}

void endMenu::Quit(){};
void endMenu::displayScore(){};
endMenu:: ~endMenu(){};