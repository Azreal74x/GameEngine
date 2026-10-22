#pragma once
#include <SDL.h>
#include "Object.h"

class Tube : public Object{
public:

  Tube(Texture* flappyTexture, int posX, int posY, Collider collider);

  void Move();
  void RespawnX(int offset);
  void RespawnY(int posY);
  void Update();

  virtual void CollisionDetected(Object* collidedObject);

  virtual std::string GetObjectName() {
    return "Tube";
  }

  static bool stopCondition;

  static const int TUBE_WIDTH = 64;
  static const int TUBE_HEIGHT = 500;
  static const int TUBE_VEL = 2;

private:

};