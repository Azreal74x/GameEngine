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
#include "Tube.h"
#include "Flappy.h"
#include "MathManager.h"
#include "GameManager.h"
#include "TimeManager.h"

int main(int argc, char* args[]) {
	TextureManager::CreateSingleton();
	RenderManager::CreateSingleton();
	InputManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	MathManager::CreateSingleton();
	GameManager::CreateSingleton();
	TimeManager::CreateSingleton();

	if (!RenderManager::GetInstance().Initialize("Flappy Bird", RenderManager::GetScreenWidth(), RenderManager::GetScreenHeight())) {
		printf("Failed to initialize!\n");
	}
	else {
		//textures (ID and path)
		std::vector<std::pair<std::string, std::string>> texturesToLoad = {
				{"dot", "../../../MediaGame1/dot.bmp"},
				{"dotTwo", "../../../MediaGame1/dotTwo.bmp"},
				{"BACKGROUND", "../../../MediaGame1/BACKGROUND.png"},
				{"TUBE", "../../../MediaGame1/TUBE.png"},
				{"FLAPPY", "../../../MediaGame1/FLAPPY.png"},
		};

		//load textures
		if (!TextureManager::GetInstance().LoadAllTextures(texturesToLoad)) {
			printf("Failed to load textures!\n");
			return -1;
		}
		else {
			bool quit = false;
			SDL_Event e;

			GameManager::GetInstance().CreateTubes();
			TimeManager::GetInstance().createTimer();

			//flapyp with rectangular collider
			Flappy flappy(TextureManager::GetInstance().GetTexture("FLAPPY"), RenderManager::GetScreenWidth() / 2 - 200, RenderManager::GetScreenHeight() / 2, Collider::CreateRectangle(200, 200, Flappy::FLAPPY_WIDTH, Flappy::FLAPPY_HEIGHT));
			ObjectManager::GetInstance().AddObject(&flappy);

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
				GameManager::GetInstance().RespawnTubes();

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

	GameManager::DestroySingleton();
	MathManager::DestroySingleton();
	ObjectManager::DestroySingleton();
	InputManager::DestroySingleton();
	RenderManager::DestroySingleton();
	TextureManager::DestroySingleton();
	return 0;
}

