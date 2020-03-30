#pragma once

#include <TGUI/TGUI.hpp>

#include "../Core/Info/Info.hpp"

class Setup
{
private:
    //
    Info Informations;
    //
    tgui::Gui CentralGui;
public:
    ///
    ///
    ///
    Setup();
    ///
    ///
    ///
    void drawGui();
    ///
    ///
    ///
    bool handleGuiEvent(const sf::Event& Event);
    ///
    ///
    ///
    void CreatePlayerInterface();
    ///
    ///
    ///
    void CreateEnemyInterface();
};
