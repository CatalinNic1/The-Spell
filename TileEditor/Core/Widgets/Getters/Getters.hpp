#pragma once

#include <TGUI/Widgets/EditBox.hpp>

class Getters
{
private:
    ///
    ///
    ///
    static std::string ToScale(float Result);
    ///
    ///
    ///
    static bool ContainsDigits(const std::string& Text);
public:
    ///
    ///
    ///
    template< typename Value >
    static void getEditBoxValue(tgui::EditBox::Ptr EditBox, Value& Variable);
    ///
    ///
    ///
    template< typename Value >
    static void getComboBoxValue(tgui::ComboBox::Ptr ComboBox, Value& Variable);
    ///
    ///
    ///
    static tgui::Layout2d getScale(
        const sf::Vector2f& Left, const sf::Vector2f& ParentSize = {1280, 768});
    ///
    ///
    ///
    static tgui::Layout2d getCenterScale(
        const sf::Vector2f& Size, const sf::Vector2f& ParentSize = {1280, 768});
};

#include "Getters.tpp"