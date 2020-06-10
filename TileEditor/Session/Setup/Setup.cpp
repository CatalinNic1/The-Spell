#include "Setup.hpp"

#include "../../../EngineLogic/CentralStuff/GlobalVariables.hpp"

void Setup::CreatePlayerInterface()
{
    sf::Vector2f SetupWindowSize = {250, 300};

    tgui::ChildWindow::Ptr SetupWindow = Creators::CreateChildWindow
    (
        Getters::getCenterScale(SetupWindowSize),
        Getters::getScale(SetupWindowSize),
        "Player Setup",
        false, true
    );
    CentralGui.add(SetupWindow);
    
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
        [this, SetupWindow](const PlayerInfo& Information){
            Informations.SetPlayer(Information);
            SetupWindow->close();
            SetupWindow->destroy();
        }, PlayerInfoTemp
    );
    SetupWindow->add(CreatePlayer);
}

void Setup::CreateEnemyInterface()
{
    sf::Vector2f SetupWindowSize = {250, 375};

    tgui::ChildWindow::Ptr SetupWindow = Creators::CreateChildWindow
    (
        Getters::getCenterScale(SetupWindowSize),
        Getters::getScale(SetupWindowSize),
        "Enemy Setup",
        false, true
    );
    CentralGui.add(SetupWindow);
    
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
        [this, SetupWindow](const EnemyInfo& Information){
            Informations.AddEnemy(Information);
            SetupWindow->close();
            SetupWindow->destroy();
        }, EnemyInfoTemp
    );
    SetupWindow->add(CreatePlayer);
}

void Setup::CreateTileInterface()
{
    sf::Vector2f TileSize = Informations.getTileSize();
    sf::Vector2u MapSize = Informations.getMapSize();

    tgui::Group::Ptr MapCanvas = Creators::CreateScrollableCanvas
    (
        UpdatePool, {256, 20.f},
        {"100% - 576", "100% - 20"},
        {2000, 2000}, [](tgui::Canvas::Ptr){}
    );
    CentralGui.add(MapCanvas);

    tgui::ListView::Ptr list2d = Creators::Create2DList
	(
		{0, 20}, {256, "100% - 20"}, {
		{"Variables", "Values"},
		{"Map Width", std::to_string(MapSize.x)},
		{"Map Height", std::to_string(MapSize.y)},
        {"Tile Width", std::to_string(TileSize.x)},
        {"Tile Height", std::to_string(TileSize.y)} }, 
        [](int Index){}
    );
	CentralGui.add(list2d);

    tgui::ChildWindow::Ptr ListWindow = Creators::CreateChildWindow
    (
        {"100% - 320", 20},
        {320, "50% - 10"},
        "Layers",
        false, false
    );

    tgui::ListBox::Ptr list1d = Creators::CreateList
    (
        {0, 0}, 
        {"100%", "100% - 32"},
        {"first", "second", "third"},
        [](int Index){}
    );

    ListWindow->add(list1d);
    CentralGui.add(ListWindow);

    tgui::ChildWindow::Ptr TilesetWindow = Creators::CreateChildWindow
    (
        {"100% - 320", "50% - 10"},
        {320, "50% - 10"},
        "Tilesets",
        false, false
    );

    tgui::Group::Ptr TilesetCanvas = Creators::CreateScrollableCanvas
    (
        UpdatePool, {0, 0},
        {"100%", "100% - 32"},
        {1280, 768}, [](tgui::Canvas::Ptr){}
    );

    TilesetWindow->add(TilesetCanvas);
    CentralGui.add(TilesetWindow);
}

void Setup::CreateEditorMenubar()
{
    tgui::MenuBar::Ptr Tools = Creators::CreateMenubar
    ({{
        "New",{
            {"Map", []{}},
            {"Player", [this]{CreatePlayerInterface();}},
            {"Enemy", [this]{CreateEnemyInterface();}}
    }},{
        "Run",{
                {"Test", []{}}
    }},{
        "Close",{
            {"Exit", &Setup::Exit}
    }}});
    CentralGui.add(Tools);
}

Setup::Setup() 
    : UpdatePool(&Setup::IsOpen), CentralGui(AppWindow)
{
    sf::Vector2f SetupWindowSize = {200, 340};

    tgui::ChildWindow::Ptr SetupWindow = Creators::CreateChildWindow
    (
        Getters::getCenterScale(SetupWindowSize),
        Getters::getScale(SetupWindowSize),
        "New Map",
        false, true
    );

    tgui::Label::Ptr FileLabel = Creators::CreateLabel
    (
        Getters::getScale({20, 20}, SetupWindowSize),
        20, "Map Filename"
    );
    SetupWindow->add(FileLabel);

    tgui::EditBox::Ptr MapFilenameBox = Creators::CreateEditBox
    (
        Getters::getScale({20, 40}, SetupWindowSize),
        Getters::getScale({60, 15}, SetupWindowSize),
        "File Path", Signals::EditBox::TextChanged,
        MapFilename
    );
    SetupWindow->add(MapFilenameBox);

    tgui::Label::Ptr TileLabel = Creators::CreateLabel
    (
        Getters::getScale({20, 65}, SetupWindowSize),
        20, "Tile Size"
    );
    SetupWindow->add(TileLabel);

    tgui::EditBox::Ptr TileSizeX = Creators::CreateEditBox
    (
        Getters::getScale({20, 85}, SetupWindowSize),
        Getters::getScale({20, 15}, SetupWindowSize),
        "X", Signals::EditBox::TextChanged,
        Informations.getTileSize().x
    );
    SetupWindow->add(TileSizeX);

    tgui::EditBox::Ptr TileSizeY = Creators::CreateEditBox
    (
        Getters::getScale({60, 85}, SetupWindowSize),
        Getters::getScale({20, 15}, SetupWindowSize),
        "Y", Signals::EditBox::TextChanged,
        Informations.getTileSize().y
    );
    SetupWindow->add(TileSizeY);

    tgui::Label::Ptr LayerLabel = Creators::CreateLabel
    (
        Getters::getScale({20, 110}, SetupWindowSize),
        20, "Layer Size"
    );
    SetupWindow->add(LayerLabel);

    tgui::EditBox::Ptr LayerSizeX = Creators::CreateEditBox
    (
        Getters::getScale({20, 130}, SetupWindowSize),
        Getters::getScale({20, 15}, SetupWindowSize),
        "X", Signals::EditBox::TextChanged,
        Informations.getMapSize().x
    );
    SetupWindow->add(LayerSizeX);

    tgui::EditBox::Ptr LayerSizeY = Creators::CreateEditBox
    (
        Getters::getScale({60, 130}, SetupWindowSize),
        Getters::getScale({20, 15}, SetupWindowSize),
        "Y", Signals::EditBox::TextChanged,
        Informations.getMapSize().y
    );
    SetupWindow->add(LayerSizeY);

    tgui::Button::Ptr CreateButton = Creators::CreateButton
    (
        Getters::getCenterScale({40, 25}, SetupWindowSize),
        Getters::getScale({40, 25}, SetupWindowSize),
        "Create Map", Signals::Button::Pressed,
        [this, SetupWindow](const sf::Vector2u& LSize, const sf::Vector2f& TSize, const std::string& Tileset){
            Informations.AddLayer(LSize, TSize, Tileset);
            SetupWindow->close();
            SetupWindow->destroy();
        }, Informations.getMapSize(),
        Informations.getTileSize(),
        "Tilesets/A4_Master.png"
    );
    
    CreateTileInterface();
    CreateEditorMenubar();
    SetupWindow->add(CreateButton);
    CentralGui.add(SetupWindow);
}

void Setup::draw()
{
    Setup::Clear();
    UpdatePool.Update();
    CentralGui.draw();
    Setup::Display();
}

bool Setup::IsOpen()
{
    return AppWindow.isOpen();
}

bool Setup::PollEvent(sf::Event& Event)
{
    return AppWindow.pollEvent(Event);
}

bool Setup::handleGuiEvent(const sf::Event& Event)
{
    return CentralGui.handleEvent(Event);
}

void Setup::SetGuiView(const sf::View& View)
{
    CentralGui.setView(View);
}

void Setup::Exit()
{
    AppWindow.close();
}

void Setup::Clear(const sf::Color& Color)
{
    AppWindow.clear(Color);
}

void Setup::Display()
{
    AppWindow.display();
}

void Setup::SetWindowView(const sf::View& View)
{
    AppWindow.setView(View);
}

const sf::View& Setup::GetWindowView()
{
    return AppWindow.getView();
}

void Setup::RemoveOrphans()
{
    UpdatePool.RemoveOrphans();
    ResourceManager::RemoveOrphans();
}