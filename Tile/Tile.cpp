#include <iostream>

#include "Tile.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "../CentralStuff/TypeDefs.hpp"

typedef unsigned int uint;

MapTile::MapTile(sf::Vector2f TilePosition) : Tile(sf::PrimitiveType::Quads, 4)
{
    Tile[static_cast< int >(Corners::TopRight)].position = {TilePosition};
    Tile[static_cast< int >(Corners::TopLeft)].position = {TilePosition.x + TileSize.x, TilePosition.y};
    Tile[static_cast< int >(Corners::BottomLeft)].position = {TilePosition + TileSize};
    Tile[static_cast< int >(Corners::BottomRight)].position = {TilePosition.x, TilePosition.y + TileSize.y};
}

void MapTile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(Drawable == true)
    {
        states.texture = TileTexture.get();
        target.draw(Tile, states);
    }
}

bool MapTile::loadTile(const std::string& TileSetFileName, const sf::Vector2f& TexturePosition)
{
    try
    {
        TileTexture = ResourceManager::Acquire(TileSetFileName);
    }
    catch(const std::exception& Exeption)
    {
        std::cerr << Exeption.what() << "\n";
        return false;
    }

    Tile[static_cast< int >(Corners::TopRight)].texCoords = {TexturePosition};
    Tile[static_cast< int >(Corners::TopLeft)].texCoords = {TexturePosition.x + TileSize.x, TexturePosition.y};
    Tile[static_cast< int >(Corners::BottomLeft)].texCoords = {TexturePosition + TileSize};
    Tile[static_cast< int >(Corners::BottomRight)].texCoords = {TexturePosition.x, TexturePosition.y + TileSize.y};
    
    return true;
}

void MapTile::CheckStructureCollision(sf::FloatRect Structure)
{
    if(CollidesWithCorner(Structure, Corners::TopRight) && CollidesWithCorner(Structure, Corners::BottomRight) 
    && CollidesWithCorner(Structure, Corners::BottomLeft) && CollidesWithCorner(Structure, Corners::TopLeft))
        Drawable = false;
    else
        Drawable = true;
}

void MapTile::CheckCameraCollision(sf::FloatRect Camera)
{
    if(Camera.intersects(Tile.getBounds()))
        Drawable = true;
    else
        Drawable = false;
}

bool MapTile::CollidesWithCorner(sf::FloatRect Structure, Corners Corner)
{
    return Structure.contains(Tile[static_cast< uint >(Corner)].position);
}