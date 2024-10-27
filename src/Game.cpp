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
    testSprite.SetTexture(cursor);
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

    testSprite.Draw(200, 200, 32, 32);
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