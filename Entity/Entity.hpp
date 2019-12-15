#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <memory>

#include "../Animation/Animation.hpp"
#include "../ResourceManager/ResourceManager.hpp"

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
    // Used for defining directions instead of using magic numbers
    struct Directions
    {
        static inline const sf::Vector2f Stop = {0, 0};
        static inline const sf::Vector2f Up = {0, -1};
        static inline const sf::Vector2f Down = {0, 1};
        static inline const sf::Vector2f Left = {-1, 0};
        static inline const sf::Vector2f Right = {1, 0};
    };
    // Used in collisions
    bool Movable = true;
    sf::Vector2f EntityDirection; 
private:
    // Variable used for animating an entity movement or action
    Animation EntityAnimation;
    // Pointer to texture of an Entity in order to reduce resource usage
    std::shared_ptr< sf::Texture > EntityTexture;
    // Self-explanatory
    const float EntitySpeed = 450.f;
    // Used for defining directions for collision instead of using magic numbers
    struct Axis
    {
        static inline const sf::Vector2f None = {0, 0};
        static inline const sf::Vector2f Vertical = {0, 1};
        static inline const sf::Vector2f Horizontal = {1, 0};
    };
    ///
    /// @brief This is where collision is check, but inwards
    ///
    /// @param EntityFloatRect - The bounding box of the Entity
    ///
    /// @param ObjectFloatRect - Same as above but for the object
    ///
    /// @return The Difference in order to correct to push in a appropriate direction 
    ///
    sf::Vector2f getInwardsCollision(sf::FloatRect EntityFloatRect, sf::FloatRect ObjectFloatRect);
    ///
    /// @brief This is where collision is check, but outWards
    ///
    /// @param EntityFloatRect - The bounding box of the Entity
    ///
    /// @param ObjectFloatRect - Same as above but for the object
    ///
    /// @return The Difference in order to correct to push in a appropriate direction 
    ///
    sf::Vector2f getOutwardsCollision(sf::FloatRect EntityFloatRect, sf::FloatRect ObjectFloatRect);
public:
    // You got it
    enum class CollisionTypes
    {
        Inwards,
        Outwards
    };
    // Initializer construct
    Entity(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    // Internal variable for moving, drawing and collinding entity.
    // Well the Entity itself is there, but not the logic
    sf::RectangleShape EntityRect;
    ///
    /// @brief Like .Intersect method of the float rect but It moves the entity (at this point)
    ///
    /// @param ObjectFloatRect - The bounding box of the object
    ///
    /// @param IsMovable - Idk, it does something :)) (Checks it it the object moves)
    ///
    /// @param CollisionType - Idk, at this point I'm just lazy
    ///
    /// @return It is a Boolean. I don't think this needs explation
    ///
    bool CheckCollision(sf::FloatRect ObjectFloatRect, bool IsMovable, CollisionTypes CollisionType);
    ///
    /// @brief It is a set method. What you need to know at this point?
    ///
    /// @param IsMovable - Booleans, you know it
    ///
    void setMovable(bool IsMovable);
};
