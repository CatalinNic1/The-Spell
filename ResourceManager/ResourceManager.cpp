#include "ResourceManager.hpp"
#include "../CentralStuff/CoreFunctions.hpp"
#include "../CentralStuff/TypeDefs.hpp"

#include <iostream>

std::shared_ptr< sf::Texture > ResourceManager::Acquire(const std::string& TextureFileName, const sf::IntRect& TextureArea)
{
    std::string TextureKey;
    if(TextureArea != sf::IntRect())
        TextureKey = getName(TextureFileName) + " " + RectToString(TextureArea);
    else
        TextureKey = getName(TextureFileName);
        
    TextureMapIter = TextureMap.find(TextureKey);

    if(TextureMapIter != TextureMap.end())
        return TextureMapIter->second;
    else
    {
        CheckSize(TextureFileName, TextureArea);
        std::shared_ptr< sf::Texture > PtrTexture = std::make_shared< sf::Texture >();
        if(!PtrTexture->loadFromFile(TextureFileName, TextureArea))
        {
            throw std::runtime_error("File not found");
            return nullptr;
        }
        else
        {
            TextureMap.insert({TextureKey, PtrTexture});
            return PtrTexture;
        }
    }
}

void ResourceManager::CheckSize(const std::string& FileName, const sf::IntRect& Area)
{
    sf::Image Im;
    Im.loadFromFile(FileName);
    if((Im.getSize().x > sf::Texture::getMaximumSize() || Im.getSize().y > sf::Texture::getMaximumSize()) && (Area == sf::IntRect() || (static_cast< uint >(Area.width) > sf::Texture::getMaximumSize() || static_cast< uint >(Area.height) > sf::Texture::getMaximumSize())))
        std::runtime_error("The image is bigger than the minimal size for all GPUs. Consider disabling the mod that you loaded.");
    if((Im.getSize().x > TextureMinSize || Im.getSize().y > TextureMinSize) && (Area == sf::IntRect()))
        std::cout << "Warning: The image is bigger than the minimal size for all GPUs. Please use TileSets with the maximum resolution of 512x512, but if it is an animation, use the Area argument, but to be max 512x512. To ensure maximum compatibility.\n";
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