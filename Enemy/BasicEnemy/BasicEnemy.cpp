#include "BasicEnemy.hpp"

#define maxDistance 128.f

BasicEnemy::BasicEnemy(sf::Vector2f Position, sf::Vector2f Size, std::string TextureFileName)
    : Enemy(Position, Size, TextureFileName)
{}

void BasicEnemy::move(float DeltaTime)
{
    
}