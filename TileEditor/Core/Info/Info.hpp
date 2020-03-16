#pragma once 

#include <json/json.h>

#include "../TileMap/TileMap.hpp"
#include "../Enemy/Core/Enemy.hpp"
#include "../Player/Player.hpp"

class Info
{
private:
    //
    sf::Vector2u LayerSize;
    //
    sf::Vector2f TileSize;
    //
    std::vector< std::vector< TileInfo > > Layers;
    //
    std::vector< EnemyInfo > Enemies;
    //
    std::unique_ptr< PlayerInfo > Player;
public:
    ///
    ///
    ///
    void AddLayer(const sf::Vector2u& LSize, const sf::Vector2f& TSize);
    ///
    ///
    ///
    void AddEnemy(const EnemyInfo& Info);
    ///
    ///
    ///
};
