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
const std::string Resources::ASSETS_PATH = "../assets/";

std::unordered_map<std::string, SDL_Texture*> Resources::loadedTextures;

auto Resources::GetTexture(std::string filePath) -> SDL_Texture*
{
	filePath = Resources::GetAssetFilePath(filePath);

	// If we have the texture already loaded in memory, return it
	if (Resources::loadedTextures.count(filePath) > 0)
	{
		return Resources::loadedTextures[filePath];
	}

	// Otherwise, load the texture from disk
	return Resources::LoadTextureFromFile(filePath);
}

std::string Resources::GetAssetFilePath(const std::string& relativePath)
{
	return Resources::ASSETS_PATH + relativePath;
}

SDL_Texture* Resources::LoadTextureFromFile(const std::string& filePath)
{
	SDL_Texture* loadedTexture = nullptr;

	std::cout << "Loading texture " << filePath << "\n";

	std::vector<char> buffer;
	File textureFile(filePath);

	SDL_RWops* data = nullptr;

    if (!textureFile.Read(buffer) || buffer.empty())
	{
		std::cerr << "!! [ERROR] !! Failed to read texture file at \"" << filePath << "\" \n";
		return nullptr;
	}

	data = SDL_RWFromMem(buffer.data(), buffer.size());

	if (data == nullptr)
	{
		std::cerr << "!! [ERROR] !! Failed to create SDL_RWops from memory for file \"" << filePath
							<< "\" \n";
		return nullptr;
	}

	loadedTexture = IMG_LoadTexture_RW(Window::GetRenderer(), data, 0);

	if (loadedTexture == nullptr)
	{
		std::cerr << "!! [ERROR] !! Failed to load texture from file \"" << filePath << "\" \n";
		return nullptr;
	}

	// Cache the loaded texture
	Resources::loadedTextures[filePath] = loadedTexture;

	return loadedTexture;
}

void Resources::UnloadTexture(std::string filePath)
{
	if (Resources::loadedTextures.count(filePath) == 0)
	{
		// We did not have the texture loaded already
		// TODO: Shoudl this give an error?
		return;
	}

	SDL_Texture* texture = Resources::loadedTextures[filePath];

	// Destroy the texture
	SDL_DestroyTexture(texture);

	// Clear our cache of this texture
	Resources::loadedTextures.erase(filePath);
}