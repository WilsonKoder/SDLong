//
//  game.cpp
//  Pong
//
//  Created by Wilson Koder on 23/11/14.
//  Copyright (c) 2014 ;. All rights reserved.
//

#include "game.h"
#include "textureManager.h"
#include "ballMovement.h"
#include "collision.h"
#include <iostream>

// g prefix because they are global variables

TextureManager* tm = 0;
collision* col = 0;
SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;
bool running = false;

bool p1MoveUp = false;
bool p1MoveDown = false;
bool p2MoveUp = false;
bool p2MoveDown = false;

int p1YPos = 300;
int p2YPos = 300;

int ballX = 400;
int ballY = 300;
int ballMoveX = 0;
int ballMoveY = 0;
ballMovement* bm = new ballMovement();

SDL_Rect ballRect;
SDL_Rect player1Rect;
SDL_Rect player2Rect;

bool Game::init(int resx, int resy, bool fullscreen)
{
    tm = new TextureManager();
    col = new collision();
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        g_pWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resx, resy, flags);
        
        if(g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
            
            if(g_pRenderer != 0)
            {
                running = true;
                
                tm->load("Images/bg.png", "bg", g_pRenderer);
                tm->load("Images/paddle.png", "player1", g_pRenderer);
                tm->load("Images/paddle.png", "player2", g_pRenderer);
                tm->load("Images/ball.png", "ball", g_pRenderer);
                
                reset();
                
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
    return false;
}

void Game::handleEvents()
{
    SDL_Event event;
    
    // Poll events until the queue is empty...
    while(SDL_PollEvent(&event)) {
        
        // ...then check the event.
        switch (event.type) {
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_w)
                {
                    p1MoveUp = true;
                }
                else if (event.key.keysym.sym == SDLK_s)
                {
                    p1MoveDown = true;
                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    p2MoveUp = true;
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    p2MoveDown = true;
                }
                else if (event.key.keysym.sym == SDLK_r)
                {
                    reset();
                }
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_w)
                {
                    p1MoveUp = false;
                }
                else if (event.key.keysym.sym == SDLK_s)
                {
                    p1MoveDown = false;
                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    p2MoveUp = false;
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    p2MoveDown = false;
                }
                break;
                
            default:
                break;
        }    
    }
}

void Game::update()
{
    if (p1MoveUp)
    {
        p1YPos -= 5;
        if (p1YPos <= -80)
        {
            p1YPos = 835;
        }
    }
    else if (p1MoveDown)
    {
        p1YPos += 5;
        if (p1YPos >= 840)
        {
            p1YPos = -75;
        }
    }
    if(p2MoveUp)
    {
        p2YPos -= 5;
        if (p2YPos <= -80)
        {
            p2YPos = 835;
        }
    }
    else if (p2MoveDown)
    {
        p2YPos += 5;
        if (p2YPos >= 840)
        {
            p2YPos = -75;
        }
    }
    
    if (ballY >= 570)
    {
        ballMoveY = ballMoveY * -1;
    }
    else if(ballY <= 0)
    {
        ballMoveY = ballMoveY * -1;
    }
    
    if (col->checkCollision(ballRect, player1Rect) == true)
    {
        ballMoveX = bm->player1Hit();
        ballMoveY = bm->yMovement();
    }
    else if (col->checkCollision(ballRect, player2Rect))
    {
        ballMoveX = bm->player2Hit();
        ballMoveY = bm->yMovement();
    }
    
    ballX += ballMoveX;
    ballY += ballMoveY;
    
}

void Game::render()
{
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    
    //All drawing code goes inbetween SDL_RenderPresent and SDL_SetRenderDrawColor
    
    tm->draw("bg", 0, 0, 800, 600, g_pRenderer);
    player1Rect = tm->draw("player1", 15, p1YPos, 15, 80, g_pRenderer);
    player2Rect = tm->draw("player2", 770, p2YPos, 15, 80, g_pRenderer);
    ballRect = tm->draw("ball", ballX, ballY, 30, 30, g_pRenderer);
    
    SDL_RenderPresent(g_pRenderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(g_pWindow);
}

void Game::reset()
{
    ballX = 400;
    ballY = 300;
    
    ballMoveX = bm->xMovement();
    ballMoveY = bm->yMovement();
}

bool Game::isRunning()
{
    return running;
}
