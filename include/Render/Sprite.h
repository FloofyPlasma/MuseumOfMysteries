#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include "Core/Vec2.h"
#include "Render/Animation.h"

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
	 * @brief Draws the sprite to the screen
	 *
	 * @param position
	 * @param scale
	 */
	void Draw(const Vec2& position, const Vec2& scale);

	/**
	 * @brief Set the Texture object
	 *
	 * @param texture
	 */
	void SetTexture(SDL_Texture* texture);

	/**
	 * @brief Set the Animation of this sprite
	 *
	 * @param animation
	 */
	void SetAnimation(const Animation& animation);

	/**
	 * @brief Set the Frame Limits of the animation, use 0 to make it static
	 *
	 * @param minFrame
	 * @param maxFrame
	 */
	void SetFrameLimits(int minFrame, int maxFrame);

	/**
	 * @brief Set the Frame Size of the animation
	 *
	 * @param frameSize
	 */
	void SetFrameSize(const Vec2& frameSize);

	/**
	 * @brief Set the Frame Rate of the animation
	 *
	 * @param frameRate
	 */
	void SetFrameRate(Uint16 frameRate);

	/**
	 * @brief Set the Current Frame of the animation, calculates the positions of frames
	 *
	 * @param frame
	 */
	void SetCurrentFrame(int frame);

	private:
	SDL_Texture* texture;
	SDL_Rect spriteRect; // Full-size of the sprite
	SDL_Rect animationRect; // Size of the sprite cropped to the animation

	int framesHorizontal;
	int framesVertical;

	Animation animationControl;
};

#endif // SPRITE_H