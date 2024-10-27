#include "Core/Vec2.h"

const Vec2 Vec2::ZERO = Vec2(0.0f, 0.0f);

Vec2::Vec2()
{
    this->x = 0.0f;
    this->y = 0.0f;
}

Vec2::Vec2(const float& x, const float& y)
{
    this->x = x;
    this->y = y;
}