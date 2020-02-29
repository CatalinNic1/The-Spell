#include "BasicEnemy.hpp"
#include "../../CentralStuff/Random.hpp"
#include "../../CentralStuff/TypeDefs.hpp"

#define DistanceTreshold 128.f
#define MaxActions 3.f

BasicEnemy::BasicEnemy(const sf::Vector2f& Position, const sf::Vector2f& Size, const std::string& TextureFileName)
    : Enemy(Position, Size, TextureFileName)
{}

void BasicEnemy::Update(const float& DeltaTime)
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
        if(Action == Actions::MoveUp)
            return {SmartRect::Directions::Up, Actions::MoveUp};
        else if(Action == Actions::MoveDown)
            return {SmartRect::Directions::Down, Actions::MoveDown};
        else if(Action == Actions::MoveLeft)
            return {SmartRect::Directions::Left, Actions::MoveLeft};
        else if(Action == Actions::MoveRight)
            return {SmartRect::Directions::Right, Actions::MoveRight};
        else
            return {SmartRect::Directions::Stop, Actions::None};
    }
    else
    {
        Action = static_cast< Actions >(RandomIntegral::getRandom(MaxActions));
        Distance = 0.f;
        return {SmartRect::Directions::Stop, Actions::None};
    }
}