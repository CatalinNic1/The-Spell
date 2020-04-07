#include "Setup.hpp"
#include "../Core/Widgets/Creators/Creators.hpp"
#include "../../CentralStuff/GlobalVariables.hpp"

void Setup::CreatePlayerInterface()
{
    sf::Vector2f SetupWindowSize;

    tgui::ChildWindow::Ptr SetupWindow = Creators::CreateChildWindow
    (
        Getters::getCenterScale({250, 300}),
        Getters::getScale({250, 300}),
        "Player Setup"
    );
    CentralGui.add(SetupWindow);
    SetupWindowSize = SetupWindow->getSize();
    
    tgui::Label::Ptr PosLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 25}, SetupWindowSize),
        20, "Player Position"
    );
    SetupWindow->add(PosLabel);

    tgui::EditBox::Ptr PosX = Creators::CreateEditBox
    (
        Getters::getScale({25, 50}, SetupWindowSize), 
        Getters::getScale({75, 25}, SetupWindowSize), "X",
        Signals::EditBox::TextChanged,
        PlayerInfoTemp.Position.x
    );
    SetupWindow->add(PosX);

    tgui::EditBox::Ptr PosY = Creators::CreateEditBox
    (
        Getters::getScale({150, 50}, SetupWindowSize), 
        Getters::getScale({75, 25}, SetupWindowSize), "Y",
        Signals::EditBox::TextChanged,
        PlayerInfoTemp.Position.y
    );
    SetupWindow->add(PosY);

    tgui::Label::Ptr SizeLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 100}, SetupWindowSize),
        20, "Player Size"
    );
    SetupWindow->add(SizeLabel);

    tgui::EditBox::Ptr SizeX = Creators::CreateEditBox
    (
        Getters::getScale({25, 125}, SetupWindowSize),
        Getters::getScale({75, 25}, SetupWindowSize), "X",
        Signals::EditBox::TextChanged,
        PlayerInfoTemp.Size.x
    );
    SetupWindow->add(SizeX);

    tgui::EditBox::Ptr SizeY = Creators::CreateEditBox
    (
        Getters::getScale({150, 125}, SetupWindowSize),
        Getters::getScale({75, 25}, SetupWindowSize), "Y",
        Signals::EditBox::TextChanged,
        PlayerInfoTemp.Size.y
    );
    SetupWindow->add(SizeY);

    tgui::Label::Ptr FileLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 175}, SetupWindowSize),
        20, "Texture Filename"
    );
    SetupWindow->add(FileLabel);

    tgui::EditBox::Ptr TextureFilename = Creators::CreateEditBox
    (
        Getters::getScale({25, 200}, SetupWindowSize),
        Getters::getScale({200, 25}, SetupWindowSize),
        "File Path", Signals::EditBox::TextChanged,
        PlayerInfoTemp.TextureFilename
    );
    SetupWindow->add(TextureFilename);

    tgui::Button::Ptr CreatePlayer = Creators::CreateButton
    (
        Getters::getScale({75, 245}, SetupWindowSize),
        Getters::getScale({100, 35}, SetupWindowSize),
        "Create", Signals::Button::Pressed,
        Informations.SetPlayer,
        std::ref(PlayerInfoTemp)
    );
    SetupWindow->add(CreatePlayer);
}

void Setup::CreateEnemyInterface()
{
    sf::Vector2f SetupWindowSize;

    tgui::ChildWindow::Ptr SetupWindow = Creators::CreateChildWindow
    (
        Getters::getCenterScale({250, 375}),
        Getters::getScale({250, 375}),
        "Enemy Setup"
    );
    CentralGui.add(SetupWindow);
    SetupWindowSize = SetupWindow->getSize();
    
    tgui::Label::Ptr PosLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 25}, SetupWindowSize),
        20, "Enemy Position"
    );
    SetupWindow->add(PosLabel);

    tgui::EditBox::Ptr PosX = Creators::CreateEditBox
    (
        Getters::getScale({25, 50}, SetupWindowSize), 
        Getters::getScale({75, 25}, SetupWindowSize), "X",
        Signals::EditBox::TextChanged,
        EnemyInfoTemp.Position.x
    );
    SetupWindow->add(PosX);

    tgui::EditBox::Ptr PosY = Creators::CreateEditBox
    (
        Getters::getScale({150, 50}, SetupWindowSize), 
        Getters::getScale({75, 25}, SetupWindowSize), "Y",
        Signals::EditBox::TextChanged,
        EnemyInfoTemp.Position.y
    );
    SetupWindow->add(PosY);

    tgui::Label::Ptr SizeLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 100}, SetupWindowSize),
        20, "Enemy Size"
    );
    SetupWindow->add(SizeLabel);

    tgui::EditBox::Ptr SizeX = Creators::CreateEditBox
    (
        Getters::getScale({25, 125}, SetupWindowSize),
        Getters::getScale({75, 25}, SetupWindowSize), "X",
        Signals::EditBox::TextChanged,
        EnemyInfoTemp.Size.x
    );
    SetupWindow->add(SizeX);

    tgui::EditBox::Ptr SizeY = Creators::CreateEditBox
    (
        Getters::getScale({150, 125}, SetupWindowSize),
        Getters::getScale({75, 25}, SetupWindowSize), "Y",
        Signals::EditBox::TextChanged,
        EnemyInfoTemp.Size.y
    );
    SetupWindow->add(SizeY);

    tgui::Label::Ptr FileLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 175}, SetupWindowSize),
        20, "Texture Filename"
    );
    SetupWindow->add(FileLabel);

    tgui::EditBox::Ptr TextureFilename = Creators::CreateEditBox
    (
        Getters::getScale({25, 200}, SetupWindowSize),
        Getters::getScale({200, 25}, SetupWindowSize),
        "File Path", Signals::EditBox::TextChanged,
        EnemyInfoTemp.TextureFilename
    );
    SetupWindow->add(TextureFilename);

    tgui::Label::Ptr TypeLabel = Creators::CreateLabel
    (
        Getters::getScale({25, 250}, SetupWindowSize),
        20, "Enemy Type"
    );
    SetupWindow->add(TypeLabel);

    tgui::ComboBox::Ptr Type = Creators::CreateComboBox
    (
        Getters::getScale({25, 275}, SetupWindowSize),
        Getters::getScale({200, 25}, SetupWindowSize),
        {"Basic", "Intelligent"},
        EnemyInfoTemp.Type
    );
    SetupWindow->add(Type);

    tgui::Button::Ptr CreatePlayer = Creators::CreateButton
    (
        Getters::getScale({75, 320}, SetupWindowSize),
        Getters::getScale({100, 35}, SetupWindowSize),
        "Create", Signals::Button::Pressed,
        Informations.AddEnemy,
        std::ref(EnemyInfoTemp)
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