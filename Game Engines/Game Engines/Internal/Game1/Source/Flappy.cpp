#include "Flappy.h"
#include "InputManager.h"
#include "RenderManager.h"
#include <iostream>

Flappy::Flappy(Texture* flappyTexture, int posX, int posY, Collider collider)
  : Object(flappyTexture, posX, posY, collider) {
}

void Flappy::CheckInput() {
  mVelX = 0.0f;
  mVelY = 0.0f;

  if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_SPACE)) {
    //printf("UP PRESSED\n");
    mVelY -= FLAPPY_JUMP;
  }
}

void Flappy::Move() {
  mVelY += FLAPPY_VEL;

  mPosX += mVelX;
  if (mPosX < 0 || (mPosX + FLAPPY_WIDTH > RenderManager::GetScreenWidth())) mPosX -= mVelX;

  mPosY += mVelY;
  if (mPosY < 0 || (mPosY + FLAPPY_HEIGHT > RenderManager::GetScreenWidth())) mPosY -= mVelY;

  std::cout << "Flappy's mPosY is " << mPosY << std::endl;

  UpdateCollider();
}

void Flappy::Update() {
  Move();
  CheckInput();
}