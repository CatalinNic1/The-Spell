#pragma once

#include "../../Entity/Entity.hpp"

class Enemy : public Entity
{
private:
    /* data */
protected:
    ///
    ///
    ///
    virtual std::pair< sf::Vector2f, Actions > getAction() = 0;
public:
    ///
    ///
    ///
    Enemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    ///
    ///
    virtual void Update(float DeltaTime) = 0;
};