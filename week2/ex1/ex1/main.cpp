#include <iostream>
#include "EnemyController.hpp"

struct Point{
    int x;
    int y;
};

int main()
{
    Point initialLocation;
    initialLocation.x = 10;
    initialLocation.y = 10;

    EnemyController controller;
    controller.Init(10, 2, initialLocation);

    controller.Move();

    for (int i = 0; i < 5; i++)
        controller.SpawnEnemy();

    controller.DamageAll();
    controller.DamageAll();
    controller.DamageAll();

    int killed = controller.CountKilledEnemies();
    std::cout << "Killed :" << killed << " enemies" << std::endl;

    controller.Uninit();

    return 0;
}
