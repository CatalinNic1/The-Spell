#include "Player/Player.hpp"
#include "CentralStuff/GUIWrapper.hpp"
#include "BigRect/BigRect.hpp"
#include "CentralStuff/GUIWrapper.hpp"

int main()
{
    AppWindow.create(sf::VideoMode(800, 600), "app");
    Player Player({628.f, 368.f}, {24.f, 32.f}, "Resources/Player.png");
    BigRect Map;
    Map.loadFromFile("Resources/Thevillage.png");
    while(AppWindow.isOpen())
    {
        while(AppWindow.pollEvent(AppEvent))
        {
            if(AppEvent.type == sf::Event::Closed)
                AppWindow.close();
            else if(AppEvent.type == sf::Event::Resized)
                Player.setViewSize({static_cast<float>(AppEvent.size.width), 
                static_cast<float>(AppEvent.size.height)});
        }
        AppWindow.clear();
        Player.Update(AppClock.restart().asSeconds());
        AppWindow.setView(Player.getPlayerView());
        Map.draw();
        AppWindow.draw(Player.EntityRect);
        AppWindow.display();
    }
    return 0;
}