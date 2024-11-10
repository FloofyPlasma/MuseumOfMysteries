#include "Render/Sprite.h"

#include <iostream>

#include "Render/Surface.h"

Sprite::Sprite()
{
	this->texture = nullptr;
	this->spriteRect = { -1, -1, -1, -1 };
	this->animationRect = this->spriteRect;

	this->framesHorizontal = 0;
	this->framesVertical = 0;
}

Sprite::~Sprite() { }

void Sprite::Draw(int posX, int posY, int sizeX, int sizeY)
{
	SDL_Rect destinationRect = { posX, posY, sizeX, sizeY };

	Surface::Draw(this->texture, &destinationRect);
}

void Sprite::Draw(const Vec2& position, const Vec2& scale)
{
	SDL_Rect destinationRect = { static_cast<int>(position.x), static_cast<int>(position.y),
		static_cast<int>(scale.x), static_cast<int>(scale.y) };

	// Calculate current frame position
	SDL_Rect sourceRect = Sprite::CalculateSourceRectForAnimation();
	Surface::Draw(this->texture, &sourceRect, &destinationRect);

	// Update the animation after rendering
	this->animationControl.Tick();
}

SDL_Rect Sprite::CalculateSourceRectForAnimation()
{
	SDL_Rect sourceRect = { 0, 0, 0, 0 };
	if (this->framesHorizontal != 0)
	{
		sourceRect.x = (this->animationControl.GetCurrentFrame() % this->framesHorizontal)
				* this->animationRect.w;
		sourceRect.y = (this->animationControl.GetCurrentFrame() / this->framesHorizontal)
				* this->animationRect.h;
	}

	sourceRect.w = this->animationRect.w;
	sourceRect.h = this->animationRect.h;

	return sourceRect;
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

void Sprite::SetAnimation(const Animation& animation)
{
	// TODO: Only set if the animations are different
	this->animationControl = animation;
}

void Sprite::SetFrameSize(const Vec2& size)
{
	this->animationRect.w = size.x;
	this->animationRect.h = size.y;

	Sprite::SetCurrentFrame(this->animationControl.GetCurrentFrame());
}

void Sprite::SetFrameRate(Uint16 frameRate) { this->animationControl.SetFrameRate(frameRate); }

void Sprite::SetCurrentFrame(int frame)
{
	// Calculate the frame count
	if (this->spriteRect.w <= 0 || this->animationRect.w <= 0 || this->spriteRect.h <= 0
			|| this->animationRect.h <= 0)
	{
		this->framesHorizontal = 1;
		this->framesVertical = 1;
	}
	else
	{
		this->framesHorizontal = this->spriteRect.w / this->animationRect.w;
		this->framesVertical = this->spriteRect.h / this->animationRect.h;
	}

	this->animationControl.SetCurrentFrame(frame);
}

void Sprite::SetFrameLimits(int minFrame, int maxFrame)
{
	this->animationControl.SetMinFrame(minFrame);
	this->animationControl.SetMaxFrame(maxFrame);
}