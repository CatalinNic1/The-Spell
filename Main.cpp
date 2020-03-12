#include "TileMap/TileMap.hpp"
#include "Player/Player.hpp"
#include "Enemy/IntelligentEnemy/IntelligentEnemy.hpp"
#include "CentralStuff/GlobalVariables.hpp"
#include "BigRect/BigRect.hpp"
#include "CentralStuff/Random.hpp"

int main()
{
    AppWindow.create(sf::VideoMode(800, 600), "app", sf::Style::Default);
    AppWindow.setVerticalSyncEnabled(true);

    std::vector< TileInfo > Test =
    {
        {{384.f, 96.f}, Rotation::QuadrantI}, {{416.f, 96.f}, Rotation::QuadrantI},  {{448.f, 96.f}, Rotation::QuadrantI},
        {{384.f, 128.f}, Rotation::QuadrantI}, {{416.f, 128.f}, Rotation::QuadrantI}, {{448.f, 128.f}, Rotation::QuadrantI},
        {{384.f, 160.f}, Rotation::QuadrantI}, {{416.f, 160.f}, Rotation::QuadrantI}, {{448.f, 160.f}, Rotation::QuadrantI}
    };

    TileMap Map;

    Map.setTileSize(TileSize);
    Map.setMapSize({3, 3});
    
    if(!Map.loadTileMap("Tilesets/PathAndObjects.png", Test))
    {
        printf("Failed to Load\n");
        return EXIT_FAILURE;
    }

    /*Player Player({650, 540}, {24, 32}, "Resources/Player.png");
    Player.setCameraSize({800, 600});
    Player.setLevelLimits({1280, 768});

    SmartRect Cage;
    Cage.setPosition(600, 400);
    Cage.setSize({300, 25});
    Cage.setFillColor(sf::Color(RandomIntegral< sf::Uint8 >::getRandom(255),
                                RandomIntegral< sf::Uint8 >::getRandom(255), 
                                RandomIntegral< sf::Uint8 >::getRandom(255)));

    BigRect Map;
    Map.loadFromFile("Resources/Thevillage.png");

    std::vector< IntelligentEnemy > Enemies;

    for(int i = 1; i <= 1; i++)
    {
        IntelligentEnemy E({RandomReal< float >::getRandom(600), RandomReal< float >::getRandom(600)}, {24, 32}, "Resources/BasicEnemy.png");
        Enemies.emplace_back(E);include "../CentralStuff/TypeDefs.hpp
    }*/

    while(AppWindow.isOpen())
    {
        while(AppWindow.pollEvent(AppEvent))
        {
            if(AppEvent.type == sf::Event::Closed)
                AppWindow.close();
            else if(AppEvent.type == sf::Event::LostFocus)
                SleepWindow();
            else if(AppEvent.type == sf::Event::Resized)
            {
                //Player.setCameraSize({static_cast< float >(AppEvent.size.width),
                //static_cast< float >(AppEvent.size.height)});
            }
        }
        AppWindow.clear();
        DeltaTime = AppClock.restart().asSeconds();
        /*Player.Update(DeltaTime);
        IntelligentEnemy::setDestinationPos(Player.EntityRect.getPosition());

        for(IntelligentEnemy& E : Enemies)
        {
            E.Update(DeltaTime);
                        
            Player.EntityRect.CheckCollision(E.EntityRect, SmartRect::CollisionTypes::Outwards);
            Player.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
            
            Player.EntityRect.CheckCollision(Cage, SmartRect::CollisionTypes::Outwards);
            if(E.EntityRect.CheckCollision(Cage, SmartRect::CollisionTypes::Outwards))
                E.setObstcaleInfo(Cage.getGlobalBounds());
            
            E.EntityRect.CheckCollision(Player.EntityRect, SmartRect::CollisionTypes::Outwards);
            E.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
        }
        
        Player.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));

        Player.UpdateCamera();
        AppWindow.setView(Player.getPlayerCamera());*
        AppWindow.draw(Map);

        if(getPerspective().intersects(Cage.getGlobalBounds()))
            AppWindow.draw(Cage);

        for(IntelligentEnemy& E : Enemies)
            if(getPerspective().intersects(E.EntityRect.getGlobalBounds()))
                AppWindow.draw(E.EntityRect);

        AppWindow.draw(Player.EntityRect);*/
        AppWindow.draw(Map);
        AppWindow.display();
    }
    return 0;
}