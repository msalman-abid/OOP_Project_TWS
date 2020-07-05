#include "IngameScreen.hpp"

IngameScreen::IngameScreen(const char *filepath, GameObject *player) : GameObject(filepath, "screen")
{
    isActive = false;
    screen_name = "";
    enemy_cleared = false;
}

void IngameScreen::render()
{
    if (isActive)
    {
        GameObject::render();
    }
}

void IngameScreen::insert_obj(GameObject *obj)
{
    obj_vector.push_back(obj);
}

std::vector<GameObject *> IngameScreen::get_obj_vector()
{
    return obj_vector;
}

void IngameScreen::set_obj_vector(std::vector<GameObject *> vect)
{
    obj_vector = vect;
}

void IngameScreen::set_active(bool active)
{
    this->isActive = active;
}
void IngameScreen::handleObjectevents()
{
}

void IngameScreen::set_lvl_cleared(bool value)
{
    enemy_cleared = false;
}

bool IngameScreen::lvl_cleared()
{
    return enemy_cleared;
}

void IngameScreen::set_scr_name(std::string new_name)
{
    screen_name = new_name;
}

std::string IngameScreen::get_scr_name()
{
    return screen_name;
}

std::ostream &operator<<(std::ostream &out, const IngameScreen &screen)
{
    out << screen.screen_name << std::endl;
    return out;
}

IngameScreen::~IngameScreen()
{
    std::vector<GameObject *>::iterator itr;
    GameObject *temp1;

    for (itr = this->obj_vector.begin(); itr < this->obj_vector.end(); itr++)
    {
        std::cout << "deconstructing screen " << *this << std::endl;
        temp1 = *itr;

        if (temp1)
        {

            if (temp1->get_type() == "player")
            {
                continue;
            }
            delete temp1;
            temp1 = nullptr;
        }
    }
}