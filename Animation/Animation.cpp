#include <SFML/Graphics/Image.hpp>

#include "Animation.hpp"
#include "../CentralStuff/TypeDefs.hpp"
#include "../ResourceManager/ResourceManager.hpp"

void Animation::Animate(sf::RectangleShape& EntityRect, Actions Action)
{
    sf::Vector2f FrameSize = EntityRect.getSize();
    
    if(Action == Actions::None || CurrentFrame == FrameLimit)
        CurrentFrame = 0;

    if(Action != Actions::None && Action != CurrentAction)
    {
        CurrentFrame = 0;
        CurrentAction = Action;
    }
    
    if(NeedsToLoad == true)
    {
        ResourceManager::RemoveOrphans();
        AnimTexture = ResourceManager::Acquire(FileName, 
        sf::IntRect(CurrentFrame * static_cast<int>(FrameSize.x), 
        static_cast<int>(CurrentAction) * static_cast<int>(FrameSize.y), 
        static_cast<int>(FrameSize.x), static_cast<int>(FrameSize.y)));
    }
    else
    {
        EntityRect.setTextureRect(sf::IntRect(CurrentFrame * static_cast<int>(FrameSize.x), 
        static_cast<int>(CurrentAction) * static_cast<int>(FrameSize.y), 
        static_cast<int>(FrameSize.x), static_cast<int>(FrameSize.y)));
    }
    
    CurrentFrame++;
}

void Animation::setFrameLimit(const std::string& TextureFileName, int HorizontalFrameNumber)
{
    sf::Image Im;
    
    Im.loadFromFile(TextureFileName);
    sf::Vector2u TextureSize = Im.getSize();
    
    FrameLimit = static_cast<int>(TextureSize.x) / HorizontalFrameNumber;
    if(TextureSize.x > TextureMinSize || TextureSize.y > TextureMinSize)
    {
        NeedsToLoad = true;
        FileName = TextureFileName;
    }
}