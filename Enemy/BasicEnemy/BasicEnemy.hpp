#pragma once

#include "../Core/Enemy.hpp"

class BasicEnemy : Enemy
{
private:
    //
    enum Directions
    {
        None,
        Up,
        Down,
        Left,
        Right
    };
    //
    float Distance = 0.f;
    //
    int Direction = Directions::None;
public:
    ///
    ///
    ///
    BasicEnemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    ///
    ///
    virtual void move(float DeltaTime, float SpeedFactor = 1.f) override;
};