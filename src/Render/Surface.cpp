#include "Render/Surface.h"

#include "GUI/Colors.h"
#include "GUI/Window.h"

Surface::Surface() { }

Surface::~Surface() { }

void Surface::Draw(SDL_Texture* texture, SDL_Rect* destinationRect)
{
	if (texture != nullptr)
	{
		// Draw the texture
		SDL_RenderCopy(Window::GetRenderer(), texture, nullptr, destinationRect);
	}
	else
	{
		// The texture is missing somehow?
		// Just draw it in a color that stands out
		Surface::DrawRect(destinationRect, COLOR_MAGENTA, true);
	}
}

void Surface::Draw(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destinationRect)
{
	if (texture != nullptr)
	{
		// Draw the texture
		SDL_RenderCopy(Window::GetRenderer(), texture, sourceRect, destinationRect);
	}
	else
	{
		// The texture is missing somehow?
		// Just drow it in a color that stands out
		Surface::DrawRect(destinationRect, COLOR_MAGENTA, true);
	}
}

void Surface::DrawRect(SDL_Rect* destinationRect, SDL_Color color, bool filled)
{
	// Change the draw color to the chosen color
	SDL_SetRenderDrawColor(Window::GetRenderer(), color.r, color.g, color.b, color.a);

	if (filled)
	{
		// Draw a filled rect
		SDL_RenderFillRect(Window::GetRenderer(), destinationRect);
	}
	else
	{
		// Draw an empty rect
		SDL_RenderDrawRect(Window::GetRenderer(), destinationRect);
	}

	// TODO: Should we have it change to whatever the current window clear color
	//       is or should I just assume that its black?
	SDL_SetRenderDrawColor(
			Window::GetRenderer(), COLOR_BLACK.r, COLOR_BLACK.g, COLOR_BLACK.b, COLOR_BLACK.a);
}