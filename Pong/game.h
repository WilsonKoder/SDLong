//
//  game.h
//  Pong
//
//  Created by Wilson Koder on 23/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#ifndef __Pong__game__
#define __Pong__game__

#include <stdio.h>
#include <SDL2/SDL.h>

class Game {
    
public:
    SDL_Window *g_pWindow = 0;
    SDL_Renderer *g_pRenderer = 0;
    
    bool init(int resx, int resy, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    bool isRunning();
    void clean();
    void reset();
private:
    bool running;
};


#endif /* defined(__Pong__game__) */
