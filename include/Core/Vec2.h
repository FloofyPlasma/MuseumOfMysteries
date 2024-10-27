#ifndef VEC2_H
#define VEC2_H

/**
 * @brief Vector2 class for positions
 *
 */
class Vec2
{
	public:
    const static Vec2 ZERO;

	/**
	 * @brief Vector2 X value.
	 *
	 */
	float x;

	/**
	 * @brief Vector2 Y value.
	 *
	 */
	float y;

	/**
	 * @brief Construct a new Vec 2 object with x and y values of 0
	 *
	 */
	Vec2();

	/**
	 * @brief Construct a new Vec 2 object
	 *
	 * @param x
	 * @param y
	 */
	Vec2(const float& x, const float& y);

	private:
};

#endif // VEC2_H