#pragma once

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

class MapTile : public sf::Drawable
{
private:
    //
    sf::VertexArray Tile;
    //
    bool Drawable = true;
    //
    enum class Corners
    {
        TopRight,
        TopLeft,
        BottomLeft,
        BottomRight
    };
    //
    class std::shared_ptr< sf::Texture > TileTexture;
    ///
    ///
    ///
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    ///
    ///
    ///
    bool CollidesWithCorner(sf::FloatRect Structure, Corners Corner);
public:
    ///
    ///
    ///
    void CheckStructureCollision(sf::FloatRect Structure);
    ///
    ///
    ///
    void CheckCameraCollision(sf::FloatRect Camera);
    ///
    ///
    ///
    bool loadTile(const std::string& TileSetFileName, const sf::Vector2f& TexturePosition = sf::Vector2f());
    ///
    ///
    ///
    MapTile(sf::Vector2f TilePosition);
};


