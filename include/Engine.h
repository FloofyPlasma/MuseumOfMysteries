#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include <SDL2/SDL.h>

class Engine
{
	public:
	/**
	 * @brief Construct a new Engine object
	 *
	 */
	Engine();

	/**
	 * @brief Destroy the Engine object
	 *
	 */
	virtual ~Engine();

	/**
	 * @brief Creates a window, and sets properties
	 *
	 * @param width
	 * @param height
	 * @param fullScreen defaults to false
	 * @param windowTitle
	 */
	static void SetupWindow(int width, int height, bool fullScreen, std::string windowTitle);

	/**
	 * @brief Starts the engine
	 *
	 */
	void Start();

	/**
	 * @brief Stops the engine
	 *
	 */
	void Stop();

	/**
	 * @brief
	 *
	 */
	virtual void OnInit();

	/**
	 * @brief
	 *
	 * @param event
	 * @param keyboardState
	 */
	virtual void OnEvent(SDL_Event* event, const Uint8* keyboardState);

	/**
	 * @brief
	 *
	 */
	virtual void OnUpdate();

	/**
	 * @brief Called BEFORE the frame is presented to the screen
	 *
	 */
	virtual void OnRender();

	/**
	 * @brief
	 *
	 */
	virtual void OnCleanup();

	private:
	bool quit;

	auto CoreInit() -> bool;
	void CoreEvent(SDL_Event* event, const Uint8* keyboardState);
	void CoreUpdate();
	void CoreRender();
	void CoreCleanup();
};

#endif // ENGINE_H
