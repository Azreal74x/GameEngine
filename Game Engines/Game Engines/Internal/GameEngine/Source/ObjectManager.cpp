#include "ObjectManager.h"
#include <iostream>

ObjectManager::ObjectManager() {
	ObjectsList = std::vector<Object*>(); //init

/*for (int i = 0; i < ITEM_COUNT; i++) {
	items[i] = NULL;
}*/
}

ObjectManager::~ObjectManager() {
	ObjectsList.clear(); // Clean up object list
}

Object* ObjectManager::GetObject(int index) {
	return ObjectsList[index];
}

//could also be a bool return
void ObjectManager::AddObject(Object* newItem) {

	ObjectsList.push_back(newItem); //push_back adds item to the end

	//different way to do it
	//for (int i = 0; i < ITEM_COUNT; i++) {
	//	if (items[i] == NULL) {
	//		items[i] = newItem;
	//		break;
	//	}
	//}
}

void ObjectManager::RenderAll() {
	for (int i = 0; i < ObjectsList.size(); i++) {
		ObjectsList[i]->Render();
	}
}

void ObjectManager::Update() {
	for (int i = 0; i < ObjectsList.size(); i++) {
		ObjectsList[i]->Update();
	}

	//for (int i = 0; i < ITEM_COUNT; i++) {
	//	items[i]->Update();
	//}

	CheckCollisions();
}

void ObjectManager::CheckCollisions() {
	for (size_t i = 0; i < ObjectsList.size(); ++i) {
		for (size_t j = i + 1; j < ObjectsList.size(); ++j) {
			if (CheckCollision(ObjectsList[i]->GetCollider(), ObjectsList[j]->GetCollider())) {
				/*std::cout << "Collision detected between Object " << ObjectsList[i]
					<< " and Object " << ObjectsList[j] << std::endl;*/

				ObjectsList[i]->CollisionDetected(ObjectsList[j]);
				ObjectsList[j]->CollisionDetected(ObjectsList[i]);

				//std::cout << "collision should be true" << isColliding << std::endl;;
			}
		}
	}
}

bool ObjectManager::CheckCollision(const Collider& a, const Collider& b) {
	if (a.type == ColliderType::CIRCLE && b.type == ColliderType::CIRCLE) {
		int dx = a.circleX - b.circleX;
		int dy = a.circleY - b.circleY;
		int radiiSum = a.radius + b.radius;
		return (dx * dx + dy * dy) <= (radiiSum * radiiSum);
	}
	else if (a.type == ColliderType::CIRCLE && b.type == ColliderType::RECTANGLE) {
		int closestX = std::max(b.rect.x, std::min(a.circleX, b.rect.x + b.rect.w));
		int closestY = std::max(b.rect.y, std::min(a.circleY, b.rect.y + b.rect.h));

		int dx = a.circleX - closestX;
		int dy = a.circleY - closestY;

		return (dx * dx + dy * dy) <= (a.radius * a.radius);
	}
	else if (a.type == ColliderType::RECTANGLE && b.type == ColliderType::RECTANGLE) {
		return a.rect.x < b.rect.x + b.rect.w &&
			a.rect.x + a.rect.w > b.rect.x &&
			a.rect.y < b.rect.y + b.rect.h &&
			a.rect.y + a.rect.h > b.rect.y;
	}

	return false;
}