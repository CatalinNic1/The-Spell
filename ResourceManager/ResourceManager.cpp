#include "ResourceManager.hpp"

std::shared_ptr< sf::Texture > ResourceManager::Acquire(const std::string& TextureFileName)
{
    TextureMapIter = TextureMap.find(TextureFileName);
    if(TextureMapIter != TextureMap.end())
        return TextureMapIter->second;
    else
    {
        std::shared_ptr< sf::Texture > PtrTexture = std::make_shared< sf::Texture >();
        PtrTexture->loadFromFile(TextureFileName);
        PtrTexture->setSmooth(false);
        TextureMap.insert({TextureFileName, PtrTexture});
        return PtrTexture;
    }
}

std::shared_ptr< sf::Texture > ResourceManager::Acquire(const std::string& TextureFileName, sf::IntRect TextureArea)
{
    TextureMapIter = TextureMap.find(TextureFileName);
    if(TextureMapIter != TextureMap.end())
        return TextureMapIter->second;
    else
    {
        std::shared_ptr< sf::Texture > PtrTexture = std::make_shared< sf::Texture >();
        PtrTexture->loadFromFile(TextureFileName, TextureArea);
        PtrTexture->setSmooth(false);
        TextureMap.insert({TextureFileName, PtrTexture});
        return PtrTexture;
    }
}

void ResourceManager::RemoveOrphans()
{
    for(TextureMapIter = TextureMap.begin(); TextureMapIter != TextureMap.end();)
    {
        if(TextureMapIter->second.use_count() == 1)
            TextureMapIter = TextureMap.erase(TextureMapIter);
        else
            TextureMapIter++;
    }
}

void ResourceManager::Clear()
{
    TextureMap.clear();
}