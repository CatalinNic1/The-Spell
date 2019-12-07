#pragma once

#include <SFML/Graphics/View.hpp>

class Camera : public sf::View
{
private:
    // Collision types
    enum class Collisions
    {
        Nope,
        Up,
        Down,
        Left,
        Right
    };
    ///
    /// @brief Get a specific (sort of) direction accordingly
    ///
    /// @return A direction axy and if it exceed a limit it will also return a collision type
    ///
    std::pair< sf::Vector2f, Camera::Collisions > getCameraDirection();
    ///
    /// @brief If the limit is exceed getCameraDirection will call this function in order to return the type of collision 
    ///
    /// @param CameraPosition - You can figure out
    ///
    /// @return Same thing as the function from above
    ///
    std::pair< sf::Vector2f, Camera::Collisions > getCollisionType(sf::Vector2f CameraPosition);
    ///
    /// @brief After exceeding the limit the moving function will have a little but semnificative error and this function will correct it
    ///
    /// @param CollisionType - You can figure out
    ///
    void correctCamera(Camera::Collisions CollisionType);
    // The position of the central point in Player rectangle
    sf::Vector2f PlayerCentralPosition;
    // The area where the player can act
    sf::Vector2f LevelLimits;
    // Used for defining directions instead of using magic numbers
    struct Axis
    {
        static inline const sf::Vector2f None = {0, 0};
        static inline const sf::Vector2f Vertical = {0, 1};
        static inline const sf::Vector2f Horizontal = {1, 0};
    };
    ///
    /// @brief Getting the central position with a formula
    ///
    /// @return The Central Position Used by the View
    ///
    sf::Vector2f getPlayerCenterPosition(sf::FloatRect PlayerRect);
    // 
    sf::Vector2f CameraSize = {0.f, 0.f};
public:
    ///
    /// @brief Used for scaling the perspective in order to support multiple resoultions 
    ///
    /// @param NewSize - The size of window after beeing resized
    ///
    void setCameraSize(sf::Vector2f NewSize);
    ///
    /// @brief Setup "The Level Border" 
    ///
    /// @param Limits - The Size of the level
    ///
    void setLevelLimits(sf::Vector2f Limits);
    ///
    /// @brief Does what you see
    ///
    void UpdateCamera(sf::FloatRect EntityCenter);
};
