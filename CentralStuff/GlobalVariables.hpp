#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

// This class will be used to store
// componets like: RenderWindow and GUI class
class AppCore
{
public:
    static inline sf::RenderWindow AppWindow;
    static inline sf::Clock AppClock;
    static inline sf::Event AppEvent;
    static inline float DeltaTime;
};

// sf::RenderWindow global interface
#define AppWindow AppCore::AppWindow
// sf::Clock global interface
#define AppClock AppCore::AppClock
// sf::Event global interface
#define AppEvent AppCore::AppEvent
// Global interface for thie between frames
#define DeltaTime AppCore::DeltaTime

///
/// @brief Sleep function when unfocused 
///
void SleepWindow();

void SleepWindow()
{
    while(AppWindow.isOpen())
    {
        while(AppWindow.pollEvent(AppEvent))
        {
            if(AppEvent.type == sf::Event::GainedFocus)
                return;
            if(AppEvent.type == sf::Event::Closed)
            {
                AppWindow.close();
                return;
            }
        }
    }
}