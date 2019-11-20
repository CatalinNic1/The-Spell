#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <memory>

#include "../Animation/Animation.hpp"
#include "../ResourceManager/ResourceManager.hpp"

// Core class for NPC's, Player and Enemies 
class Entity
{
public:
    // Initializer construct
    Entity(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    // Internal variable for moving, drawing and collinding entity.
    // Well the Entity itself is there, but not the logic
    sf::RectangleShape EntityRect;
protected:
    /// @brief I think this is self-explanatory
    ///
    /// @param DeltaTime - Time between frames
    ///
    /// @param Direction - Self-Explanatory
    void moveEntity(float DeltaTime, sf::Vector2f Direction);
    /// @brief Function used as a wrapper around Animation::Animate method
    ///
    /// @param Action - Predefined action or direction 
    void EntityAnimate(Actions Action);
    // Used for defining directions instead of using magic numbers
    struct Directions
    {
        static inline const sf::Vector2f Stop = {0, 0};
        static inline const sf::Vector2f Up = {0, -1};
        static inline const sf::Vector2f Down = {0, 1};
        static inline const sf::Vector2f Left = {-1, 0};
        static inline const sf::Vector2f Right = {1, 0};
    };
private:
    // Variable used for animating an entity movement or action
    Animation EntityAnimation;
    // Pointer to texture of an Entity in order to reduce resource usage
    std::shared_ptr< sf::Texture > EntityTexture;
    // Self-explanatory
    const int EntitySpeed = 450;
};
