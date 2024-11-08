#include "IO/Mouse.h"

#include <SDL2/SDL.h>

Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}

auto Mouse::GetPosition() -> Vec2
{
    static int mouseX;
    static int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    return Vec2 { static_cast<float>(mouseX), static_cast<float>(mouseY) };
}