#include "Engine.h"
#include <iostream>

	
Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	return m_IsRunning = true;
}

bool Engine::Clean()
{
}

void Engine::Quit(){}

void Engine::Update()
{
	std::cout << "Updating!" << std::endl;
}

void Engine::Render(){}

void Engine::Events(){}