#pragma once

#include <string>
#include <SFML/Graphics/Rect.hpp>

///
///
///
template< typename T >
std::string RectToString(sf::Rect< T > Rect)
{
    return "(" + std::to_string(Rect.left) + ", " + std::to_string(Rect.top) + ", " 
    + std::to_string(Rect.width) + ", " + std::to_string(Rect.height) + ")";
}

///
///
///
template< typename T >
sf::Vector2< T > operator*(sf::Vector2< T > Right, sf::Vector2< T > Left)
{
    return sf::Vector2< T >(Right.x * Left.x, Right.y * Left.y);
}
///
///
///
std::string getName(const std::string& FileName);