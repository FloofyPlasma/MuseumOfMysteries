#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

/**
 * @brief Sprite class, has a texture and can be animated
 *
 */
class Sprite
{
	public:
	/**
	 * @brief Construct a new Sprite object
	 *
	 */
	Sprite();

	/**
	 * @brief Destroy the Sprite object
	 *
	 */
	virtual ~Sprite();

	/**
	 * @brief Draws the sprite to the screen
	 *
	 * @param posX
	 * @param posY
	 * @param sizeX
	 * @param sizeY
	 */
	void Draw(int posX, int posY, int sizeX, int sizeY);

	/**
	 * @brief Set the Texture object
	 *
	 * @param texture
	 */
	void SetTexture(SDL_Texture* texture);

	private:
	SDL_Texture* texture;
	SDL_Rect spriteRect;
};

#endif // SPRITE_H