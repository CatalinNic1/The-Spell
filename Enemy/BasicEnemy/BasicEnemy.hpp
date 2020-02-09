#pragma once

#include "../Core/Enemy.hpp"

class BasicEnemy : public Enemy
{
private:
    //
    float Distance = 0.f;
    //
    int Direction = static_cast< int >(Actions::None);
protected:
    ///
    ///
    ///
    virtual std::pair< sf::Vector2f, Actions > getAction() override;
public:
    ///
    ///
    ///
    BasicEnemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName);
    ///
    ///
    ///
    virtual void Update(float DeltaTime) override;
};