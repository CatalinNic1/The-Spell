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
    void moveEntity(float DeltaTime, sf::Vector2f Direction);
    ///
    /// @brief Function used as a wrapper around Animation::Animate method
    ///
    /// @param Action - Predefined action or direction 
    ///
    void EntityAnimate(Actions Action);
    ///
    ///
    ///
    void initEntityAnim(const std::string& TextureFileName);
private:
    // Variable used for animating an entity movement or action
    Animation EntityAnimation;
public:
    // Initializer construct
    Entity(sf::Vector2f Position, sf::Vector2f Size);
    // Internal variable for moving, drawing and collinding entity.
    // Well the Entity itself is there, but not the logic
    SmartRect EntityRect;
};
