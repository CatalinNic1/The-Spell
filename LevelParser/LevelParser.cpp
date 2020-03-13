#include <iostream>

#include "LevelParser.hpp"

bool LevelParser::openFile(const std::string& FileName)
{
    Reader.close();
    Reader.open(FileName);

    if(!Reader.is_open())
    {
        std::cerr << "File: " + FileName + " couldn't be opened\n";
        return false;
    }

    Root.clear();
    ResourceManager::RemoveOrphans();
    
    try
    {
        Reader >> Root;
    }
    catch(std::exception& Exception)
    {
        std::cerr << Exception.what() << "\n";
        return false;
    }

    return true;
}

Player LevelParser::loadPlayer()
{
    return Player
    (
        sf::Vector2f(Root["Map"]["Player"]["Position"][0].asFloat(), Root["Map"]["Player"]["Position"][1].asFloat()), 
        sf::Vector2f(Root["Map"]["Player"]["Size"][0].asFloat(), Root["Map"]["Player"]["Size"][1].asFloat()),
        Root["Map"]["Player"]["FileName"].asString()
    );
}

bool LevelParser::loadEnemies(std::vector< std::unique_ptr< Enemy > >& Enemies)
{
    Enemy::Type EnemyType;
    
    for(Json::Value& Val : Root["Map"]["Enemies"])
    {
        try
        {
            EnemyType = static_cast< Enemy::Type >(Val[0].asInt());

            if(EnemyType == Enemy::Type::Basic)
            {
                Enemies.emplace_back(std::make_unique< BasicEnemy >
                (
                    sf::Vector2f(Val[1].asFloat(), Val[2].asFloat()), 
                    sf::Vector2f(Val[3].asFloat(), Val[4].asFloat()),
                    Val[5].asString()
                ));
            }
            else if(EnemyType == Enemy::Type::Intelligent)
            {
                Enemies.emplace_back(std::make_unique< IntelligentEnemy >
                (
                    sf::Vector2f(Val[1].asFloat(), Val[2].asFloat()), 
                    sf::Vector2f(Val[3].asFloat(), Val[4].asFloat()),
                    Val[5].asString()
                ));
            }
            else
                throw std::runtime_error("Unknown Type of Enemy");
        }
        catch(std::exception& Exception)
        {
            std::cerr << Exception.what() << "\n";
            Enemies.clear();
            return false;
        }
    }

    return true;
}

bool LevelParser::loadBackground(TileMap& Background)
{
    std::vector< TileInfo > BackgroundInfo;

    try
    {
        std::string TileSetFileName = Root["Map"]["Background"]["FileName"].asString();
        sf::Vector2f TileSize = sf::Vector2f
        (
            Root["Map"]["Background"]["TileSize"][0].asFloat(),
            Root["Map"]["Background"]["TileSize"][1].asFloat()
        );
        sf::Vector2u BackgroundSize = sf::Vector2u
        (
            Root["Map"]["Background"]["Size"][0].asUInt(),
            Root["Map"]["Background"]["Size"][1].asUInt()
        );

        for(Json::Value& Val : Root["Map"]["Background"]["Info"])
        {
            BackgroundInfo.emplace_back
            (
                sf::Vector2f(Val[0].asFloat(), Val[1].asFloat()),
                static_cast< Rotation >(Val[2].asInt())
            );
        }

        Background.setTileSize(TileSize);
        Background.setMapSize(BackgroundSize);

        if(!Background.loadTileMap(TileSetFileName, BackgroundInfo))
        {
            throw std::runtime_error("Loading Went Wrong");
        }
        
    }
    catch(const std::exception& Exception)
    {
        std::cerr << Exception.what() << '\n';
        return false;
    }

    return true;
}