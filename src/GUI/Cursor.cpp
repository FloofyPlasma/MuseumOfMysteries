#include "GUI/Cursor.h"

#include "Render/Surface.h"

// Bad hack?
SDL_Texture* Cursor::cursorTexture = nullptr;
SDL_Rect Cursor::cursorRect;

void Cursor::Init(SDL_Texture* cursorTexture, int width, int height)
{
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_FALSE);

	Cursor::cursorTexture = cursorTexture;
	Cursor::cursorRect = { 0, 0, width, height };
}

void Cursor::Draw()
{
	SDL_GetMouseState(&Cursor::cursorRect.x, &Cursor::cursorRect.y);
    // FIXME: BAD HACK! The cursor sprite is centered, and is offset from the actual cursor position by a few pixels
    Cursor::cursorRect.x -= 10;
    Cursor::cursorRect.y -= 8;
	Surface::Draw(Cursor::cursorTexture, &Cursor::cursorRect);
}