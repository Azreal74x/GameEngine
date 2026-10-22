#include <iostream>
#include <string>
#include <vector>
#include "GameManagerTwo.h"
#include "Crate.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "MathManager.h"
#include "ObjectManager.h"

GameManagerTwo::GameManagerTwo() {

}

void GameManagerTwo::CreateCrates() {
	for (int i = 1; i < crateAmount; i++) {
		int randomX = MathManager::GetInstance().GenerateRandomRange(0 + TextureManager::GetInstance().GetTextureWidth("CRATE"), RenderManager::GetScreenWidth() - TextureManager::GetInstance().GetTextureWidth("CRATE")); //generate random y position for the tubes
		int randomY = MathManager::GetInstance().GenerateRandomRange(0, TextureManager::GetInstance().GetTextureHeight("CRATE"));
		int offsetY = 50 + randomY * i;

		Crate crate(
			TextureManager::GetInstance().GetTexture("CRATE"),
			randomX,
			offsetY - randomY - TextureManager::GetInstance().GetTextureHeight("CRATE"),
			TextureManager::GetInstance().GetTextureWidth("CRATE"),
			TextureManager::GetInstance().GetTextureHeight("CRATE"),
			Collider::CreateRectangle(
				RenderManager::GetScreenWidth() / 2,
				RenderManager::GetScreenHeight() / 2,
				TextureManager::GetInstance().GetTextureWidth("CRATE"),
				TextureManager::GetInstance().GetTextureHeight("CRATE")
			)
		);
		crates.push_back(crate);
	}

	for (int i = 0; i < crates.size(); i++) {
		ObjectManager::GetInstance().AddObject(&crates[i]);
	}

}

void GameManagerTwo::RespawnCrates() {
	for (int i = 0; i < crates.size(); i++) {
		int randomX = MathManager::GetInstance().GenerateRandomRange(0 + TextureManager::GetInstance().GetTextureWidth("CRATE"), RenderManager::GetScreenWidth() - TextureManager::GetInstance().GetTextureWidth("CRATE")); 
		int randomY = TextureManager::GetInstance().GetTextureWidth("CRATE");
		if (crates[i].GetPositionY() > RenderManager::GetScreenHeight()) {
			crates[i].RespawnX(randomX);
			crates[i].RespawnY(randomY);
		}
	}
}