#include "Engine.h"

#include "GUI/Colors.h"
#include "Render/Surface.h"

static SDL_Rect testRect = { 205, 205, 190, 190 };
static SDL_Rect testRect2 = { 200, 200, 200, 200 };
static SDL_Rect testRect3 = { 300, 250, 400, 400 };

void Engine::OnInit()
{
    Engine::SetupWindow(1280, 720, false, "Game Window");
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
    Surface::DrawRect(&testRect3, COLOR_WHITE, true);
    Surface::DrawRect(&testRect2, COLOR_MAGENTA, false);
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