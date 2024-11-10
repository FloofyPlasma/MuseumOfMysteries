#include "GUI/Cursor.h"

#include "Render/Surface.h"

// Bad hack?
SDL_Rect Cursor::cursorRect;

SDL_Texture* Cursor::cursorTexture;

void Cursor::Init(SDL_Texture* cursorTexture, Vec2 cursorDimensions)
{
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_FALSE);

	Cursor::cursorTexture = cursorTexture;
	Cursor::cursorRect
			= { 0, 0, static_cast<int>(cursorDimensions.x), static_cast<int>(cursorDimensions.y) };
}

void Cursor::Draw()
{
	SDL_GetMouseState(&Cursor::cursorRect.x, &Cursor::cursorRect.y);
	// FIXME: BAD HACK! The cursor sprite is centered, and is offset from the actual cursor position
	// by a few pixels
	Cursor::cursorRect.x -= 10;
	Cursor::cursorRect.y -= 8;
	Surface::Draw(Cursor::cursorTexture, &Cursor::cursorRect);
}