//
//  ballMovement.cpp
//  Pong
//
//  Created by Wilson Koder on 23/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include "ballMovement.h"
#include <random>

int ballMovement::xMovement()
{
    int movement = rand() % 19 + (-9);
    if (movement == 0)
    {
        movement = rand() % 19 + (-9);
    }
    return movement;
}

int ballMovement::yMovement()
{
    int movement = rand() % 19 + (-9);
    if (movement == 0)
    {
        movement = rand() % 19 + (-9);
    }
    return movement;
}