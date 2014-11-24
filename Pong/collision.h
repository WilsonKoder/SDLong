//
//  collision.h
//  Pong
//
//  Created by Wilson Koder on 24/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#ifndef __Pong__collision__
#define __Pong__collision__

#include <stdio.h>
#include <SDL2/SDL.h>

class collision {
public:
    bool checkCollision(SDL_Rect a, SDL_Rect b);
};

#endif /* defined(__Pong__collision__) */
