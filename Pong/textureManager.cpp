//
//  textureManager.cpp
//  Pong
//
//  Created by Wilson Koder on 23/11/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include "textureManager.h"
#include <SDL2_image/SDL_image.h>

std::map<std::string, SDL_Texture*> m_textureMap;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *pRenderer)
{
    
    SDL_Surface *pTempSurface = IMG_Load(fileName.c_str());
    
    if(pTempSurface == 0)
    {
        return false;
    }
    
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    if(pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    if (flip == 0)
    {
        flip = SDL_FLIP_NONE;
    }
    
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = srcRect.y = 0;
    
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}


