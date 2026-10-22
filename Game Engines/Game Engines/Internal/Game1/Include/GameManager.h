#pragma once
#include <SDL.h>
#include "Singleton.h"
#include "Tube.h"

class GameManager : public Singleton<GameManager>{
  friend class Singleton<GameManager>;

public:
  GameManager();

  void CalculateTubeDistanceX();
  void CreateTubes();
  void RespawnTubes();

  //variables for tubes
  int tubeDistanceX = 0;
  int tubeDistanceY = 250;
  int tubeAmount = 4;

  //list to store tubes
  std::vector<Tube> tubes;

private:

};