#include <SDL.h>
#include <iostream>
#include "Dot.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "Collider.h"

Dot::Dot(Texture* dotTexture, int posX, int posY, Collider collider)
  : Object(dotTexture, posX, posY, collider) {
}

void Dot::CheckInput() {
  mVelX = 0.0f;
  mVelY = 0.0f;

  if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_DOWN)) {
    //printf("DOWN PRESSED\n");
    mVelY += DOT_VEL;
  }
  if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_UP)) {
    //printf("UP PRESSED\n");
    mVelY -= DOT_VEL;
  }
  if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_LEFT)) {
    //printf("LEFT PRESSED\n");
    mVelX -= DOT_VEL;
  }
  if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_RIGHT)) {
    //printf("RIGHT PRESSED\n");
    mVelX += DOT_VEL;
  }
}

void Dot::Move() {
  mPosX += mVelX;
  if (mPosX < 0 || (mPosX + DOT_WIDTH > RenderManager::GetScreenWidth())) mPosX -= mVelX;

  mPosY += mVelY;
  if (mPosY < 0 || (mPosY + DOT_HEIGHT > RenderManager::GetScreenWidth())) mPosY -= mVelY;

  // Update the collider's position
  UpdateCollider();
}

void Dot::Update() {
  Move();
  CheckInput();
}
