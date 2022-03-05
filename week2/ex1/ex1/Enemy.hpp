//
//  Enemy.hpp
//  ex1
//
//  Created by Stefan Alexandru on 05.03.2022.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "EnemiesStructures.h"

class Enemy
{
private:
    Point location;
    int health;

public:
    void Init(Point intitialLocation, int initialHealh);
    void Move(EnemyDirection direction, int step);

    bool IsDead();//returns true is current health is lower or equal to 0
    void Shoot(int damage); //decrease the health by damage
};

#endif /* Enemy_hpp */
