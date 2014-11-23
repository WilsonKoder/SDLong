//
//  textureManager.h
//  Pong
//
//  Created by Wilson Koder on 23/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#ifndef __Pong__textureManager__
#define __Pong__textureManager__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include <map>

class TextureManager {
public:
    bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif /* defined(__Pong__textureManager__) */
