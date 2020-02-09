#include "Player/Player.hpp"
#include "Enemy/BasicEnemy/BasicEnemy.hpp"
#include "CentralStuff/GUIWrapper.hpp"
#include "BigRect/BigRect.hpp"

int main()
{
    AppWindow.create(sf::VideoMode(800, 600), "app", sf::Style::Default);
    AppWindow.setVerticalSyncEnabled(true);

    Player Player({650, 540}, {24, 32}, "Resources/Player.png");
    Player.setCameraSize({800, 600});
    Player.setLevelLimits({1280, 768});

    SmartRect Cage;
    Cage.setPosition(600, 400);
    Cage.setSize({50, 50});
    Cage.setFillColor(sf::Color(233, 123, 31));

    BigRect Map;
    Map.loadFromFile("Resources/Thevillage.png");

    BasicEnemy E({600, 600}, {24, 32}, "Resources/BasicEnemy.png");

    while(AppWindow.isOpen())
    {
        while(AppWindow.pollEvent(AppEvent))
        {
            if(AppEvent.type == sf::Event::Closed)
                AppWindow.close();
            else if(AppEvent.type == sf::Event::LostFocus)
                continue;
            else if(AppEvent.type == sf::Event::Resized)
                Player.setCameraSize({static_cast<float>(AppEvent.size.width),
                static_cast<float>(AppEvent.size.height)});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            AppWindow.close();
        AppWindow.clear();
        DeltaTime = AppClock.restart().asSeconds();
        Player.Update(DeltaTime);
        Cage.moveRect(DeltaTime, SmartRect::Directions::Up, 0.05f);
        E.Update(DeltaTime);

        {
            Player.EntityRect.CheckCollision(Cage, SmartRect::CollisionTypes::Outwards);
            Player.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
            Cage.CheckCollision(Player.EntityRect, SmartRect::CollisionTypes::Outwards);
            Cage.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
        }
        {
            Player.EntityRect.CheckCollision(E.EntityRect, SmartRect::CollisionTypes::Outwards);
            Player.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
            E.EntityRect.CheckCollision(Player.EntityRect, SmartRect::CollisionTypes::Outwards);
            E.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
        }
        {
            E.EntityRect.CheckCollision(Cage, SmartRect::CollisionTypes::Outwards);
            E.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
            Cage.CheckCollision(E.EntityRect, SmartRect::CollisionTypes::Outwards);
            Cage.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
        }

        Player.UpdateCamera();
        AppWindow.setView(Player.getPlayerCamera());
        AppWindow.draw(Map);
        AppWindow.draw(Cage);
        AppWindow.draw(E.EntityRect);
        AppWindow.draw(Player.EntityRect);
        AppWindow.display();
    }
    return 0;
}