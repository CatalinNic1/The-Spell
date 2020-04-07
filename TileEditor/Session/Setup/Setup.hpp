#pragma once

#include <TGUI/TGUI.hpp>

#include "../Core/Info/Info.hpp"

class Setup
{
private:
    //
    Info Informations;
    //
    PlayerInfo PlayerInfoTemp;
    //
    EnemyInfo EnemyInfoTemp;
    //
    tgui::Gui CentralGui;
    ///
    ///
    ///
    void CreatePlayerInterface();
    ///
    ///
    ///
    void CreateEnemyInterface();
    ///
    ///
    ///
    void CreateTileInterface();
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
};
