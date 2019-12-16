#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class SmartRect : public sf::RectangleShape
{
private:
    // Self-explanatory
    const float MovingSpeed = 450.f;
    //
    float PseudoLineThickness = 0.f;
    // Used for defining directions for collision instead of using magic numbers
    struct Axis
    {
        static inline const sf::Vector2f None = {0, 0};
        static inline const sf::Vector2f Vertical = {0, 1};
        static inline const sf::Vector2f Horizontal = {1, 0};
    };
    // Used in collisions
    bool Movable = true;
    sf::Vector2f MovingDirection = {0, 0};
    ///
    /// @brief This is where collision is check, but inwards
    ///
    /// @param OtherObject - The Object itself
    ///
    /// @return The Difference in order to correct to push in a appropriate direction 
    ///
    sf::Vector2f getInwardsCollision(SmartRect OtherObject);
    ///
    /// @brief This is where collision is check, but inwards and for collisions with the margin of the level
    ///
    /// @param OtherObjectFloatRect - The binding box of the object
    ///
    /// @return The Difference in order to correct to push in a appropriate direction 
    ///
    sf::Vector2f getInwardsCollision(sf::FloatRect OtherObjectFloatRect);
    ///
    /// @brief This is where collision is check, but inwards
    ///
    /// @param OtherObject - The Object itself
    ///
    /// @return The Difference in order to correct to push in a appropriate direction 
    ///
    sf::Vector2f getOutwardsCollision(SmartRect OtherObject);
    ///
    ///
    ///
    sf::Vector2f getCollisionDirection(SmartRect OtherObject);
public:
    // Used for defining directions instead of using magic numbers
    struct Directions
    {
        static inline const sf::Vector2f Stop = {0, 0};
        static inline const sf::Vector2f Up = {0, -1};
        static inline const sf::Vector2f Down = {0, 1};
        static inline const sf::Vector2f Left = {-1, 0};
        static inline const sf::Vector2f Right = {1, 0};
    };
    // You got it
    enum class CollisionTypes
    {
        Inwards,
        Outwards
    };
    ///
    /// @brief I think this is self-explanatory
    ///
    /// @param DeltaTime - Time between frames
    ///
    /// @param Direction - Self-Explanatory
    ///
    /// @param SpeedFactor
    ///
    void moveRect(float DeltaTime, sf::Vector2f Direction, float SpeedFactor = 1.f);
    ///
    /// @brief Like .Intersect method of the float rect but It moves the entity (at this point)
    ///
    /// @param OtherObject - The object itself
    ///
    /// @param CollisionType - Idk, at this point I'm just lazy
    ///
    /// @return It is a Boolean. I don't think this needs explation
    ///
    bool CheckCollision(SmartRect& OtherObject, CollisionTypes CollisionType);
    ///
    /// @brief Like .Intersect method of the float rect but It moves the entity (at this point)
    ///
    /// @param OtherObjectFloatRect - The bounding box of the object
    ///
    /// @warning This is used for inwards collision and needs to be used for the margins of the level 
    ///
    /// @return It is a Boolean. I don't think this needs explation
    ///
    bool CheckCollision(sf::FloatRect OtherObjectFloatRect);
};
