#include "BasicEnemy.hpp"
#include "../../CentralStuff/Random.hpp"
#include "../../CentralStuff/TypeDefs.hpp"

#define DistanceTreshold 128.f
#define MaxDirections 4
#define AddInCaseOfNone 8.f

BasicEnemy::BasicEnemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName)
    : Enemy(Position, Size, TextureFileName)
{}

void BasicEnemy::move(float DeltaTime, float SpeedFactor)
{
    if(Distance < DistanceTreshold)
    {
        if(Direction == Directions::None)
            Distance += AddInCaseOfNone;
        else if(Direction == Directions::Up)
            EntityRect.moveRect(DeltaTime, SmartRect::Directions::Up, SpeedFactor);
        else if(Direction == Directions::Down)
            EntityRect.moveRect(DeltaTime, SmartRect::Directions::Down, SpeedFactor);
        else if(Direction == Directions::Left)
            EntityRect.moveRect(DeltaTime, SmartRect::Directions::Left, SpeedFactor);
        else if(Direction == Directions::Right)
            EntityRect.moveRect(DeltaTime, SmartRect::Directions::Right, SpeedFactor);
        Distance = DeltaTime * MovingSpeed * SpeedFactor;
    }
    else
    {
        Direction = RandomIntegral::getRandom(MaxDirections);
        Distance = 0.f;
    }
}