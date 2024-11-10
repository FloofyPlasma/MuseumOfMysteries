#include "GUI/Window.h"

#include <iostream>

#include "GUI/Colors.h"

// Bad hack?
int Window::sizeX = 1280;
int Window::sizeY = 720;
bool Window::fullscreen = false;
std::string Window::windowTitle = "Game Window";

// Window handles
SDL_Window* Window::windowHandle;
SDL_Renderer* Window::rendererHandle;

auto Window::Init() -> bool
{
	Window::Destroy();

	// Create a new window
	if (!Window::CreateWindow())
	{
		std::cerr << "Failed to initialize window.\n";
		return false;
	}

	// Create new renderer
	if (!Window::CreateRenderer())
	{
		std::cerr << "Failed to initialize renderer.\n";
		return false;
	}


	SDL_SetRenderDrawColor(Window::rendererHandle, COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);

	SDL_RenderSetLogicalSize(Window::rendererHandle, Window::sizeX, Window::sizeY);

	return true;
}

auto Window::CreateWindow() -> bool
{
	Window::windowHandle = SDL_CreateWindow(Window::windowTitle.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, Window::sizeX, Window::sizeY,
			SDL_WINDOW_FULLSCREEN_DESKTOP * static_cast<int>(Window::fullscreen));

	if (!Window::windowHandle)
	{
		std::cerr << SDL_GetError() << "\n";
		return false;
	}

	return true;
}

auto Window::CreateRenderer() -> bool { SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	Window::rendererHandle = SDL_CreateRenderer(
			Window::windowHandle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!Window::rendererHandle)
	{
		std::cerr << SDL_GetError() << "\n";
		return false;
	}

	return true;
}

auto Window::SetWindowProperties(
		Vec2 dimensions, bool fullScreen, const std::string& windowTitle) -> bool
{
	Window::sizeX = dimensions.x;
	Window::sizeY = dimensions.y;
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
	return;
  //if (event->type == SDL_WINDOWEVENT)
  //{
  //  switch (event->window.event)
  //  {
  //      case SDL_WINDOWEVENT_CLOSE:
  //        break;
  //  }
  //}
}

inline auto Window::IsInitialized() -> bool
{
	return (Window::windowHandle != nullptr && Window::rendererHandle != nullptr);
}

void Window::Destroy() {
	if (Window::rendererHandle)
	{
		SDL_DestroyRenderer(Window::rendererHandle);
		Window::rendererHandle = nullptr;
	}
	
	if (Window::windowHandle)
	{
		SDL_DestroyWindow(Window::windowHandle);
		Window::windowHandle = nullptr;
	}
}