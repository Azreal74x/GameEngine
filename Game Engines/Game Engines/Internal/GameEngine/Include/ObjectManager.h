#pragma once
#include "Object.h"
#include <cstddef>
#include <stdio.h>
#include <vector>
#include "Singleton.h"
#include "Texture.h"

class ObjectManager :public Singleton<ObjectManager>{
	friend class Singleton<ObjectManager>;

public:

	ObjectManager();
	~ObjectManager();

	Object* GetObject(int index); // Get object by index
	void AddObject(Object* newItem); // Add an object to the manager
	void RenderAll(); // Render all objects
	void Update(); // Update all objects

private:

	//static const int ITEM_COUNT = 50;
	//Item* items[ITEM_COUNT]; 	//static array

	std::vector<Object*> ObjectsList; //vector is a dynamic array

	void CheckCollisions(); // Check collisions between objects
	bool CheckCollision(const Collider& a, const Collider& b); // Check collision between two colliders
};