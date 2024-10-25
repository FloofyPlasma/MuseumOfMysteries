#include "GUI/Window.h"

#include <iostream>

#include "GUI/Colors.h"

// Bad hack?
SDL_Window* Window::windowHandle = nullptr;
SDL_Renderer* Window::rendererHandle = nullptr;
int Window::sizeX = 1280;
int Window::sizeY = 720;
bool Window::fullscreen = false;
std::string Window::windowTitle = "Game Window";

Window::Window() { }

Window::~Window() { }

auto Window::Init() -> bool
{
	// Check if we already have a window and destroy it if it exists.
	if (Window::windowHandle != nullptr)
	{
		SDL_DestroyWindow(Window::windowHandle);
	}

	// Create a new window
	Window::windowHandle = SDL_CreateWindow(Window::windowTitle.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, Window::sizeX, Window::sizeY,
			SDL_WINDOW_FULLSCREEN_DESKTOP * static_cast<int>(Window::fullscreen));

	if (Window::windowHandle == nullptr)
	{
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
		return false;
	}

	// Check if we already have a renderer and destroy it if it exists
	if (Window::rendererHandle != nullptr)
	{
		SDL_DestroyRenderer(Window::rendererHandle);
	}

	// Set the scaling to nearest pixel
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

	// Create a new renderer
	Window::rendererHandle = SDL_CreateRenderer(
			Window::windowHandle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (Window::rendererHandle == nullptr)
	{
		std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
		return false;
	}

	SDL_SetRenderDrawColor(Window::rendererHandle, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);

	SDL_RenderSetLogicalSize(Window::rendererHandle, Window::sizeX, Window::sizeY);

	return true;
}

auto Window::SetWindowProperties(
		int width, int height, bool fullScreen, const std::string& windowTitle) -> bool
{
	Window::sizeX = width;
	Window::sizeY = height;
	Window::fullscreen = fullScreen;
	Window::windowTitle = windowTitle;

	if (!Window::IsInitialized())
	{
		return Window::Init();
	}

	SDL_SetWindowTitle(Window::windowHandle, Window::windowTitle.c_str());
	SDL_SetWindowSize(Window::windowHandle, Window::sizeX, Window::sizeY);

	SDL_RenderSetLogicalSize(Window::rendererHandle, Window::sizeX, Window::sizeY);

	return true;
}

void Window::OnEvent(const SDL_Event* event)
{
  if (event->type == SDL_WINDOWEVENT)
  {
    switch (event->window.event)
    {
        case SDL_WINDOWEVENT_CLOSE:
          break;
    }
  }
}

inline auto Window::IsInitialized() -> bool
{
	return (Window::windowHandle != nullptr && Window::rendererHandle != nullptr);
}