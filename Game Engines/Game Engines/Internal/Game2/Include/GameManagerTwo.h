#pragma once
#include <SDL.h>
#include "Singleton.h"
#include "Crate.h"

class GameManagerTwo : public Singleton<GameManagerTwo>{
  friend class Singleton<GameManagerTwo>;

public:
  GameManagerTwo();

  void CreateCrates();
  void RespawnCrates();

  int crateAmount = 8;
  std::vector<Crate> crates;

private:

};