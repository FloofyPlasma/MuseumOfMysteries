#include "Render/Surface.h"

#include "GUI/Colors.h"
#include "GUI/Window.h"

void Surface::SetDrawColor(SDL_Color color)
{
	SDL_SetRenderDrawColor(Window::GetRenderer(), color.r, color.g, color.b, color.a);
}

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
		Surface::SetDrawColor(COLOR_MAGENTA);
		Surface::DrawRect(destinationRect, true);
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
		Surface::SetDrawColor(COLOR_MAGENTA);
		Surface::DrawRect(destinationRect, true);
	}
}

void Surface::DrawRect(SDL_Rect* destinationRect, bool filled)
{
	SDL_Renderer* renderer = Window::GetRenderer();

	if (filled)
	{
		// Draw a filled rect
		SDL_RenderFillRect(renderer, destinationRect);
	}
	else
	{
		// Draw an empty rect
		SDL_RenderDrawRect(renderer, destinationRect);
	}

	// TODO: Should we have it change to whatever the current window clear color
	//       is or should I just assume that its black?
	Surface::SetDrawColor(COLOR_BLACK);
}