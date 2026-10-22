#include "TimeManager.h"

TimeManager::TimeManager() : lastFrameTime(0), deltaTime(0.0f), timerStart(0) {}

void TimeManager::startFrame() {
  Uint32 currentTime = SDL_GetTicks();
  deltaTime = (currentTime - lastFrameTime) / 1000.0f; // Convert ms to seconds
  lastFrameTime = currentTime;
}

float TimeManager::getDeltaTime() const {
  return deltaTime;
}

void TimeManager::createTimer() {
  timerStart = SDL_GetTicks();
}

void TimeManager::resetTimer() {
  timerStart = SDL_GetTicks();
}

float TimeManager::getElapsedTime() const {
  return (SDL_GetTicks() - timerStart) / 1000.0f; // Convert ms to seconds
}

void TimeManager::printTimer() const {
  float elapsedTime = getElapsedTime();
  //std::cout << "Elapsed Time: " << elapsedTime << " seconds" << std::endl;
}
