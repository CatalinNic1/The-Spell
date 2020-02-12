#pragma once

#include <TGUI/TGUI.hpp>
#include <vector>

// This class will be used to store
// componets like: RenderWindow and GUI class
class AppCore
{
public:
    static inline sf::RenderWindow AppWindow;
    static inline tgui::Gui AppGui;
    static inline sf::Clock AppClock;
    static inline sf::Event AppEvent;
    static inline float DeltaTime;
};

#define AppWindow AppCore::AppWindow
#define AppClock AppCore::AppClock
#define AppEvent AppCore::AppEvent
#define AppGui AppCore::AppGui
#define DeltaTime AppCore::DeltaTime

void SleepWindow();

void SleepWindow()
{
    while(AppWindow.isOpen())
    {
        while(AppWindow.pollEvent(AppEvent))
        {
            if(AppEvent.type == sf::Event::GainedFocus)
                return;
        }
    }
}