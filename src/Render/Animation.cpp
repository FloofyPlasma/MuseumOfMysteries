#include "Render/Animation.h"

Animation::Animation()
{
    this->frameRate = 100;
    this->maxFrame = 0;
    this->currentFrame = 0;
    this->minFrame = 0;
    this->lastTick = 0;
}

void Animation::SetFrameRate(Uint16 rate)
{
    // Cannot have a negative frame-rate
    if (rate >= 0)
    {
        this->frameRate = rate;
    }
}

void Animation::SetFrameSize(const Vec2& size)
{
    this->frameSize = size;
}

void Animation::Tick()
{
    if (this->lastTick + this->frameRate > SDL_GetTicks64() || this->minFrame == this->maxFrame)
    {
        // If enough time has not elapsed
        // OR if we only have one frame
        // break out of the tick function
        return;
    }

    this->lastTick = SDL_GetTicks64();
    this->currentFrame++;

    if (this->currentFrame > this->maxFrame)
    {
        // If we exceed the max frames in this animation
        // Wrap around to the start again
        this->currentFrame = this->minFrame;
    }
}

void Animation::SetMinFrame(Uint16 minFrame)
{
    this->minFrame = minFrame;
}

void Animation::SetMaxFrame(Uint16 maxFrame)
{
    this->maxFrame = maxFrame;
}

void Animation::SetCurrentFrame(Uint16 currentFrame)
{
    this->currentFrame = currentFrame;
}

auto Animation::GetCurrentFrame() const -> Uint16
{
    return this->currentFrame;
}