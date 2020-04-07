#pragma once

#include <type_traits>
#include <TGUI/SignalImpl.hpp>

#include "Creators.hpp"

tgui::ChildWindow::Ptr Creators::CreateChildWindow(
    const tgui::Layout2d& Position, const tgui::Layout2d& Size, const std::string& Title)
{
    tgui::ChildWindow::Ptr ChildWindow = tgui::ChildWindow::create(Title);
    ChildWindow->setPosition(Position);
    ChildWindow->setSize(Size);
    ChildWindow->setTitleTextSize(0);
    ChildWindow->setKeepInParent(true);
    ChildWindow->setTitleAlignment(tgui::ChildWindow::TitleAlignment::Center);

    return ChildWindow;
}

template< typename Variable >
tgui::EditBox::Ptr Creators::CreateEditBox(
    const tgui::Layout2d& Position, const tgui::Layout2d& Size, const std::string& DefaultText, 
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

tgui::Label::Ptr Creators::CreateLabel(
    const tgui::Layout2d& Position, std::size_t TextSize, const std::string& DefaultText)
{
    tgui::Label::Ptr Label = tgui::Label::create(DefaultText);
    Label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    Label->setPosition(Position);
    Label->setTextSize(TextSize);
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

tgui::MenuBar::Ptr Creators::CreateMenuBar(std::vector< MenuItem > MenuItems)
{
    tgui::MenuBar::Ptr MenuBar = tgui::MenuBar::create();
    for(auto& Item : MenuItems)
    {
        std::string Parent = std::get<0>(Item);
        MenuBar->addMenu(Parent);
        for(auto& ItemInfo : std::get<1>(Item))
        {
            std::apply([Parent, MenuBar](std::string&& Name, auto&& Function)
                {
                    MenuBar->addMenuItem(Name);
                    MenuBar->connectMenuItem(Parent, Name, Function);
                }, std::move(ItemInfo));
        }
    }

    return MenuBar;
}