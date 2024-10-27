#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

#include "Core/Vec2.h"

class Animation
{
	public:
	/**
	 * @brief Construct a new Animation object
	 *
	 */
	Animation();

	/**
	 * @brief Called to update the animation frame
	 *
	 */
	void Tick();

	/**
	 * @brief Set the Frame Size in pixels
	 *
	 * @param size
	 */
	void SetFrameSize(const Vec2& size);

	/**
	 * @brief Set the Frame Rate in ms
	 *
	 * @param rate (defaults to 100ms)
	 */
	void SetFrameRate(Uint16 rate);

	/**
	 * @brief Set the Min Frame of the animation
	 *
	 * @param minFrame
	 */
	void SetMinFrame(Uint16 minFrame);

	/**
	 * @brief Set the Max Frame of the animation
	 *
	 * @param maxFrame
	 */
	void SetMaxFrame(Uint16 maxFrame);

	/**
	 * @brief Set the Current Frame of the animation
	 *
	 * @param currentFrame
	 */
	void SetCurrentFrame(Uint16 currentFrame);

	/**
	 * @brief Get the Current Frame
	 *
	 * @return Uint16
	 */
	[[nodiscard]] auto GetCurrentFrame() const -> Uint16;

	private:
	// State tracking
	Uint16 frameRate;
	Uint16 maxFrame;
	Uint16 currentFrame;
	Uint16 minFrame;
	Uint64 lastTick;

	Vec2 frameSize;
};

#endif // ANIMATION_H