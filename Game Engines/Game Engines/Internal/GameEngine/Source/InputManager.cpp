//in the source file you write the implementation of the members or methods that you declared in the header

#include "InputManager.h"

InputManager* InputManager::instance = NULL;

//constructor (could be deleted if declared empty in header)
InputManager::InputManager() : mCurrentKeyStates(nullptr), mLastKeyStates(nullptr), mNumKeys(0) {
	// Query the number of keys from SDL
	SDL_GetKeyboardState(&mNumKeys);

	// Allocate memory for key states
	mCurrentKeyStates = new Uint8[mNumKeys];
	mLastKeyStates = new Uint8[mNumKeys];

	// Initialize both arrays to zero
	memset(mCurrentKeyStates, 0, mNumKeys);
	memset(mLastKeyStates, 0, mNumKeys);
}

//destructor (could be deleted if declared empty in header)
InputManager::~InputManager() {
	delete[] mCurrentKeyStates;
	delete[] mLastKeyStates;
}

void InputManager::UpdateKeyStates() {
	// Copy current states to last states
	memcpy(mLastKeyStates, mCurrentKeyStates, mNumKeys);

	// Get updated key states
	const Uint8* sdlKeyStates = SDL_GetKeyboardState(nullptr);
	memcpy(mCurrentKeyStates, sdlKeyStates, mNumKeys);
}

bool InputManager::GetKeyDown(int keyID) {
	return mLastKeyStates[keyID] == 0 && mCurrentKeyStates[keyID] != 0;
}

bool InputManager::GetKeyPressed(int keyID) {
	return mCurrentKeyStates[keyID] != 0;
}