#pragma once

#include <TGUI/Widgets/EditBox.hpp>
#include <TGUI/Widgets/ChildWindow.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/Label.hpp>
#include <TGUI/Widgets/ComboBox.hpp>
#include <TGUI/Widgets/MenuBar.hpp>

#include "../Getters/Getters.hpp"

namespace Signals = tgui::Signals;

struct Creators
{
    //
    using MenuItemsInfo = std::unordered_map< std::string, std::function< void() > >;
    //
    using MenuItems = std::unordered_map< std::string, MenuItemsInfo >;
    ///
    ///
    ///
    template< typename Variable >
    static tgui::EditBox::Ptr CreateEditBox(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::string& DefaultText, const std::string& Signal, Variable& Var);
    ///
    ///
    ///
    static tgui::ChildWindow::Ptr CreateChildWindow(
        const tgui::Layout2d& Position, const tgui::Layout2d& Size, const std::string& Title);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::Button::Ptr CreateButton(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::string& DefaultText, const std::string& Signal, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    static tgui::Label::Ptr CreateLabel(
        const tgui::Layout2d& Position, std::size_t TextSize, const std::string& DefaultText);
    ///
    ///
    ///
    template< typename Variable >
    static tgui::ComboBox::Ptr CreateComboBox(const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, const std::vector< std::string > Items, Variable& Var);
    ///
    ///
    ///
    static tgui::MenuBar::Ptr CreateMenuBar(MenuItems&& MenuItems);
};

#include "Creators.tpp"