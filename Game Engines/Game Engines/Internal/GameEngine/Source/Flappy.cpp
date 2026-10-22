#include <iostream>
#include <string>
#include "Flappy.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"

Flappy::Flappy(Texture* flappyTexture, int posX, int posY, Collider collider)
	: Object(flappyTexture, posX, posY, collider) {
}

void Flappy::CheckInput() {
	mVelX = 0.0f;
	mVelY = 0.0f;

	if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_SPACE)) {
		//printf("SPACE PRESSED\n");
		mVelY -= FLAPPY_JUMP;
	}
}

void Flappy::Move() {
	mVelY += FLAPPY_GRAVITY;
	mPosY += mVelY;
	//float deltaTime = TimeManager::GetInstance().getDeltaTime();
	//mVelY += FLAPPY_GRAVITY * deltaTime;
	//mPosY += mVelY * deltaTime;

	if (mPosY < 0) {
		mPosY = 0;
	}

	if (mPosY + FLAPPY_HEIGHT> RenderManager::GetScreenHeight()) {
		mPosY = RenderManager::GetScreenHeight() - FLAPPY_HEIGHT;
	}

	//std::cout << "Flappy's mPosY is " << mPosY << std::endl;

	UpdateCollider();
}

void Flappy::CollisionDetected(Object* collidedObject) {
	std::string objectName = collidedObject->GetObjectName();
	if (objectName == "Tube") {
		isFlappyDead = true;
	}
}

void Flappy::Update() {
	if (!isFlappyDead) {
		CheckInput();
	}
	Move();
	//std::cout << isFlappyDead << std::endl;
}