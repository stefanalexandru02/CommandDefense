//
//  EnemyStructure.hpp
//  ex1
//
//  Created by Stefan Alexandru on 05.03.2022.
//

#ifndef EnemyStructure_hpp
#define EnemyStructure_hpp

#include <stdio.h>

struct Point
{
    int x, y;
};

enum class EnemyDirection
{
    UpDirection,//decrease y by step
    DownDirection,//increase y by step
    LeftDirection, // decrease x by step
    RightDirection // increase x by step
};

#endif /* EnemyStructure_hpp */
