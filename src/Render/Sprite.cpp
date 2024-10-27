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

void Sprite::Draw(const Vec2& position, const Vec2& scale)
{
	SDL_Rect destinationRect = {static_cast<int>(position.x), static_cast<int>(position.y), static_cast<int>(scale.x), static_cast<int>(scale.y)};

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