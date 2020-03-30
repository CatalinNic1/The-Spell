#include "Setup.hpp"
#include "../Core/Widgets/Creators/Creators.hpp"
#include "../../CentralStuff/GlobalVariables.hpp"

void Setup::CreatePlayerInterface()
{
    PlayerInfo PlayerInformation;
    sf::Vector2f SetupWindowSize;

    tgui::ChildWindow::Ptr SetupWindow = Creators::CreateChildWindow
    (
        Getters::getCenterScale({200, 300}),
        Getters::getScale({250, 350}),
        "Player Setup"
    );
    CentralGui.add(SetupWindow);
    SetupWindowSize = SetupWindow->getSize();
    
    tgui::EditBox::Ptr PosX = Creators::CreateEditBox
    (
        Getters::getScale({25, 50}, SetupWindowSize), 
        Getters::getScale({75, 25}, SetupWindowSize), 
        "Pos.x",
        Signals::EditBox::TextChanged,
        InputType::Float,
        PlayerInformation.Position.x
    );
    SetupWindow->add(PosX);

    tgui::EditBox::Ptr PosY = Creators::CreateEditBox
    (
        Getters::getScale({150, 50}, SetupWindowSize), 
        Getters::getScale({75, 25}, SetupWindowSize), 
        "Pos.y",
        Signals::EditBox::TextChanged,
        InputType::Float,
        PlayerInformation.Position.y
    );
    SetupWindow->add(PosY);

    tgui::EditBox::Ptr SizeX = Creators::CreateEditBox
    (
        Getters::getScale({25, 125}, SetupWindowSize),
        Getters::getScale({75, 25}, SetupWindowSize),
        "Size.x",
        Signals::EditBox::TextChanged,
        InputType::Float,
        PlayerInformation.Size.x
    );
    SetupWindow->add(SizeX);

    tgui::EditBox::Ptr SizeY = Creators::CreateEditBox
    (
        Getters::getScale({150, 125}, SetupWindowSize),
        Getters::getScale({75, 25}, SetupWindowSize),
        "Size.y",
        Signals::EditBox::TextChanged,
        InputType::Float,
        PlayerInformation.Size.y
    );
    SetupWindow->add(SizeY);

    tgui::EditBox::Ptr TextureFilename = Creators::CreateEditBox
    (
        Getters::getScale({25, 200}, SetupWindowSize),
        Getters::getScale({200, 25}, SetupWindowSize),
        "Texture Filename",
        Signals::EditBox::TextChanged,
        InputType::String,
        PlayerInformation.TextureFilename
    );
    SetupWindow->add(TextureFilename);

    tgui::Button::Ptr CreatePlayer = Creators::CreateButton
    (
        Getters::getScale({110, 310}, SetupWindowSize),
        Getters::getScale({50, 30}, SetupWindowSize),
        "Create",
        Signals::Button::Pressed,
        Informations.SetPlayer,
        std::ref(PlayerInformation)
    );
    SetupWindow->add(CreatePlayer);
}

Setup::Setup() 
    : CentralGui(AppWindow)
{}

void Setup::drawGui()
{
    CentralGui.draw();
}

bool Setup::handleGuiEvent(const sf::Event& Event)
{
    CentralGui.handleEvent(Event);
}