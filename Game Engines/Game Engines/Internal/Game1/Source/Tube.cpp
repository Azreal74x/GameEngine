#include <iostream>
#include <string>
#include "Tube.h"
#include "RenderManager.h"
#include "MathManager.h"

bool Tube::stopCondition = false;

Tube::Tube(Texture* tubeTexture, int posX, int posY, Collider collider)
	: Object(tubeTexture, posX, posY, collider) {
	//std::cout << "i have been added" << std::endl;
}

void Tube::Move() {
	mPosX -= TUBE_VEL;
	UpdateCollider();
}

void Tube::CollisionDetected(Object* collidedObject) {
	std::string objectName = collidedObject->GetObjectName();
	if (objectName == "Flappy") {
		Tube::stopCondition = true;
	}
}

void Tube::Update() {
	if (!stopCondition) {
		Move();
	}
}
 
void Tube::RespawnX(int offset) {
	//std::cout << "Respawn X called" << std::endl;
	mPosX = RenderManager::GetScreenWidth() + offset;
	//std::cout << "New pos X is " << mPosX << std::endl;
}

void Tube::RespawnY(int posY) {
	//std::cout << "Respawn Y called with passed parameter posY is " << posY << std::endl;
	mPosY = posY;
}
