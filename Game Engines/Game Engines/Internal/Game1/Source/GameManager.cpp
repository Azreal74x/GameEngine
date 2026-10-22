#include <iostream>
#include <string>
#include <vector>
#include "GameManager.h"
#include "Tube.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "MathManager.h"
#include "ObjectManager.h"

GameManager::GameManager() {

}

void GameManager::CalculateTubeDistanceX() { //calculate the distance based on screensize (it's not necessary but..)
	int screenWidth = RenderManager::GetScreenWidth();
	for (int i = screenWidth - 1; i >= 1; i--) {
		if (screenWidth % i == 0 && i % 2 == 0) {
			tubeDistanceX = i;
			//std::cout << "Tube distance X is " << tubeDistanceX << std::endl;
			break;
		}
	}
}

void GameManager::CreateTubes() {
	CalculateTubeDistanceX();

	for (int i = 1; i < tubeAmount; i++) {
		int randomY = MathManager::GetInstance().GenerateRandomRange(-450, 175); //generate random y position for the tubes
		int offsetX = tubeDistanceX * i;

		//tube with rectangular collider
		Tube tube(TextureManager::GetInstance().GetTexture("TUBE"), RenderManager::GetScreenWidth() + offsetX, randomY, Collider::CreateRectangle(RenderManager::GetScreenWidth() + offsetX, randomY, Tube::TUBE_WIDTH, Tube::TUBE_HEIGHT));
		tubes.push_back(tube);

		//tube with rectangular collider
		Tube tubeTwo(TextureManager::GetInstance().GetTexture("TUBE"), RenderManager::GetScreenWidth() + offsetX, randomY + tube.TUBE_HEIGHT + tubeDistanceY, Collider::CreateRectangle(RenderManager::GetScreenWidth() + offsetX, randomY + tube.TUBE_HEIGHT + tubeDistanceY, Tube::TUBE_WIDTH, Tube::TUBE_HEIGHT));
		tubes.push_back(tubeTwo);
	}

	//add all tubes to object manager
	for (int i = 0; i < tubes.size(); i++) {
		ObjectManager::GetInstance().AddObject(&tubes[i]);
	}

}

void GameManager::RespawnTubes() {
	for (int i = 0; i < tubes.size(); i += 2) {
		//std::cout << "i is " << i << std::endl;
		//std::cout << "Current X pos is " << tubes[i].GetPositionX() << std::endl;
		int randomY = MathManager::GenerateRandomRange(-450, 175);
		//std::cout << "Generated randomY =  " << randomY << std::endl;
		if (tubes[i].GetPositionX() < -tubes[i].TUBE_WIDTH) {
			//std::cout << "Tube pos X is smaller than tube width below 0" << std::endl;
			if (i % 2 == 0) {
				//std::cout << "Top tube" << std::endl;
				tubes[i].RespawnY(randomY);
				//std::cout << "Bottom tube" << std::endl;
				tubes[i + 1].RespawnY(randomY + tubes[i + 1].TUBE_HEIGHT + tubeDistanceY);

				tubes[i].RespawnX(tubeDistanceX - tubes[i].TUBE_WIDTH);
				tubes[i + 1].RespawnX(tubeDistanceX - tubes[i].TUBE_WIDTH);
			}
		}
	}
}