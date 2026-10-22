#pragma once
#include <map>
#include <string>
#include <SDL.h>
#include <vector>
#include "Singleton.h"
#include "Texture.h"

class TextureManager : public Singleton<TextureManager> {
  friend class Singleton<TextureManager>;

public:

  bool LoadTexture(const std::string& id, const std::string& path);
  Texture* GetTexture(const std::string& id);

  int GetTextureWidth(const std::string& id);
  int GetTextureHeight(const std::string& id);

  void FreeTextures();

  bool LoadAllTextures(const std::vector<std::pair<std::string, std::string>>& texturesToLoad);

private:

  TextureManager() {} // Constructor is private due to Singleton
  ~TextureManager() { FreeTextures(); } // Destructor to ensure cleanup

  std::map<std::string, Texture*> m_textures; // Map of texture IDs to Texture objects
};