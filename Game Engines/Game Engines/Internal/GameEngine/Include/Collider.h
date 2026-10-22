#pragma once
#include "SDL.h"

enum class ColliderType { NONE, CIRCLE, RECTANGLE };

class Collider {
public:
  ColliderType type;
  SDL_Rect rect; //rectangle collider
  int circleX, circleY, radius; //circle collider

  Collider() : type(ColliderType::NONE), rect({ 0, 0, 0, 0 }), circleX(0), circleY(0), radius(0) {}

  static Collider CreateRectangle(int x, int y, int w, int h) {
    Collider collider;
    collider.type = ColliderType::RECTANGLE;
    collider.rect = { x, y, w, h };
    return collider;
  }

  static Collider CreateCircle(int x, int y, int r) {
    Collider collider;
    collider.type = ColliderType::CIRCLE;
    collider.circleX = x;
    collider.circleY = y;
    collider.radius = r;
    return collider;
  }
};

