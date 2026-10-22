#pragma once
#include "Singleton.h"
#include <SDL.h>
#include "Texture.h"

class RenderManager :public Singleton<RenderManager> {
  friend class Singleton<RenderManager>;

public:
  RenderManager();
  ~RenderManager();

  bool Initialize(const char* title, int width, int height);
  void Destroy();

  void Render(Texture* texture, int x, int y, int width, int height, SDL_Rect* clip = nullptr,
    double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

  SDL_Renderer* getRenderer();

  static int GetScreenWidth() {
    return SCREEN_WIDTH;
  }

  static int GetScreenHeight() {
    return SCREEN_HEIGHT;
  }

  void RenderAll();

private:
  SDL_Window* gWindow;
  SDL_Renderer* gRenderer;

  static const int SCREEN_WIDTH = 840;
  static const int SCREEN_HEIGHT = 480;
};

