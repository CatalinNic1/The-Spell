#pragma once

#include <TGUI/Widgets/EditBox.hpp>
#include <TGUI/Widgets/ChildWindow.hpp>
#include <TGUI/Widgets/Button.hpp>

#include "../Getters/Getters.hpp"

namespace Signals = tgui::Signals;

enum class InputType
{
    Int,
    Float,
    String
};

struct Creators
{
    ///
    ///
    ///
    template< typename Variable >
    static tgui::EditBox::Ptr CreateEditBox(
        const tgui::Layout2d& Position, const tgui::Layout2d& Size, const std::string& DefaultText, 
        const std::string& Signal, const InputType& Type, Variable& Var);
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
};

#include "Creators.tpp"