#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture {
public:
  Texture();
  ~Texture();

  bool LoadFromFile(std::string path, SDL_Renderer* renderer);
  void Free();
  void Render(int x, int y, int width, int height, SDL_Renderer* renderer);

  SDL_Texture* GetSDLTexture() const;

  int GetWidth();
  int GetHeight();

private:
  SDL_Texture* mTexture;
  int mWidth;
  int mHeight;
  std::string mPath;
};

