#include <iostream>
#include <string>
#include "Player.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"

Player::Player(Texture* playerTexture, int posX, int posY, int width, int height, Collider collider)
	: Object(playerTexture, posX, posY, collider) {
	PLAYER_WIDTH = width;
	PLAYER_HEIGHT = height;
}

void Player::CheckInput() {
	mVelX = PLAYER_SPEED;

	if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_A)) {
		mPosX -= mVelX;
	}

	if (InputManager::GetInstance().GetKeyPressed(SDL_SCANCODE_D)) {
		mPosX += mVelX;
	}

	UpdateCollider();
}

void Player::Move() {
	if (mPosX + PLAYER_WIDTH >= RenderManager::GetScreenWidth()) {
		mPosX = RenderManager::GetScreenWidth() - PLAYER_WIDTH;
	}
	else if (mPosX <= 0) {
		mPosX = 0;
	}

	UpdateCollider();
}

void Player::CollisionDetected(Object* collidedObject) {
	std::string objectName = collidedObject->GetObjectName();
	if (objectName == "Crate") {
		isPlayerDead = true;
	}
}

void Player::Update() {
	if (!isPlayerDead) {
		CheckInput();
	}
	Move();
}