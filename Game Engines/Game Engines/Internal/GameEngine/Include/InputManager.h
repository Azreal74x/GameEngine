//in the header file you write the declarations of the members and methods (and parameters)
//the class size is 64 bit

#pragma once
#include <Singleton.h>
#include <SDL.h>
#include <stdio.h>

/**
Input Manager class
*/
class InputManager:public Singleton<InputManager> {
	/*****************************************************************************/
	friend class Singleton<InputManager>;
	/*****************************************************************************/

private:

	//const Uint8* mCurrentKeyStates = NULL;
	//const Uint8 mLastKeyStates = NULL;

	Uint8* mCurrentKeyStates; // Array to store current key states
	Uint8* mLastKeyStates;    // Array to store last key states
	int mNumKeys;             // Number of keys tracked

	//pointer for optimization: if without, it would copy instance, get info and destroy
	static InputManager* instance;

	InputManager(); //can also be InputManager{} and the constructor can be deleted from cpp
	~InputManager(); //can also be ~InputManager{} and the destructor can be deleted from cpp
	//you should only put it in the header file if it doesn't need to access another class

public:

	//static void CreateInstance() {
	//	if (instance == NULL) {
	//		instance = new InputManager();
	//		printf("Created InputManager instance\n");
	//	}
	//	else {
	//		printf("Trying to create instance twice!\n");
	//	}
	//}

	//static void DestroyInstance() {
	//	if (instance != NULL) {
	//		delete(instance);
	//		instance = NULL;
	//	}
	//	else {
	//		printf("Trying to destroy non existant instance!\n");
	//	}
	//}

	////pointer way (uses the -> operator)
	//static InputManager* GetInstancePtr() {
	//	return instance;
	//}

	////reference way (uses the . operator) PREFERRED
	////returns a pointer to input manager address,
	////so its saving the beginning position of InputManager is at this place in memory
	//static InputManager& GetInstanceRef() {
	//	return *instance;
	//}

	//functions below are dynamic
	void UpdateKeyStates();
	bool GetKeyDown(int keyID);
	bool GetKeyPressed(int keyID);

};


