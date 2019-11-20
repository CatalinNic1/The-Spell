#pragma once

#include "../Entity/Entity.hpp"
#include  "EventHandler/EventHandler.hpp"

class Player : public Entity 
{
private:
    std::pair< sf::Vector2f, Actions > getAction();
    sf::View PlayerView;
    sf::Vector2f getCenterPosition();
    void UpdateView();
    void ProcessInput(float DeltaTime);
public:
    Player(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    void Update(float DeltaTime);
    void setViewSize(sf::Vector2f ViewSize);
    sf::View getPlayerView();
};
