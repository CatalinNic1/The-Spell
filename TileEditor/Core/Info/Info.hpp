#pragma once 

#include <json/json.h>

#include "../../../EngineLogic/TileMap/TileMap.hpp"
#include "../../../EngineLogic/Enemy/Core/Enemy.hpp"
#include "../../../EngineLogic/Player/Player.hpp"

class Info
{
private:
    //
    sf::Vector2u LayerSize;
    //
    sf::Vector2f TileSize;
    //
    using Layer = std::pair< std::string, std::vector< TileInfo > >;
    //
    std::vector< Layer > Layers;
    //
    std::vector< EnemyInfo > Enemies;
    //
    PlayerInfo Player;
    ///
    ///
    ///
    bool SizeVerification(const sf::Vector2f& Size);
    ///
    ///
    //
    bool FileVerification(const std::string& Filename);
public:
    ///
    ///
    ///
    bool AddLayer(const sf::Vector2u& LSize, const sf::Vector2f& TSize, const std::string& Tileset);
    ///
    ///
    ///
    bool AddEnemy(const EnemyInfo& EnemyInfo);
    ///
    ///
    ///
    bool SetPlayer(const PlayerInfo& PlayerInfo);
    ///
    ///
    ///
    sf::Vector2f& getTileSize();
    ///
    ///
    ///
    sf::Vector2u& getMapSize();
};
