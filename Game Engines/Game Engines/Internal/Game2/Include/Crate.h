#pragma once
#include <SDL.h>
#include "Object.h"

class Crate : public Object{
public:

  Crate(Texture* flappyTexture, int posX, int posY, int width, int height, Collider collider);

  void Move();
  void RespawnX(int posX);
  void RespawnY(int posY);
  void Update();

  virtual void CollisionDetected(Object* collidedObject);

  virtual std::string GetObjectName() {
    return "Crate";
  }

  static bool stopCondition;

   int CRATE_WIDTH;
   int CRATE_HEIGHT;
   int CRATE_VEL = 2;

private:

};