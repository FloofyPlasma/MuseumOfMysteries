#ifndef CURSOR_H
#define CURSOR_H

#include <SDL2/SDL.h>

// TODO: Eventually it may be a good idea to have a state manager so when you hover over for example
//       a button it swaps the cursor texture.

#include "Core/Vec2.h"

class Cursor
{
	public:
	/**
	 * @brief Initialize the cursor
	 *
	 * @param cursorTexture
	 * @param cursorDimensions
	 */
	static void Init(SDL_Texture* cursorTexture, Vec2 cursorDimensions);

	/**
	 * @brief Draw the cursor to the screen
	 *
	 */
	static void Draw();

	private:
	static SDL_Texture* cursorTexture;
	static SDL_Rect cursorRect;
};

#endif // CURSOR_H