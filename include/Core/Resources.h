#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

class Resources
{
	public:
	const static std::string ASSETS_PATH;

	/**
	 * @brief Load a texture from disk
	 *
	 * @param filePath Path relative to assets folder.
	 * @return SDL_Texture*
	 */
	static auto GetTexture(std::string filePath) -> SDL_Texture*;

	/**
	 * @brief Unload a texture from disk
	 *
	 * @param filePath Path relative to assets folder.
	 */
	static void UnloadTexture(std::string filePath);

	private:

	// Resource cache
	static std::unordered_map<std::string, SDL_Texture*> loadedTextures;

	static std::string GetAssetFilePath(const std::string& relativePath);
	static auto LoadTextureFromFile(const std::string& filePath) -> SDL_Texture*;
};

#endif // RESOURCES_H