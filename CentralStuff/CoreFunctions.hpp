#pragma once

#include <string>
#include <SFML/Graphics/Rect.hpp>

///
/// @brief Transforms a sf::IntRect into a std::string. Ex: RectToString(sf::IntRect()) -> "(0, 0, 0, 0)"
///
/// @param Rect - A SFML rectangle to be transformed
///
/// @return A string according with "(Rect.left, Rect.top, Rect.width, Rect.height)"
///
template< typename T >
std::string RectToString(sf::Rect< T > Rect)
{
    return "(" + std::to_string(Rect.left) + ", " + std::to_string(Rect.top) + ", " 
    + std::to_string(Rect.width) + ", " + std::to_string(Rect.height) + ")";
}

///
/// @brief Multiplies two sf::Vector2's
///
/// @param Right - Right operand (a sf::Vector2) 
///
/// @param Left - Left operand (a sf::Vector2)
///
/// @return A multliplied sf::Vector2
///
template< typename T >
sf::Vector2< T > operator*(sf::Vector2< T > Right, sf::Vector2< T > Left)
{
    return sf::Vector2< T >(Right.x * Left.x, Right.y * Left.y);
}
///
/// @brief Strippts the extension of the file
///
/// @param FileName - This simple to understand, you want more explanation put it yourself
///
/// @return A siring, nothing more harder to understand
///
std::string getName(const std::string& FileName);