#pragma once

#include <TGUI/TGUI.hpp>

#include "../../Core/Widgets/Creators/Creators.hpp"
#include "../../Core/Info/Info.hpp"

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
    CanvasUpdater UpdatePool;
    //
    std::string MapFilename;
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
    ///
    ///
    ///
    void CreateEditorMenubar();
    ///
    ///
    ///
    static void Clear(const sf::Color& Color = sf::Color::Black);
    ///
    ///
    ///
    static void Display();
public:
    ///
    ///
    ///
    Setup();
    ///
    ///
    ///
    void draw();
    ///
    ///
    ///
    bool handleGuiEvent(const sf::Event& Event);
    ///
    ///
    ///
    void RemoveOrphans();
    ///
    ///
    ///
    static bool IsOpen();
    ///
    ///
    ///
    static bool PollEvent(sf::Event& Event);
    ///
    ///
    ///
    static void Exit();
};
