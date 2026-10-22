#include "TextureManager.h"
#include "RenderManager.h" 

bool TextureManager::LoadTexture(const std::string& id, const std::string& path) {
  Texture* newTexture = new Texture;
  if (!newTexture->LoadFromFile(path, RenderManager::GetInstance().getRenderer())) {
    printf("Failed to load texture: %s\n", path.c_str());
    delete newTexture;
    return false;
  }
  m_textures[id] = newTexture;
  return true;
}

Texture* TextureManager::GetTexture(const std::string& id) {
  auto it = m_textures.find(id);
  if (it != m_textures.end()) {
    return it->second;
  }
  return nullptr; //texture not found return null
}

int TextureManager::GetTextureWidth(const std::string& id) {
  auto it = m_textures.find(id);
  if (it != m_textures.end()) {
    return it->second->GetWidth();
  }
  return 0; // Return 0 or handle the error as needed
}

int TextureManager::GetTextureHeight(const std::string& id) {
  auto it = m_textures.find(id);
  if (it != m_textures.end()) {
    return it->second->GetHeight();
  }
  return 0; // Return 0 or handle the error as needed
}


void TextureManager::FreeTextures() {
  for (auto& pair : m_textures) {
    pair.second->Free();
    delete pair.second;
  }
  m_textures.clear();
}

bool TextureManager::LoadAllTextures(const std::vector<std::pair<std::string, std::string>>& texturesToLoad) {
  for (const auto& texture : texturesToLoad) {
    const std::string& id = texture.first;
    const std::string& path = texture.second;

    if (!LoadTexture(id, path)) {
      printf("Failed to load texture: %s\n", id.c_str());
      return false; // Stop loading if any texture fails
    }
  }
  return true;
}