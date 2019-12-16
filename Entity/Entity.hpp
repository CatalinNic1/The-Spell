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
private:
    // Variable used for animating an entity movement or action
    Animation EntityAnimation;
    // Pointer to texture of an Entity in order to reduce resource usage
    std::shared_ptr< sf::Texture > EntityTexture;
public:
    // Initializer construct
    Entity(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    // Internal variable for moving, drawing and collinding entity.
    // Well the Entity itself is there, but not the logic
   SmartRect EntityRect;
};
