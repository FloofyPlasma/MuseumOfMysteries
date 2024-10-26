#include "Engine.h"

#include <iostream>

#include "GUI/Colors.h"
#include "GUI/Window.h"

Engine::Engine() { }

Engine::~Engine() { }

void Engine::Start()
{
	if (!Engine::CoreInit())
	{
		// Something went wring during the initialization internally, abort
		return;
	}

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	auto* event = new SDL_Event; // Use auto to prevent type name duplication

	// Main engine loop
	while (!this->quit)
	{
		Engine::CoreRender();
		Engine::CoreEvent(event, keyboardState);
	}

	// Delete the event since we are preparing to exit
	delete event;

	Engine::CoreCleanup();
}

void Engine::Stop() { this->quit = true; }

void Engine::SetupWindow(int width, int height, bool fullScreen, std::string windowTitle)
{
	Window::SetWindowProperties(width, height, fullScreen, windowTitle);
}

auto Engine::CoreInit() -> bool
{
	this->quit = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init error: " << SDL_GetError() << "\n";
		return false;
	}

	// Setup a window incase you don't make your own.
	Engine::SetupWindow(800, 600, false, "Default Window");

	Engine::OnInit(); // Call the game's init function

	return true;
}

void Engine::CoreEvent(SDL_Event* event, const Uint8* keyboardState)
{
	while (SDL_PollEvent(event) != 0)
	{
		bool ALT_F4 = keyboardState[SDL_SCANCODE_LALT] && keyboardState[SDL_SCANCODE_F4];

		if (ALT_F4 || (event->type == SDL_QUIT))
		{
			Engine::Stop();
			return;
		}

		Engine::OnEvent(event, keyboardState);
	}
}

void Engine::CoreUpdate()
{
	Engine::OnUpdate(); // Call the game's update function
}

void Engine::CoreRender()
{
	// TODO: If we change the clear color, make this not hardcoded
	SDL_SetRenderDrawColor(Window::GetRenderer(), COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
	SDL_RenderClear(Window::GetRenderer());

	Engine::OnRender(); // Call the game's render function

	// I'll eventually want some type of GUI lib stuff
	// which would go here.
	
	SDL_RenderPresent(Window::GetRenderer());
}

void Engine::CoreCleanup()
{
	Engine::OnCleanup(); // Call the game's cleanup function
}