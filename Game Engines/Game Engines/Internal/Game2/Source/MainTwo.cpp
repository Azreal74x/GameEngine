#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Texture.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Dot.h"
#include "DotTwo.h"
#include "Crate.h"
#include "Player.h"
#include "MathManager.h"
#include "GameManagerTwo.h"
#include "TimeManager.h"

int main(int argc, char* args[]) {
	TextureManager::CreateSingleton();
	RenderManager::CreateSingleton();
	InputManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	MathManager::CreateSingleton();
	GameManagerTwo::CreateSingleton();
	TimeManager::CreateSingleton();

	if (!RenderManager::GetInstance().Initialize("Crate Run", RenderManager::GetScreenWidth(), RenderManager::GetScreenHeight())) {
		printf("Failed to initialize!\n");
	}
	else {
		// List of textures to load (ID and path)
		std::vector<std::pair<std::string, std::string>> texturesToLoad = {
				{"dot", "../../../MediaGame2/dot.bmp"},
				{"dotTwo", "../../../MediaGame2/dotTwo.bmp"},
				{"BACKGROUND", "../../../MediaGame2/BACKGROUND.png"},
				{"CRATE", "../../../MediaGame2/CRATE.png"},
				{"PLAYER", "../../../MediaGame2/PLAYER.png"},
		};

		// Load all textures
		if (!TextureManager::GetInstance().LoadAllTextures(texturesToLoad)) {
			printf("Failed to load textures!\n");
			return -1;
		}
		else {
			bool quit = false;
			SDL_Event e;

			GameManagerTwo::GetInstance().CreateCrates();
			TimeManager::GetInstance().createTimer();

			//player with rectangular collider
			Player player(
				TextureManager::GetInstance().GetTexture("PLAYER"), 
				RenderManager::GetScreenWidth() / 2, 
				RenderManager::GetScreenHeight() - TextureManager::GetInstance().GetTextureHeight("PLAYER"),
				TextureManager::GetInstance().GetTextureWidth("PLAYER"), 
				TextureManager::GetInstance().GetTextureHeight("PLAYER"), 
				Collider::CreateRectangle(
					RenderManager::GetScreenWidth() / 2,
					RenderManager::GetScreenHeight() / 2,
					TextureManager::GetInstance().GetTextureWidth("PLAYER"), 
					TextureManager::GetInstance().GetTextureHeight("PLAYER")
				)
			);
			ObjectManager::GetInstance().AddObject(&player);

			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}
				 
				TimeManager::GetInstance().startFrame();
				//std::cout<< "delta time is " << TimeManager::GetInstance().getDeltaTime() << std::endl;

				InputManager::GetInstance().UpdateKeyStates();
				ObjectManager::GetInstance().Update();
				GameManagerTwo::GetInstance().RespawnCrates();

				SDL_SetRenderDrawColor(RenderManager::GetInstance().getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(RenderManager::GetInstance().getRenderer());

				// Render background (before objects)
				Texture* backgroundTexture = TextureManager::GetInstance().GetTexture("BACKGROUND");
				SDL_Texture* sdlBackground = backgroundTexture->GetSDLTexture(); // Access the SDL_Texture
				SDL_RenderCopy(RenderManager::GetInstance().getRenderer(), sdlBackground, nullptr, nullptr);

				RenderManager::GetInstance().RenderAll();
				SDL_RenderPresent(RenderManager::GetInstance().getRenderer());

			}
		}
	}

	GameManagerTwo::DestroySingleton();
	MathManager::DestroySingleton();
	ObjectManager::DestroySingleton();
	InputManager::DestroySingleton();
	RenderManager::DestroySingleton();
	TextureManager::DestroySingleton();
	return 0;
}

