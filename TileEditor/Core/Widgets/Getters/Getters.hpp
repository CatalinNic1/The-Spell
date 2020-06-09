#pragma once

#include <TGUI/Widgets/EditBox.hpp>
#include <TGUI/Widgets/ComboBox.hpp>

namespace Getters
{
    ///
    ///
    ///
    template< typename Value >
    void getEditBoxValue(tgui::EditBox::Ptr EditBox, Value& Variable);
    ///
    ///
    ///
    template< typename Value >
    void getComboBoxValue(tgui::ComboBox::Ptr ComboBox, Value& Variable);
    ///
    ///
    ///
    tgui::Layout2d getScale(
        const sf::Vector2f& Left, const sf::Vector2f& ParentSize = {1280, 768});
    ///
    ///
    ///
    tgui::Layout2d getCenterScale(
        const sf::Vector2f& Size, const sf::Vector2f& ParentSize = {1280, 768});
}

#include "Getters.tpp"