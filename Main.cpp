#include "Player/Player.hpp"
#include "CentralStuff/GUIWrapper.hpp"
#include "BigRect/BigRect.hpp"
#include "CentralStuff/GUIWrapper.hpp"

int main()
{
    AppWindow.create(sf::VideoMode(800, 600), "app", sf::Style::Default);
    AppWindow.setVerticalSyncEnabled(true);
    
    Player Player({628, 368}, {24, 32}, "Resources/Player.png");
    Player.setCameraSize({800, 600});
    Player.setLevelLimits({1280, 768});

    SmartRect Cage;
    Cage.setPosition(600, 400);
    Cage.setSize({50, 50});
    Cage.setFillColor(sf::Color(123, 231, 43));

    BigRect Map;
    Map.loadFromFile("Resources/Thevillage.png");

    while(AppWindow.isOpen())
    {
        while(AppWindow.pollEvent(AppEvent))
        {
            if(AppEvent.type == sf::Event::Closed)
                AppWindow.close();
            else if(AppEvent.type == sf::Event::Resized)
                Player.setCameraSize({static_cast<float>(AppEvent.size.width), 
                static_cast<float>(AppEvent.size.height)});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            AppWindow.close();
        AppWindow.clear();
        DeltaTime = AppClock.restart().asSeconds();
        Player.Update(DeltaTime);
        Cage.moveRect(DeltaTime, SmartRect::Directions::Up, 0.1f);
        Player.EntityRect.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
        Player.EntityRect.CheckCollision(Cage, SmartRect::CollisionTypes::Outwards);
        Cage.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}));
        Player.UpdateCamera();
        AppWindow.setView(Player.getPlayerCamera());
        Map.draw();
        AppWindow.draw(Cage);
        AppWindow.draw(Player.EntityRect);
        AppWindow.display();
    }
    return 0;
}