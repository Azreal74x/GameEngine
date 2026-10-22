#pragma once
#include <string>
#include "SDL.h"
#include "Texture.h"
#include "Collider.h"

class Object {

public:
  Object(Texture* dotTexture, int posX, int posY, Collider collider);

  virtual void Update();
  void Render();

  Collider& GetCollider() { return mCollider; }

  int GetPositionX();
  int GetPositionY();

  void SetPosition(int x, int y);

  virtual void CollisionDetected(Object* collidedObject) {}

  virtual std::string GetObjectName() {
    return " ";
  }

protected:
  int mPosX, mPosY;
  int mWidth, mHeight;
  int mVelX, mVelY;

  Texture* mDotTexture;

  Collider mCollider;
  void UpdateCollider();
};