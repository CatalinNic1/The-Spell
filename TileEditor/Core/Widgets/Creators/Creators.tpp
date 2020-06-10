#include <type_traits>
#include <TGUI/SignalImpl.hpp>

#include "Creators.hpp"
#include "../Handlers/Handlers.hpp"

tgui::ChildWindow::Ptr Creators::CreateChildWindow(const tgui::Layout2d& Position, 
    const tgui::Layout2d& Size, const std::string& Title, bool IsMovable, bool KeepInParent)
{
    tgui::ChildWindow::Ptr ChildWindow = tgui::ChildWindow::create(Title);
    ChildWindow->setPosition(Position);
    ChildWindow->setSize(Size);
    ChildWindow->setTitleTextSize(0);
    ChildWindow->setKeepInParent(KeepInParent);
    ChildWindow->setPositionLocked(!IsMovable);
    ChildWindow->setTitleAlignment(tgui::ChildWindow::TitleAlignment::Center);
    ChildWindow->connect(Signals::ChildWindow::Closed, [ChildWindow]
    {
        ChildWindow->destroy();
    });

    return ChildWindow;
}

template< typename Variable >
tgui::EditBox::Ptr Creators::CreateEditBox(const tgui::Layout2d& Position, 
    const tgui::Layout2d& Size, const std::string& DefaultText, 
    const std::string& Signal, Variable& Var)
{
        tgui::EditBox::Ptr Editbox = tgui::EditBox::create();
        Editbox->setPosition(Position);
        Editbox->setSize(Size);
        Editbox->setDefaultText(DefaultText);
        Editbox->setTextSize(0);
        if constexpr(!std::is_same< Variable, std::string >::value)
        {
            Editbox->setMaximumCharacters(9);
            if constexpr(std::is_same< Variable, int >::value)
            {
                Editbox->setInputValidator(tgui::EditBox::Validator::Int);
                Editbox->connect(Signal, Getters::getEditBoxValue< Variable >, Editbox, std::ref(Var));
            }
            else
            {
                Editbox->setInputValidator(tgui::EditBox::Validator::Float);
                Editbox->connect(Signal, Getters::getEditBoxValue< Variable >, Editbox, std::ref(Var));
            }
        }
        else
            Editbox->connect(Signal, Getters::getEditBoxValue< Variable >, Editbox, std::ref(Var));

        return Editbox;
} 

template< typename Func, typename... Args >
tgui::Button::Ptr Creators::CreateButton(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
    const std::string& DefaultText, const std::string& Signal, Func&& Function, Args&&... Arguments)
{
    tgui::Button::Ptr Button = tgui::Button::create(DefaultText);
    Button->setPosition(Position);
    Button->setSize(Size);
    Button->setTextSize(0);
    Button->connect(Signal, Function, Arguments...);

    return Button;
}

tgui::Label::Ptr Creators::CreateLabel(const tgui::Layout2d& Position, 
    std::size_t TextSize, const std::string& DefaultText)
{
    tgui::Label::Ptr Label = tgui::Label::create(DefaultText);
    Label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    Label->setPosition(Position);
    Label->setTextSize(static_cast< unsigned >(TextSize));
    return Label;
}

template< typename Variable >
tgui::ComboBox::Ptr Creators::CreateComboBox(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
    const std::vector< std::string > Items, Variable& Var)
{
    tgui::ComboBox::Ptr ComboBox = tgui::ComboBox::create();
    ComboBox->setPosition(Position);
    ComboBox->setSize(Size);
    ComboBox->setTextSize(0);

    for(const std::string& Item : Items)
        ComboBox->addItem(Item);

    ComboBox->setSelectedItem(Items.front());
    Getters::getComboBoxValue(ComboBox, Var);
    ComboBox->getItems();
    ComboBox->connect(Signals::ComboBox::ItemSelected, Getters::getComboBoxValue< Variable >, ComboBox, std::ref(Var));
    return ComboBox;
}

tgui::MenuBar::Ptr Creators::CreateMenubar(MenuItems&& MenuItems)
{
    tgui::MenuBar::Ptr MenuBar = tgui::MenuBar::create();
    for(auto& Item : MenuItems)
    {
        std::string Parent = Item.first;
        MenuBar->addMenu(Parent);
        for(auto& ItemInfo : Item.second)
        {
            std::string Child = ItemInfo.first;
            MenuBar->addMenuItem(Child);
            MenuBar->connectMenuItem({Parent, Child}, ItemInfo.second);
        }
    }

    return MenuBar;
}

template< typename Func, typename... Args >
tgui::Canvas::Ptr Creators::CreateCanvas(CanvasUpdater& UpdatePool, const tgui::Layout2d& Position, 
    const tgui::Layout2d& Size, Func&& Function, Args&&... Arguments)
{
    tgui::Canvas::Ptr Canvas = tgui::Canvas::create();
    Canvas->setPosition(Position);
    Canvas->setSize(Size);
    UpdatePool.add({Canvas, std::bind(Function, Canvas, Arguments...)});
    return Canvas;
}

template< typename Func, typename... Args >
tgui::Scrollbar::Ptr Creators::CreateScrollbar(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
    unsigned int MaxValue, unsigned int ViewportSize, Func&& Function, Args&&... Arguments)
{
    tgui::Scrollbar::Ptr ScrollBar = tgui::Scrollbar::create();
    ScrollBar->setPosition(Position);
    ScrollBar->setSize(Size);
    ScrollBar->setMaximum(MaxValue);
    ScrollBar->setViewportSize(ViewportSize);
    ScrollBar->setValue(0);
    ScrollBar->connect(Signals::Scrollbar::ValueChanged, Function, Arguments...);
    return ScrollBar;
}

template< typename Func, typename... Args >
tgui::ListBox::Ptr Creators::CreateList(const tgui::Layout2d& Position, const tgui::Layout2d& Size,
    const StringVector& Items, Func&& Function, Args&&... Arguments)
{
    tgui::ListBox::Ptr ListBox = tgui::ListBox::create();
    ListBox->setPosition(Position);
    ListBox->setSize(Size);
    ListBox->connect(Signals::ListBox::ItemSelected, Function, Arguments...);

    for(auto& Item : Items)
        ListBox->addItem(Item);

    return ListBox;
}

template< typename Func, typename... Args >
tgui::ListView::Ptr Creators::Create2DList(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
    const StringMatrix& Items, Func&& Function, Args&&... Arguments)
{
	tgui::ListView::Ptr ListView = tgui::ListView::create();
	ListView->setPosition(Position);
	ListView->setSize(Size);
	ListView->setExpandLastColumn(true);
    ListView->setShowHorizontalGridLines(true);
    ListView->setShowVerticalGridLines(true);

	for (auto& Colum : Items[0])
		ListView->addColumn(Colum);
    
    ListView->setColumnWidth(0, Size.getValue().x / 2);
	ListView->addMultipleItems({Items.begin() + 1, Items.end()});
    ListView->connect(Signals::ListView::SizeChanged, Handlers::Handle2DList, ListView);
    ListView->connect(Signals::ListView::ItemSelected, Function, Arguments...);
	return ListView;
}

template< typename Func, typename... Args >
tgui::Group::Ptr Creators::CreateScrollableCanvas(CanvasUpdater& UpdatePool, const tgui::Layout2d& Position, 
    const tgui::Layout2d& Size, const sf::Vector2u& WholeSize, Func&& DrawFunction, Args&&... Arguments)
{
    tgui::Group::Ptr BoxLayout = tgui::BoxLayout::create();
    BoxLayout->setPosition(Position);
    BoxLayout->setSize(Size);
    
    tgui::Canvas::Ptr Canvas = CreateCanvas
    (
        UpdatePool, {0.f, 0.f},
        BoxLayout->getSize() - sf::Vector2f(20.f, 20.f),
        DrawFunction, Arguments...
    );
    BoxLayout->add(Canvas);
    sf::Vector2f CanvasSize = Canvas->getSize();

    tgui::Scrollbar::Ptr VerticalScroll = CreateScrollbar
    (
        {CanvasSize.x , 0.f}, {20.f, CanvasSize.y},
        WholeSize.y, static_cast< uint >(CanvasSize.y), 
        Handlers::HandleVScrollbar, 
        Canvas, VerticalScroll
    );
    BoxLayout->add(VerticalScroll);

    tgui::Scrollbar::Ptr HorizontalScroll = CreateScrollbar
    (
        {0.f , CanvasSize.y}, {CanvasSize.x, 20.f},
        WholeSize.x, static_cast< uint >(CanvasSize.x),
        Handlers::HandleHScrollbar, 
        Canvas, HorizontalScroll
    );
    BoxLayout->add(HorizontalScroll);

    BoxLayout->connect
    (
        Signals::Widget::SizeChanged, 
        Handlers::ScaleScrollableCanvas,
        BoxLayout, Canvas, VerticalScroll, 
        HorizontalScroll
    );
    return BoxLayout;
}