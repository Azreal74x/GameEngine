#pragma once
#include <SDL.h>
#include <string>
#include "Object.h"

class Player : public Object {
public:

	Player(Texture* playerTexture, int posX, int posY, int width, int height, Collider collider);

	void CheckInput();
	void Move();

	virtual void CollisionDetected(Object* collidedObject);

	virtual std::string GetObjectName() {
		return "Player";
	}

	void Update();

	int PLAYER_WIDTH;
	int PLAYER_HEIGHT;
	const float PLAYER_SPEED = 8.0f;

private:

	bool isPlayerDead = false;

};