#include <filesystem>
#include <iostream>

#include "Info.hpp"

bool Info::SizeVerification(const sf::Vector2f& Size)
{
    return (Size.x <= 0.f || Size.y <= 0.f);
}

sf::Vector2f& Info::getTileSize()
{
    return TileSize;
}

sf::Vector2u& Info::getMapSize()
{
    return LayerSize;
}

bool Info::FileVerification(const std::string& Filename)
{
    try
    {
        return std::filesystem::exists(Filename);
    }
    catch(std::exception& Exception)
    {
        std::cerr << Exception.what() << '\n';
        return false;
    }
}

bool Info::AddLayer(const sf::Vector2u& LSize, const sf::Vector2f& TSize, const std::string& Tileset)
{
    if(SizeVerification(sf::Vector2f(LSize)) == false)
    {
        std::cerr << "Error [Info::AddLayer]: Invalid Layer Size\n";
        return false;
    }
    if(SizeVerification(TSize) == false)
    {
        std::cerr << "Error [Info::AddLayer]: Invalid Tile Size\n";
        return false;
    }
    if(FileVerification)
    {
        std::cerr << "Error [Info::AddLayer]: Texture File Not Found\n";
        return false;
    }

    LayerSize = LSize;
    TileSize = TSize;
        
    std::vector< TileInfo > Layer;
    Layer.resize(LayerSize.x * LayerSize.y);
        
    std::fill(Layer.begin(), Layer.end(), TileInfo({-1.f, -1.f}, static_cast< Rotation >(0)));
    Layers.emplace_back(Tileset, Layer);
    return true;
}

bool Info::AddEnemy(const EnemyInfo& Info)
{
    if(SizeVerification(Info.Size) == false)
    {
        std::cerr << "Error [Info::AddEnemy]: Invalid Size\n";
        return false;
    }
    if(FileVerification(Info.TextureFilename) == false)
    {
        std::cerr << "Error [Info::AddEnemy]: File Not Found\n";
        return false;
    }

    Enemies.emplace_back(Info);
    return true;
}

bool Info::SetPlayer(const PlayerInfo& Info)
{
    if(SizeVerification(Info.Size) == false)
    {
        std::cerr << "Error [Info::AddEnemy]: Invalid Size\n";
        return false;
    }
    if(FileVerification(Info.TextureFilename) == false)
    {
        std::cerr << "Error [Info::AddEnemy]: File Not Found\n";
        return false;
    }

    Player = Info;
    return true;
}