#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../ResourceManager/ResourceManager.hpp"

class BigRect
{
public:
    void draw();
    void loadFromFile(std::string fileName);
private:
    class std::vector< std::pair< sf::RectangleShape, std::shared_ptr< sf::Texture > > > BigRects;
    sf::Vector2u imageSize;
};
