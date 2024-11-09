#include "Core/Resources.h"

#include <iostream>
#include <vector>

#include <SDL_image.h>

#include "GUI/Window.h"
#include "IO/File.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_rwops.h"

// Bad hack?

// TODO: Make this not hard-coded, and preferably make
//       it so the game can overwrite this.
const std::string Resources::ASSETS_PATH = "./assets/";

std::unordered_map<std::string, SDL_Texture*> Resources::loadedTextures;

auto Resources::GetTexture(std::string filePath) -> SDL_Texture*
{
    SDL_Texture* loadedTexture = nullptr;
    // Turn the path relative to the assets folder into one
    // relative to the executable working directory.
    filePath = ASSETS_PATH + filePath;

    if (Resources::loadedTextures.count(filePath) == 0)
    {
        // We didn't load this texture yet, read from disk
        std::cout << "Loading texture " << filePath << "\n";

        // Read the texture from disk
        // TODO: Clean up this function
        std::vector<char> buffer;

        File textureFile(filePath);

        SDL_RWops* data = nullptr;

        if (textureFile.Read(buffer) && !buffer.empty())
        {
            data = SDL_RWFromMem(buffer.data(), buffer.size());
        }

        if (data != nullptr)
        {
            // Load the texture
            loadedTexture = IMG_LoadTexture_RW(Window::GetRenderer(), data, 0);
        }

        // Process the loaded texture
        if (loadedTexture != nullptr)
        {
            // If we successfully loaded the texture, write it to our texture cache.
            Resources::loadedTextures[filePath] = loadedTexture;
        }
        else
        {
            std::cerr << "!! [ERROR] !! Failed to access file at \"" << filePath << "\" \n";

            if (Window::GetRenderer() == nullptr)
            {
                std::cerr << " The window's renderer is null. \n"; 
            }
        }
    }
    else
    {
        // Retrieve the texture from the cache
        loadedTexture = Resources::loadedTextures[filePath];
    }

    return loadedTexture;
}

void Resources::UnloadTexture(std::string filePath)
{
    // Check if the texture is currently loaded
    if (Resources::loadedTextures.count(filePath) != 0)
    {
        SDL_Texture* texture = Resources::loadedTextures[filePath];
        
        SDL_DestroyTexture(texture);
    }

    // Erase all instances
    Resources::loadedTextures.erase(filePath);
}