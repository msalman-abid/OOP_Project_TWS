#include "Enemy.hpp"

Enemy::Enemy(const char *enemy_image) : Character(enemy_image, "enemy")
{
    damage = 1;
}

void Enemy::set_colliding(bool val)
{
    colliding = val;
}

Enemy::~Enemy()
{
}
void Enemy:: render()
{
    GameObject::render();
}