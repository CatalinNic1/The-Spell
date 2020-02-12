#include "BasicEnemy.hpp"
#include "../../CentralStuff/Random.hpp"
#include "../../CentralStuff/TypeDefs.hpp"

#define DistanceTreshold 128.f
#define MaxDirections 3.f

BasicEnemy::BasicEnemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName)
    : Enemy(Position, Size, TextureFileName)
{}

void BasicEnemy::Update(float DeltaTime)
{
    auto [EnemyDirection, EnemyAction] = getAction();
    moveEntity(DeltaTime, EnemyDirection);
    Distance += DeltaTime * MovingSpeed;
    EntityAnimate(EnemyAction);
}

std::pair< sf::Vector2f, Actions > BasicEnemy::getAction()
{
    if(Distance < DistanceTreshold)
    {
        if(Direction == static_cast< int >(Actions::MoveUp))
            return {SmartRect::Directions::Up, Actions::MoveUp};
        else if(Direction == static_cast< int >(Actions::MoveDown))
            return {SmartRect::Directions::Down, Actions::MoveDown};
        else if(Direction == static_cast< int >(Actions::MoveLeft))
            return {SmartRect::Directions::Left, Actions::MoveLeft};
        else if(Direction == static_cast< int >(Actions::MoveRight))
            return {SmartRect::Directions::Right, Actions::MoveRight};
        else
            return {SmartRect::Directions::Stop, Actions::None};
    }
    else
    {
        Direction = RandomIntegral::getRandom(static_cast< int >(Actions::None), MaxDirections);
        Distance = 0.f;
        return {SmartRect::Directions::Stop, Actions::None};
    }
}