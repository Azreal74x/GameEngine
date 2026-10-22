#include <SDL.h>
#include "Texture.h"
#include "Object.h"
#include "Collider.h"

class Dot: public Object {
public:
  Dot(Texture* dotTexture, int posX, int posY, Collider collider);

  void Move();

  //check input
  void CheckInput();

  void Update();

  static const int DOT_WIDTH = 20;
  static const int DOT_HEIGHT = 20;
  static const int DOT_VEL = 10;

private:

};