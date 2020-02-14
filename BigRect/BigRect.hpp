#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../ResourceManager/ResourceManager.hpp"

// This a classed used bc there is too little impementation for tiles
class BigRect : public sf::Drawable 
{
public:
    ///
    /// @brief Loads a file into one or multiple rectangles, depends on GPU max texture size support (used only for static objects)
    ///
    /// @param fileName - Path of the image to be loaded
    ///
    /// @return A confirmation or infirmation that the file is loaded;
    ///
    bool loadFromFile(const std::string& fileName);
    ///
    /// @brief Gets the whole size of the file
    /// 
    /// @return The size exprimated in sf::Vector2f
    ///
    sf::Vector2f getSize();
private:
    /// @brief Draw the object to a render target
    ///
    /// @param target Render target to draw to
    ///
    /// @param states Current render states
    ///
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    // This is where the rects and the textures will be used in drawing
    class std::vector< std::pair< sf::RectangleShape, std::shared_ptr< sf::Texture > > > BigRects;
    // The size of the whole image
    sf::Vector2u imageSize;
};
