#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include "Singleton.h"

class TimeManager : public Singleton<TimeManager>{
  friend class Singleton<TimeManager>;
public:
  // Constructor
  TimeManager();

  // Start the frame timing
  void startFrame();

  // Get delta time
  float getDeltaTime() const;

  // Create a new timer
  void createTimer();

  // Reset the timer
  void resetTimer(); 

  // Get elapsed time for the timer
  float getElapsedTime() const;

  // Print timer to console
  void printTimer() const;

private:

  Uint32 lastFrameTime;
  float deltaTime;
  Uint32 timerStart;
};

