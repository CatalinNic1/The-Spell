#pragma once

#include "../Core/Enemy.hpp"

class BasicEnemy : Enemy
{
private:
    //
    static const int maxDirections = 4;
public:
    ///
    ///
    ///
    BasicEnemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    ///
    ///
    virtual void move(float DeltaTime) override;
};