#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../ResourceManager/ResourceManager.hpp"

class BigRect : public sf::Drawable 
{
public:
    ///
    ///
    ///
    bool loadFromFile(const std::string& fileName);
    //
    sf::Vector2f getSize();
private:
    ///
    ///
    ///
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    //
    class std::vector< std::pair< sf::RectangleShape, std::shared_ptr< sf::Texture > > > BigRects;
    //
    sf::Vector2u imageSize;
};
