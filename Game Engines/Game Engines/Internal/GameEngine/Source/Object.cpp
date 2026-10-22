#include "Object.h"
#include "RenderManager.h"
#include <iostream>

Object::Object(Texture* dotTexture, int posX, int posY, Collider collider) 
	: mCollider(collider) {
	mDotTexture = dotTexture;
	mWidth = dotTexture->GetWidth();
	mHeight = dotTexture->GetHeight();
	mPosX = posX;
	mPosY = posY;

	// Update collider position based on the object’s position
	UpdateCollider();

	//std::cout << "Initialized Collider: "
	//	<< "Type: " << (collider.type == ColliderType::CIRCLE ? "Circle" : "Rectangle")
	//	<< ", X: " << mCollider.circleX
	//	<< ", Y: " << mCollider.circleY
	//	<< ", Radius: " << mCollider.radius
	//	<< std::endl;
}


int Object::GetPositionX() {
	return mPosX;
}

int Object::GetPositionY() {
	return mPosY;
}

void Object::Render() {
	mDotTexture->Render(mPosX, mPosY, mWidth, mHeight, RenderManager::GetInstance().getRenderer());
}

void Object::Update() {
	UpdateCollider();
}

void Object::UpdateCollider() {
	if (mCollider.type == ColliderType::RECTANGLE) {
		mCollider.rect.x = mPosX;
		mCollider.rect.y = mPosY;
		mCollider.rect.w = mWidth;
		mCollider.rect.h = mHeight;
	}
	else if (mCollider.type == ColliderType::CIRCLE) {
		mCollider.circleX = mPosX + mWidth / 2; // Center of the circle
		mCollider.circleY = mPosY + mHeight / 2;
		mCollider.radius = mWidth / 2; // Assuming the width equals the diameter
	}
}