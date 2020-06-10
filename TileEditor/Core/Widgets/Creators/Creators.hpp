#pragma once

#include "../Widgets.hpp"
#include "../Getters/Getters.hpp"
#include "../CanvasUpdater/CanvasUpdater.hpp"

namespace Signals = tgui::Signals;

namespace Creators
{
    //
    template< typename Key, typename Value >
    using PairVector = std::vector< std::pair< Key, Value > >;
    //
    using MenuItemsInfo = PairVector< std::string, std::function< void() > >;
    //
    using MenuItems = PairVector< std::string, MenuItemsInfo >;
    //
    using StringVector = std::vector< sf::String >;
    //
    using StringMatrix = std::vector< StringVector >;
    ///
    ///
    ///
    template< typename Variable >
    static tgui::EditBox::Ptr CreateEditBox(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::string& DefaultText, const std::string& Signal, Variable& Var);
    ///
    ///
    ///
    static tgui::ChildWindow::Ptr CreateChildWindow(const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, const std::string& Title, bool IsMovable, bool KeepInParent);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::Button::Ptr CreateButton(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::string& DefaultText, const std::string& Signal, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    static tgui::Label::Ptr CreateLabel(const tgui::Layout2d& Position, 
        std::size_t TextSize, const std::string& DefaultText);
    ///
    ///
    ///
    template< typename Variable >
    static tgui::ComboBox::Ptr CreateComboBox(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const std::vector< std::string > Items, Variable& Var);
    ///
    ///
    ///
    static tgui::MenuBar::Ptr CreateMenubar(MenuItems&& MenuItems);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::Canvas::Ptr CreateCanvas(CanvasUpdater& UpdatePool, const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::Scrollbar::Ptr CreateScrollbar(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        unsigned int MaxValue, unsigned int ViewportSize, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::Group::Ptr CreateScrollableCanvas(CanvasUpdater& UpdatePool, const tgui::Layout2d& Position, 
        const tgui::Layout2d& Size, const sf::Vector2u& WholeSize, Func&& DrawFunction, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::ListView::Ptr Create2DList(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
        const StringMatrix& Items, Func&& Function, Args&&... Arguments);
    ///
    ///
    ///
    template< typename Func, typename... Args >
    static tgui::ListBox::Ptr CreateList(const tgui::Layout2d& Position, const tgui::Layout2d& Size,
        const StringVector& Items, Func&& Function, Args&&... Arguments);
}

#include "Creators.tpp"