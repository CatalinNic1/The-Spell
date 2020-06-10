#include "TileEditor/TileEditor.hpp"
#include "EngineLogic/CentralStuff/GlobalVariables.hpp"

int main()
{
    AppWindow.create(sf::VideoMode(1280, 768), "app", sf::Style::Default);
    AppWindow.setVerticalSyncEnabled(true);
    TileEditor MapEditor;
    MapEditor.Work();
    return 0;
}