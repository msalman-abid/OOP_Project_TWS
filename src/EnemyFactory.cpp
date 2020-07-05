#include "EnemyFactory.hpp"
#include "Cafe2goBhai.hpp"
#include "rahimBhai.hpp"

GameObject *EnemyFactory::getEnemy(std::string enemy_type, int x, int y)
{
    GameObject *temp_enemy = nullptr;

    if (enemy_type == "Enemy1")
    {
        temp_enemy = new rahimBhai();
    }
    else if (enemy_type == "Enemy2")
    {
        temp_enemy = new Cafe2goBhai();
    }
    // else if (enemy_type == "Enemy3")
    // {
    //     temp_enemy = new Cafe2goBhai();
    // }
    else
    {
        std::cout << "Incorrect enemy type for factory" << std::endl;
        return temp_enemy;
    }

    temp_enemy->set_x(x);
    temp_enemy->set_y(y);

    return temp_enemy;
}