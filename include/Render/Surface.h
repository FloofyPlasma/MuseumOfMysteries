#ifndef SURFACE_H
#define SURFACE_H

#include <SDL2/SDL.h>

/**
 * @brief Handles drawing textures to the screen
 *
 */
class Surface
{
	public:
	/**
	 * @brief Draw a texture to a rectangle
	 *
	 * @param texture The texture to draw
	 * @param destinationRect The rectangle to draw to
	 */
	static void Draw(SDL_Texture* texture, SDL_Rect* destinationRect);

	/**
	 * @brief Draw a texture from a rectangle to a rectangle
	 *
	 * @param texture The texture to draw
	 * @param sourceRect The rectangle to draw from
	 * @param destinationRect The rectangle to draw to
	 */
	static void Draw(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destinationRect);

	/**
	 * @brief Draws a colored rectangle
	 *
	 * @param destinationRect The rectangle to draw to
	 * @param filled
	 */
	static void DrawRect(SDL_Rect* destinationRect, bool filled);

	static void SetDrawColor(SDL_Color color);

	private:
};

#endif // SURFACE_H