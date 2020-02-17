#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

#include "BigRect.hpp"

bool BigRect::loadFromFile(const std::string& fileName)
{
    const uint maxSize = sf::Texture::getMaximumSize();
    bool NeedsToCrop = false;

    sf::Image BigImage;
    BigImage.loadFromFile(fileName);
    imageSize = BigImage.getSize();

    if(imageSize.x > maxSize || imageSize.y > maxSize)
        NeedsToCrop = true;

    for(uint x = 0u; x < imageSize.x; x += maxSize)
        for(uint y = 0u; y < imageSize.y; y += maxSize)
        {
            std::pair< sf::RectangleShape, std::shared_ptr< sf::Texture > > Rect;

            try
            {
                if(NeedsToCrop)
                {
                    Rect.second = ResourceManager::Acquire(fileName, sf::IntRect(static_cast< int >(x), 
                    static_cast< int >(y), static_cast< int >(maxSize), static_cast< int >(maxSize)));
                }
                else
                {
                    Rect.second = ResourceManager::Acquire(fileName);
                }
            }
            catch(const std::exception& Exception)
            {
                std::cerr << Exception.what() << "\n";
                return false;
            }
            
            Rect.first.setPosition(static_cast< float >(x), static_cast< float >(y));  
            Rect.first.setSize(static_cast< sf::Vector2f >(Rect.second->getSize()));
            Rect.first.setTexture(Rect.second.get());

            BigRects.emplace_back(Rect);
        }
    return true;
}
void BigRect::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto& Rect : BigRects)
        target.draw(Rect.first, states);
}
sf::Vector2f BigRect::getSize()
{
    return static_cast< sf::Vector2f >(imageSize);
    std::cout << "Harta: " << imageSize.x << " " << imageSize.y << "/n";
}