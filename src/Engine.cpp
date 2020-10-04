#include "Engine.h"
#include "TextureManager.h"
#include "Warrior.h"
#include "Input.h"
#include "SDL2/SDL.h"
	
Engine* Engine::s_Instance = nullptr;
Input* Input::s_Instance = nullptr;
Warrior* player = nullptr;

bool Engine::Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		SDL_Log("Failed initialize SDL: %s", SDL_GetError());
		return false;
	}

	m_Window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if(m_Window == nullptr)
	{
		SDL_Log("Failed to create Window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(m_Renderer == nullptr)
	{
		SDL_Log("Failed to create Renderer: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->Load("player", "assets/Idle.png");

	player = new Warrior(new Properties("player", 320, 128, 64, 64));

	Transform tf;
	tf.Log();


	return m_IsRunning = true;
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
}

void Engine::Quit()
{
	m_IsRunning = false;
}

void Engine::Update()
{
	if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		SDL_Log("Key A pushed");
	}
	player->Update(0);
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	player->Draw();
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	Input::GetInstance()->Listen();
}