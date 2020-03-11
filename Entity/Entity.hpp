#pragma once

#include <memory>

#include "../Animation/Animation.hpp"
#include "../ResourceManager/ResourceManager.hpp"
#include "../SmartRect/SmartRect.hpp"

// Core class for NPC's, Player and Enemies 
class Entity
{
protected:
    ///
    /// @brief I think this is self-explanatory
    ///
    /// @param DeltaTime - Time between frames
    ///
    /// @param Direction - Self-Explanatory
    ///
    void moveEntity(const float& DeltaTime, const sf::Vector2f& Direction, const float& SpeedFactor = 1.f);
    ///
    /// @brief Function used as a wrapper around Animation::Animate method
    ///
    /// @param Action - Predefined action or direction 
    ///
    void EntityAnimate(const Actions& Action);
    ///
    /// @brief Here is where animations will be ititialize by calling Animation::setFrameLimit()
    ///
    /// @param TextureFileName - Path of the image to be loaded
    ///
    void initEntityAnim(const std::string& TextureFileName);
private:
    // Variable used for animating an entity movement or action
    Animation EntityAnimation;
public:
    ///
    /// @brief Initializer construct for entity
    ///
    /// @param Position - Where you want the enemy will be initially localized 
    ///
    /// @param Size - How big you want the enemy to be in pixel size
    ///
    Entity(const sf::Vector2f& Position, const sf::Vector2f& Size);
    // Internal variable for moving, drawing and collinding entity.
    // Well the Entity itself is there, but not the logic
    SmartRect EntityRect;
};
