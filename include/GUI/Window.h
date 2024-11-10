#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <SDL2/SDL.h>

#include "Core/Vec2.h"

class Window
{
	public:
	/**
	 * @brief Sets window properties
	 *
	 * @param dimensions
	 * @param fullScreen
	 * @param windowTitle
	 */
	static auto SetWindowProperties(
			Vec2 dimensions, bool fullScreen, const std::string& windowTitle = "Game Window") -> bool;

	/**
	 * @brief Basic built-in event handling
	 *
	 * @param event
	 */
	static void OnEvent(const SDL_Event* event);

	/**
	 * @brief Destroys the window and releases the renderer
	 *
	 */
	static void OnCleanup();

	/**
	 * @brief Get the Renderer object
	 *
	 * @return SDL_Renderer*
	 */
	static inline auto GetRenderer() -> SDL_Renderer* { return Window::rendererHandle; }

	/**
	 * @brief Checks if the window was initialized
	 *
	 * @return true if window was initialized
	 * @return false if window was not initialized
	 */
	static inline auto IsInitialized() -> bool;

	/**
	 * @brief Cleans up the window and its renderer
	 *
	 */
	static void Destroy();

	private:

	static SDL_Window* windowHandle;
	static SDL_Renderer* rendererHandle;

	static int sizeX;
	static int sizeY;
	static bool fullscreen;

	static std::string windowTitle;

	/**
	 * @brief Creates a window and renderer
	 *
	 * @return true if window creation succeeded
	 * @return false if window creation failed
	 */
	static bool Init();

	/**
	 * @brief Creates a window
	 *
	 * @return true if window creation succeeded
	 * @return false if window creation failed
	 */
	static auto CreateWindow() -> bool;

	/**
	 * @brief Creates a renderer
	 *
	 * @return true if renderer creation succeeded
	 * @return false if renderer creation failed
	 */
	static auto CreateRenderer() -> bool;
};

#endif // WINDOW_H