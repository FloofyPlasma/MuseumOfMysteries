#include "Engine.h"

#include "GUI/Colors.h"
#include "Render/Surface.h"

static SDL_Rect testRect = { 50, 50, 50, 50 };

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