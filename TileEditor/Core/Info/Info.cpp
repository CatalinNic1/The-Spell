#include "Info.hpp"

void Info::AddLayer(const sf::Vector2u& LSize, const sf::Vector2f& TSize)
{
    LayerSize = LSize;
    TileSize = TSize;
        
    std::vector< TileInfo > Layer;
    Layer.resize(LayerSize.x * LayerSize.y);
        
    std::fill(Layer.begin, Layer.end, TileInfo({-1.f, -1.f}, static_cast< Rotation >(0)));
    Layers.emplace_back(Layer);
}

void Info::AddEnemy(const EnemyInfo& Info)
{
    Enemies.emplace_back(Info);
}

void Info::SetPlayer(const PlayerInfo& Info)
{
    Player = Info;
}