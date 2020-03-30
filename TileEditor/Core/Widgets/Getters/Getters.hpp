#pragma once

#include <TGUI/Widgets/EditBox.hpp>

struct Getters
{
private:
    ///
    ///
    ///
    static std::string ToScale(float Result);
public:
    ///
    ///
    ///
    static void getInt(tgui::EditBox::Ptr EditBox, int& Variable);
    ///
    ///
    ///
    static void getFloat(tgui::EditBox::Ptr EditBox, float& Variable);
    ///
    ///
    ///
    static void getString(tgui::EditBox::Ptr EditBox, std::string& Variable);
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
