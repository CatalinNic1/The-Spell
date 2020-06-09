#pragma once

#include "../Widgets.hpp"
#include "../Getters/Getters.hpp"
#include "../CanvasUpdater/CanvasUpdater.hpp"

namespace Signals = tgui::Signals;

namespace Creators
{
    //
    using MenuItemsInfo = std::unordered_map< std::string, std::function< void() > >;
    //
    using MenuItems = std::unordered_map< std::string, MenuItemsInfo >;
    //
    using StringVector = std::vector< sf::String >;
    //
    using StringMatrix = std::vector< StringVector >;
    ///
    ///
    ///
    template< typename Variable >
    tgui::EditBox::Ptr CreateEditBox(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::string& DefaultText, const std::string& Signal, Variable& Var);
    ///
    ///
    ///
    tgui::ChildWindow::Ptr CreateChildWindow(const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, const std::string& Title, bool IsMovable, bool KeepInParent);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    tgui::Button::Ptr CreateButton(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::string& DefaultText, const std::string& Signal, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    tgui::Label::Ptr CreateLabel(const tgui::Layout2d& Position, 
        std::size_t TextSize, const std::string& DefaultText);
    ///
    ///
    ///
    template< typename Variable >
    tgui::ComboBox::Ptr CreateComboBox(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::vector< std::string > Items, Variable& Var);
    ///
    ///
    ///
    tgui::MenuBar::Ptr CreateMenubar(MenuItems&& MenuItems);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    tgui::Canvas::Ptr CreateCanvas(CanvasUpdater& UpdatePool, const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    tgui::Scrollbar::Ptr CreateScrollbar(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        unsigned int MaxValue, unsigned int ViewportSize, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    tgui::Group::Ptr CreateScrollableCanvas(CanvasUpdater& UpdatePool, const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, const sf::Vector2u& WholeSize, Func&& DrawFunction, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    tgui::ListView::Ptr Create2DList(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const StringMatrix& Items, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    tgui::ListBox::Ptr CreateList(const tgui::Layout2d& Position, const tgui::Layout2d& Size,
        const StringVector& Items, Func&& Function, Args&&... Arguments);
}

#include "Creators.tpp"