#pragma once

#include "../Core/Enemy.hpp"

class IntelligentEnemy : public Enemy
{
private:
    //
    sf::FloatRect Obstcale = sf::FloatRect();
    //
    static inline sf::Vector2f PlayerPos = SmartRect::Directions::Stop;
    //
    static inline float EnemySpeed;
    //
    sf::Vector2f DirectionOnCollision = SmartRect::Directions::Stop;
    ///
    ///
    ///
    std::pair< sf::Vector2f, Actions > EvitObstacle();
    ///
    ///
    ///
    virtual std::pair< sf::Vector2f, Actions > getAction() override;
    ///
    ///
    ///
    bool isColliding();
public:
    ///
    ///
    ///
    IntelligentEnemy(const sf::Vector2f& Position, const sf::Vector2f& Size, const std::string& TextureFileName);
    ///
    ///
    ///
    virtual void Update(float DeltaTime) override;
    ///
    ///
    ///
    void setObstcaleInfo(const sf::FloatRect& ObstacaleRect);
    ///
    ///
    ///
    static void setDestinationPos(const sf::Vector2f& Destination);
};
