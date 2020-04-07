#pragma once

#include "Getters.hpp"

std::string Getters::ToScale(float Result)
{
    return std::to_string(Result * 100) + "%";
}

tgui::Layout2d Getters::getScale(const sf::Vector2f& Left, const sf::Vector2f& ParentSize)
{
    return tgui::Layout2d(ToScale(Left.x / ParentSize.x), ToScale(Left.y / ParentSize.y));
}

tgui::Layout2d Getters::getCenterScale(const sf::Vector2f& Size, const sf::Vector2f& ParentSize)
{
    sf::Vector2f CenterPos = (ParentSize - Size) / 2.f;
    return getScale(CenterPos, ParentSize);
}

bool Getters::ContainsDigits(const std::string& Text)
{
    return std::any_of(Text.begin(), Text.end(), ::isdigit);
}

template< typename Value >
void Getters::getEditBoxValue(tgui::EditBox::Ptr EditBox, Value& Variable)
{
    std::string Text = EditBox->getText();
    if(Text.length() == 0)
        return;

    if constexpr(std::is_floating_point< Value >::value)
    {
        if(ContainsDigits(Text))
            Variable = std::stof(Text);
    }
    else if constexpr(std::is_integral< Value >::value)
    {
        if(ContainsDigits(Text))
            Variable = std::stoi(Text);
    }
    else if constexpr(std::is_same< Value, std::string >::value)
    {
        Variable = Text;
    }
}

template< typename Value >
void Getters::getComboBoxValue(tgui::ComboBox::Ptr ComboBox, Value& Variable)
{
    if constexpr(std::is_enum< Value >::value)
    {
        int Index = ComboBox->getSelectedItemIndex();
        Variable = static_cast< Value >(Index);
    }
    else if constexpr(std::is_same< Value, std::string >::value)
    {
        Variable = ComboBox->getSelectedItem(); 
    }
}