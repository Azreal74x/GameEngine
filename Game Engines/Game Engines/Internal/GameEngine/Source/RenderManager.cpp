#include "RenderManager.h"
#include <SDL_image.h>
#include <stdio.h>
#include "ObjectManager.h"
#include "TextureManager.h"

RenderManager::RenderManager() : gWindow(nullptr), gRenderer(nullptr) {}

RenderManager::~RenderManager() {
  Destroy();
}

bool RenderManager::Initialize(const char* title, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  if (!gWindow) {
    printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!gRenderer) {
    printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    return false;
  }

  return true;
}

void RenderManager::Destroy() {
  if (gRenderer) {
    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;
  }
  if (gWindow) {
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
  }
  IMG_Quit();
  SDL_Quit();
}

void RenderManager::RenderAll()
{
  ObjectManager::GetInstance().RenderAll();

}


void RenderManager::Render(Texture* texture, int x, int y, int width, int height, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
  SDL_Rect renderQuad = { x, y, width, height };
  if (clip) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }
  SDL_RenderCopyEx(gRenderer, texture->GetSDLTexture(), clip, &renderQuad, angle, center, flip);
}

SDL_Renderer* RenderManager::getRenderer() {
  return gRenderer;
}

