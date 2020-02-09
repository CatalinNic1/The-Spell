#pragma once

#include "../../Entity/Entity.hpp"

class Enemy : public Entity
{
private:
    /* data */
public:
    ///
    ///
    ///
    Enemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    ///
    ///
    virtual void move(float DeltaTime, float SpeedFactor = 1.f) = 0;
};