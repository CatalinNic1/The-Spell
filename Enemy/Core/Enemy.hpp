#pragma once

#include "../../Entity/Entity.hpp"

class Enemy : public Entity
{
private:
    /* data */
protected:
    /// 
    /// @brief Used for analyzing input (random-generated or algorithm-generated)
    ///
    /// @return A predefined direction and a action to animate
    ///
    virtual std::pair< sf::Vector2f, Actions > getAction() = 0;
public:
    ///
    /// @brief Enemy constructor, this is where enemy will be initialized
    ///
    /// @param Position - Where you want the enemy will be initially localized 
    ///
    /// @param Size - How big you want the enemy to be in pixel size
    ///
    /// @param TextureFileName - Path to the texture
    ///
    Enemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    /// @brief It occupies with moving, attacking, defending where is the case
    ///
    /// @param DeltaTime - Time between frames
    ///
    virtual void Update(float DeltaTime) = 0;
};