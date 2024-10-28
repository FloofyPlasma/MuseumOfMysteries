#include "Engine.h"

#include "GUI/Colors.h"
#include "Render/Surface.h"
#include "Render/Sprite.h"
#include "Core/Resources.h"

static SDL_Rect testRect = { 205, 205, 190, 190 };
static SDL_Rect testRect2 = { 200, 200, 200, 200 };
static SDL_Rect testRect3 = { 300, 250, 400, 400 };

static SDL_Texture* cursor = nullptr;

static Sprite testSprite;

void Engine::OnInit()
{
    Engine::SetupWindow(1280, 720, false, "Game Window");

    cursor = Resources::GetTexture("Art/Cursors/pointer_b_shaded.png");
    SDL_Texture* frogGuy = Resources::GetTexture("Art/Characters/Frog/Idle.png");
    testSprite.SetTexture(frogGuy);
    testSprite.SetFrameRate(50);
    testSprite.SetFrameLimits(1, 10);
    testSprite.SetFrameSize(Vec2(32.0f, 32.0f));
    testSprite.SetCurrentFrame(1);
}

void Engine::OnEvent(SDL_Event *event, const Uint8 *keyboardState)
{

}

void Engine::OnUpdate()
{

}

void Engine::OnRender()
{
    Surface::DrawRect(&testRect, COLOR_MAGENTA, true);
    // Surface::DrawRect(&testRect3, COLOR_WHITE, true);
    Surface::DrawRect(&testRect2, COLOR_MAGENTA, false);

    testSprite.Draw(Vec2(400.0f, 400.0f), Vec2(64.0f, 64.0f));
    testSprite.Draw(Vec2(450.0f, 450.0f), Vec2(20.0f, 60.0f));
    testSprite.Draw(Vec2(480.0f, 470.0f), Vec2(40.0f, 100.0f));
    testSprite.Draw(Vec2(490.0f, 420.0f), Vec2(32.0f, 20.0f));
    testSprite.Draw(Vec2(420.0f, 480.0f), Vec2(32.0f, 32.0f));
}

void Engine::OnCleanup()
{

}

int main(int argc, char *argv[])
{
    Engine Game;
    Game.Start();

    return 0;
}