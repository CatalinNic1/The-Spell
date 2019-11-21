#pragma once

#include "../Entity/Entity.hpp"
#include  "EventHandler/EventHandler.hpp"

class Player : public Entity 
{
private:
    /// 
    /// @brief Used for analyzing input  
    ///
    /// @return A predefined direction and a action to animate
    ///
    std::pair< sf::Vector2f, Actions > getAction();
    // Player perspective
    sf::View PlayerView;
    ///
    /// @brief Getting the central position with a formula
    ///
    /// @return The Central Position Used by the View
    ///
    sf::Vector2f getCenterPosition();
    ///
    /// @brief Does what you see
    ///
    void UpdateView();
    ///
    /// @brief After it gets an Action and a Direction It will perform that action
    ///
    /// @param DeltaTime - Time between frames
    ///
    void ProcessInput(float DeltaTime);
public:
    ///
    /// @brief The Initializer
    /// 
    Player(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    /// @brief Calls all function like: UpdateView and ProcessInput
    ///
    /// @param DeltaTime - Time between frames
    ///
    void Update(float DeltaTime);
    ///
    /// @brief Used for scaling the perspective in order to support multiple resoultions 
    ///
    /// @param NewSize - The size of window after beeing resized
    ///
    void setViewSize(sf::Vector2f NewSize);
    ///
    /// @return Player's perspective
    ///
    sf::View getPlayerView();
};
