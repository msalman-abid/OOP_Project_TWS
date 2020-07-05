#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(){}
GameObject::GameObject(const char *tex_sheet) : x_pos(0), y_pos(0), obj_type("")
{
    obj_tex = TextureManager::LoadTexture(tex_sheet, Game::renderer);
}

GameObject::GameObject(const char *tex_sheet, std::string typ)
    : x_pos(0), y_pos(0), obj_type(typ)
{
    if (typ == "hpbar")
    {
        src_rec = {0, 0, 103, 13};
        dest_rec = {25, 10, 103, 13};
    }
    if (typ == "medical")
    {
        src_rec = {0, 0, 64, 32};
        dest_rec = {305, 560, 96, 48};
    }

    obj_tex = TextureManager::LoadTexture(tex_sheet, Game::renderer);
}

GameObject::GameObject(const char *tex_sheet, SDL_Rect a, SDL_Rect b) : x_pos(0), y_pos(0), obj_type("")
{
    obj_tex = TextureManager::LoadTexture(tex_sheet, Game::renderer);
    src_rec = a;
    dest_rec = b;
}

GameObject::GameObject(const char *tex_sheet, SDL_Rect a, SDL_Rect b, std::string typ) : x_pos(0), y_pos(0), obj_type(typ)
{
    obj_tex = TextureManager::LoadTexture(tex_sheet, Game::renderer);
    src_rec = a;
    dest_rec = b;
}

void GameObject::update()
{
}

void GameObject::movement(){};
void GameObject::set_colliding(bool) {}
void GameObject::set_colliding(std::string) {}

void GameObject::set_direction(std::string) {}

void GameObject::setAttacking(bool state)
{
    attacking = state;
}

bool GameObject::isAttacking()
{
    return attacking;
}

SDL_Rect *GameObject::get_Rect()
{
    return &dest_rec;
}

std::string GameObject::get_type()
{
    return obj_type;
}

void GameObject::render()
{
    if (obj_type == "screen")
    {
        SDL_RenderCopy(Game::renderer, obj_tex, NULL, NULL);
       
        return;
    }

    SDL_RenderCopy(Game::renderer, obj_tex, &src_rec, &dest_rec);
    
}
//int &GameObject::get_currentscore()
//{
//}

//int GameObject::get_previous_score()
//{
//}
int GameObject::show_highscore(std::string filename)
{
    return 0;
}

void GameObject::update_highscore(std::string filename)
{
}

void GameObject::set_x(int x)
{
    x_pos = x;
}

void GameObject::set_y(int y)
{
    y_pos = y;
}

void GameObject::set_hp_bar(int hp, int totalhp)
{
    int hp_pc = (hp * 100 / totalhp);

    src_rec.w = 103 * hp_pc / 100;
    dest_rec.w = src_rec.w;
}

GameObject::~GameObject() {}
