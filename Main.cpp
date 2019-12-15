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
        Player.CheckCollision(sf::FloatRect({0, 0}, {1280, 768}), false, Entity::CollisionTypes::Inwards);
        Player.UpdateCamera();
        AppWindow.setView(Player.getPlayerCamera());
        Map.draw();
        AppWindow.draw(Player.EntityRect);
        AppWindow.display();
    }
    return 0;
}