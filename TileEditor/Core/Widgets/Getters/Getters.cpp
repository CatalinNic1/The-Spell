#include "Getters.hpp"

std::string Getters::ToScale(float Result)
{
    return std::to_string(Result * 100.f) + "%";
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

void Getters::getInt(tgui::EditBox::Ptr EditBox, int& Variable)
{
    std::string Text = EditBox->getText();

    try
    {
        Variable = std::stoi(Text);
    }
    catch(const std::exception& Exception)
    {
        Variable = 0;
    }
    
}

void Getters::getFloat(tgui::EditBox::Ptr EditBox, float& Variable)
{
    std::string Text = EditBox->getText();

    try
    {
        Variable = std::stof(Text);
    }
    catch(const std::exception& Exception)
    {
        Variable = 0.f;
    }
}

void Getters::getString(tgui::EditBox::Ptr EditBox, std::string& Variable)
{
    try
    {
        Variable = EditBox->getText();
    }
    catch(const std::exception& Exception)
    {
        Variable = " ";
    }
}