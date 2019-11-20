#include "BigRect.hpp"
#include "../CentralStuff/GUIWrapper.hpp"

void BigRect::loadFromFile(std::string fileName)
{
    const uint maxSize = sf::Texture::getMaximumSize();
    
        sf::Image BigImage;
    BigImage.loadFromFile(fileName);
    imageSize = BigImage.getSize();

    for(uint x = 0u; x < imageSize.x; x += maxSize)
        for(uint y = 0u; y < imageSize.y; y += maxSize)
        {
            std::pair< sf::RectangleShape, std::shared_ptr< sf::Texture > > Rect;

            Rect.second = ResourceManager::Acquire(fileName, sf::IntRect(static_cast<int>(x), 
            static_cast<int>(y), static_cast<int>(maxSize), static_cast<int>(maxSize)));

            Rect.first.setPosition(static_cast<float>(x), static_cast<float>(y));  
            Rect.first.setSize(static_cast<sf::Vector2f>(Rect.second->getSize()));
            Rect.first.setTexture(Rect.second.get());

            BigRects.emplace_back(Rect);
        }
}
void BigRect::draw()
{
    for(std::pair< sf::RectangleShape, std::shared_ptr< sf::Texture > > Rect : BigRects)
        AppWindow.draw(Rect.first);
}