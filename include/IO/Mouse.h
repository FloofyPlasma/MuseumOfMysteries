#ifndef MOUSE_H
#define MOUSE_H

#include "Core/Vec2.h"

enum MouseButton
{
    MOUSE_LEFT,
    MOUSE_MIDDLE,
    MOUSE_RIGHT
};

enum ScrollWheel
{
    MOUSE_WHEEL_UP,
    MOUSE_WHEEL_DOWN
};

class Mouse
{
	public:
    /**
     * @brief Get the Position of the mouse
     * 
     * @return Vec2 
     */
	static auto GetPosition() -> Vec2;

	private:
	Mouse();
    ~Mouse();
};

#endif // MOUSE_H