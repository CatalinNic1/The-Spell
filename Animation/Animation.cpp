#include "Animation.hpp"

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
    
    EntityRect.setTextureRect(sf::IntRect(CurrentFrame * static_cast<int>(FrameSize.x), 
    static_cast<int>(CurrentAction) * static_cast<int>(FrameSize.y), 
    static_cast<int>(FrameSize.x), static_cast<int>(FrameSize.y)));
    CurrentFrame++;
}

void Animation::setFrameLimit(float TextureWidth, int HorizontalFrameNumber)
{
    FrameLimit = static_cast<int>(TextureWidth) / HorizontalFrameNumber;
}