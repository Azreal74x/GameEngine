#include <iostream>
#include <string>
#include "Crate.h"
#include "RenderManager.h"
#include "MathManager.h"

bool Crate::stopCondition = false;

Crate::Crate(Texture* crateTexture, int posX, int posY, int width, int height, Collider collider)
	: Object(crateTexture, posX, posY, collider) {
	CRATE_WIDTH = width;
	CRATE_HEIGHT = height;
}

void Crate::Move() {
	mPosY += CRATE_VEL;
	UpdateCollider();
}

void Crate::CollisionDetected(Object* collidedObject) {
	std::string objectName = collidedObject->GetObjectName();
	if (objectName == "Player") {
		Crate::stopCondition = true;
	}
}

void Crate::Update() {
	if (!stopCondition) {
		Move();
	}
}

void Crate::RespawnX(int posX) {
	mPosX = posX;
}

void Crate::RespawnY(int posY) {
	mPosY = posY - CRATE_HEIGHT;
}
