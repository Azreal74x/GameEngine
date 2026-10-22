#include "Texture.h"

Texture::Texture() : mTexture(nullptr), mWidth(0), mHeight(0), mPath("") {}

Texture::~Texture() {
  Free();
}

bool Texture::LoadFromFile(std::string path, SDL_Renderer* renderer) {
  Free();

  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  if (!loadedSurface) {
    printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    return false;
  }

  mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if (!mTexture) {
    printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
  }
  else {
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;
    mPath = path;
  }

  SDL_FreeSurface(loadedSurface);
  return mTexture != nullptr;
}

void Texture::Free() {
  if (mTexture) {
    SDL_DestroyTexture(mTexture);
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
  }
}

void Texture::Render(int x, int y, int width, int height, SDL_Renderer* renderer) {
  SDL_Rect renderQuad = { x, y, width, height };
  SDL_RenderCopy(renderer, mTexture, nullptr, &renderQuad);
}

SDL_Texture* Texture::GetSDLTexture() const {
  return mTexture;
}

int Texture::GetWidth() {
  return mWidth;
}

int Texture::GetHeight() {
  return mHeight;
}
