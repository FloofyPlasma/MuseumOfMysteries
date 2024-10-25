#include "Render/Sprite.h"

#include "Render/Surface.h"

Sprite::Sprite()
{
	this->texture = nullptr;
	this->spriteRect = { -1, -1, -1, -1 };
}

Sprite::~Sprite() { }

void Sprite::Draw(int posX, int posY, int sizeX, int sizeY)
{
	SDL_Rect destinationRect = { posX, posY, sizeX, sizeY };

	Surface::Draw(this->texture, &destinationRect);
}

void Sprite::SetTexture(SDL_Texture* texture)
{
	this->texture = texture;

	// Process the texture with SDL2
	if (this->texture != nullptr)
	{
		SDL_QueryTexture(this->texture, nullptr, nullptr, &this->spriteRect.w, &this->spriteRect.h);
	}
}