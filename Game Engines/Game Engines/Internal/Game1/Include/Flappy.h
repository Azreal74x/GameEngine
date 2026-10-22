#pragma once
#include <SDL.h>
#include <string>
#include "Object.h"

class Flappy : public Object {
public:

  Flappy(Texture* flappyTexture, int posX, int posY, Collider collider);

  void CheckInput();
  void Move();

  virtual void CollisionDetected(Object* collidedObject);

  virtual std::string GetObjectName() {
    return "Flappy";
  }

  void Update();

  static const int FLAPPY_WIDTH = 100;
  static const int FLAPPY_HEIGHT = 40;
  static const int FLAPPY_JUMP = 15; //80
  static const int FLAPPY_GRAVITY = 5;

private:

  bool isFlappyDead = false;

};